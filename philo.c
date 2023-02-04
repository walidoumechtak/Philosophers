/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:22:47 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/04 18:26:40 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_the_philosophers(t_ele *ptr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= ptr->nb_philo)
	{
		ptr->philo[j].id_philo = i;
		if (i == 1)
			ptr->philo[j].id_right_philo = ptr->nb_philo;
		else
			ptr->philo[j].id_right_philo = i - 1;
		if (i == 5)
			ptr->philo[j].id_left_philo = 1;
		else
			ptr->philo[j].id_left_philo = i + 1;
		ptr->philo[j].element = ptr;
		ptr->philo[j].time_last_meal = 0;
		i++;
		j++;
	}
}

void    init_struct(t_ele *ptr, char **av)
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
	fill_the_philosophers(ptr);
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

void	*routine(void *arg)
{
	t_philos *philo;
	int	*r;
	int	i;

	i = 0;
	r = &i;
	philo = (t_philos *)arg;
	if (philo->id_philo % 2 == 0)
		sleep(2);
	// printf("id : %d\n", philo->id_philo);
	while (philo->element->stop == 1)
	{
		pthread_mutex_lock(&philo->element->mut[philo->id_right_philo]);
		pthread_mutex_lock(&philo->element->mut[philo->id_left_philo]);
		taken_fork(philo->element, philo->id_philo);
		taken_fork(philo->element, philo->id_philo);
		eating(philo->element, philo->id_philo);
		pthread_mutex_unlock(&philo->element->mut[philo->id_right_philo]);
		pthread_mutex_unlock(&philo->element->mut[philo->id_left_philo]);
		sleeping(philo->element, philo->id_philo);
		thinking(philo->element, philo->id_philo);
		printf(" ------------------->>> %zu\n",get_current_time() - philo->time_last_meal);
		// printf(" ----------tlm--------->>> %zu\n", philo->time_last_meal);
		// printf(" ----------gct--------->>> %zu\n", get_current_time());
		// printf(" ----------ttd--------->>> %zu\n", philo->element->time_to_die);
		if (get_current_time() - philo->time_last_meal > philo->element->time_to_die)
			{
				pthread_mutex_lock(&philo->element->mut_stop[philo->id_philo]);
				died(philo->element, philo->id_philo);
				philo->element->stop = 0;
				pthread_mutex_unlock(&philo->element->mut_stop[philo->id_philo]);
				// return ((void *)r);
			}
			
	}
	return (NULL);
}

int	creat_philo(t_ele *ptr)
{
    int j;
	int	*r;
	
    j = 0;
	init_mutex(ptr);
	while (j < ptr->nb_philo)
	{
		if (pthread_create(&ptr->th[j], NULL, &routine, &(ptr->philo[j])) != 0)
			perror("Failed to create a thread");
        j++;
	}
	j = 0;
	while (j < ptr->nb_philo)
	{
		pthread_join(ptr->th[j], (void **)&r);
		// if (*r == 0)
		// {
		// 	destroy_mutex(ptr);
		// 	return (0);
		// }
		j++;
	}
	destroy_mutex(ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_ele *ptr;

	if (ac == 5 || ac == 6)
	{
		ptr = malloc(sizeof(t_ele));
        init_struct(ptr, av);
		if (creat_philo(ptr) == 0)
		{
			printf("walid has 0 in so_long\n");
			free(ptr);
			return (2);
		}
	}
	return (0);
}