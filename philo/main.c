/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:22:47 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/16 20:38:01 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	is_dead(t_ele *ptr, int i)
{
	if (get_current_time() - ptr->philo[i].time_last_meal > ptr->time_to_die)
	{
		return (1);
	}
	return (0);
}

void	dead(t_ele *ptr)
{
	int	i;
	int	j;

	j = 0;
	while (1)
	{
		i = 0;
		while (i < ptr->nb_philo)
		{
			if (is_dead(ptr, i) == 1)
			{
				died(ptr, i + 1);
				ptr->stop = 0;
				detache_all(ptr);
				break ;
			}
			if (ptr->philo[j].nb_time_must_eat == 0 && ptr->ac == 6)
				j++;
			if (j == ptr->nb_philo - 1 && ptr->ac == 6)
			{
				ptr->is_all_philo_eat = 1;
				break ;
			}
			i++;
		}
		if (ptr->stop == 0)
			break ;
	}
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id_philo % 2 == 0)
		usleep(200);
	while (philo->element->stop)
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
	dead(ptr);
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
			perror("Error the number of meals must be greather than 0");
		if (creat_philo(ptr) == 0)
		{
			free(ptr);
			return (free(ptr), free(ptr->th), free(ptr->mut), free(ptr->philo),
				2);
		}
	}
	else
		printf("Number of arguments are incorrect !\n");
	return (0);
}
