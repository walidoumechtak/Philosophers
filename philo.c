/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:22:47 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/12 13:43:29 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_the_philosophers(t_ele *ptr, char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= ptr->nb_philo)
	{
		ptr->philo[j].id_philo = i;
		if (i == 1)
			ptr->philo[j].id_right_philo = ptr->nb_philo - 1;
		else
			ptr->philo[j].id_right_philo = j - 1;
		if (i == ptr->nb_philo)
			ptr->philo[j].id_left_philo = ptr->nb_philo - 1;
		else
			ptr->philo[j].id_left_philo = j;
		ptr->philo[j].element = ptr;
		ptr->philo[j].time_last_meal = get_current_time();
		if (ac == 6)
			ptr->philo[j].nb_time_must_eat = ft_atoi(av[5]);
		else
			ptr->philo[j].nb_time_must_eat = 1;
		i++;
		j++;
	}
}

void	init_struct(t_ele *ptr, char **av, int ac)
{
	ptr->nb_philo = ft_atoi(av[1]);
	ptr->th = malloc(sizeof(pthread_t) * ptr->nb_philo);
	ptr->mut = malloc(sizeof(pthread_mutex_t) * ptr->nb_philo);
	ptr->mut_stop = malloc(sizeof(pthread_mutex_t) * ptr->nb_philo);
	ptr->philo = malloc(ptr->nb_philo * sizeof(t_philos));
	ptr->time_to_die = ft_atoi(av[2]);
	ptr->time_to_die_us = ms_to_micro(ptr->time_to_die);
	ptr->time_to_eat = ft_atoi(av[3]);
	ptr->time_to_eat_us = ms_to_micro(ptr->time_to_eat);
	ptr->time_to_sleep = ft_atoi(av[4]);
	ptr->time_to_sleep_us = ms_to_micro(ptr->time_to_sleep);
	ptr->stop = 1;
	ptr->design_time = get_current_time();
	ptr->is_one_philo = 0;
	ptr->is_all_philo_eat = 0;
	fill_the_philosophers(ptr, av, ac);
}

void	init_mutex(t_ele *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->nb_philo)
	{
		pthread_mutex_init(&ptr->mut[i], NULL);
		pthread_mutex_init(&ptr->mut_stop[i], NULL);
		i++;
	}
}

void	destroy_mutex(t_ele *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->nb_philo)
	{
		pthread_mutex_destroy(&ptr->mut[i]);
		pthread_mutex_destroy(&ptr->mut_stop[i]);
		i++;
	}
}

void	detache_all(t_ele *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->nb_philo)
	{
		pthread_detach(ptr->th[i]);
		i++;
	}
}

void	is_dead(t_ele *ptr)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	j = 0;
	while (1)
	{
		i = 0;
		while (i < ptr->nb_philo)
		{
			if (get_current_time()
				- ptr->philo[i].time_last_meal > ptr->time_to_die)
			{
				ptr->stop = 0;
				died(ptr, ptr->philo[i].id_philo);
				break ;
			}
			if (ptr->philo[j].nb_time_must_eat == 0)
				j++;
			if (j == ptr->nb_philo - 1)
			{
				ptr->is_all_philo_eat = 1;
				break;
			}
			i++;
		}
		if (ptr->stop == 0 || ptr->is_all_philo_eat == 1)
			break ;
	}
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id_philo % 2 == 0)
		usleep(100);
	while (philo->element->stop == 1 && philo->nb_time_must_eat > 0)
	{
		pthread_mutex_lock(&philo->element->mut[philo->id_left_philo]);
		taken_fork(philo->element, philo->id_philo);
		if (philo->element->nb_philo == 1)
		{
			usleep(philo->element->time_to_die_us);
			pthread_detach(philo->element->th[0]);
		}
		pthread_mutex_lock(&philo->element->mut[philo->id_right_philo]);
		taken_fork(philo->element, philo->id_philo);
		eating(philo->element, philo->id_philo);
		pthread_mutex_unlock(&philo->element->mut[philo->id_left_philo]);
		pthread_mutex_unlock(&philo->element->mut[philo->id_right_philo]);
		if (philo->nb_time_must_eat == 0)
			break ;
		sleeping(philo->element, philo->id_philo);
		thinking(philo->element, philo->id_philo);
	}
	return (NULL);
}

int	creat_philo(t_ele *ptr)
{
	int	j;

	j = 0;
	init_mutex(ptr);
	while (j < ptr->nb_philo)
	{
		if (pthread_create(&ptr->th[j], NULL, &routine, &(ptr->philo[j])) != 0)
			perror("Failed to create a thread");
		j++;
	}
	is_dead(ptr);
	if (ptr->stop == 0)
		detache_all(ptr);
	j = 0;
	while (j < ptr->nb_philo && ptr->stop == 1)
	{
		pthread_join(ptr->th[j], NULL);
		j++;
	}
	destroy_mutex(ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_ele	*ptr;

	if (ac == 5 || ac == 6)
	{
		if (errors(av) == 0)
			return (1);
		ptr = malloc(sizeof(t_ele));
		ptr->ac = ac;
		init_struct(ptr, av, ac);
		if (ptr->philo->nb_time_must_eat == 0)
		{
			perror("Error the number of meals must be greather than 0");
		}
		if (creat_philo(ptr) == 0)
		{
			free(ptr);
			return (2);
		}
	}
	else
		printf("Number of arguments are incorrect !\n");
	return (0);
}
