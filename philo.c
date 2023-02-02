/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:22:47 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/02 13:39:22 by woumecht         ###   ########.fr       */
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
			ptr->philo[j].id_left_philo = ptr->nb_philo;
		else
			ptr->philo[j].id_left_philo = i - 1;
			
		ptr->philo[j].id_right_philo = i + 1;
		i++;
	}
}

void    init_struct(t_ele *ptr, char **av)
{
    ptr->nb_philo = ft_atoi(av[1]);
    ptr->th = malloc(sizeof(pthread_t) * ptr->nb_philo);
    ptr->mut = malloc(sizeof(pthread_mutex_t) * ptr->nb_philo);
	ptr->philo = malloc(ptr->nb_philo * sizeof(t_philos));
	ptr->time_to_die = ft_atoi(av[2]);
	ptr->time_to_eat = ft_atoi(av[3]);
	ptr->time_to_sleep = ft_atoi(av[4]);
	fill_the_philosophers(ptr);
}

void	init_mutex(t_ele *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->nb_philo)
	{
		pthread_mutex_init(&ptr->mut[i], NULL);
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
		i++;
	}
}

void	*routine(void *arg)
{
	t_ele *ptr;
	
	ptr = (t_ele *)arg;
	while (1)
	{
		pthread_mutex_lock(&ptr->mut[ptr->philo->id_right_philo]);
		pthread_mutex_lock(&ptr->mut[ptr->philo->id_left_philo]);
		taken_fork(ptr);
		taken_fork(ptr);
		eating(ptr);
		pthread_mutex_unlock(&ptr->mut[ptr->philo->id_right_philo]);
		pthread_mutex_unlock(&ptr->mut[ptr->philo->id_left_philo]);
	}
	return (NULL);
}

void	creat_philo(t_ele *ptr)
{
	// int	*i;
    int j;
	
    j = 0;
    // i = NULL;
	init_mutex(ptr);
	while (j < ptr->nb_philo)
	{
        // i = malloc(sizeof(int));
        ptr->id_philo = malloc(sizeof(int));
        *ptr->id_philo = j;
		if (pthread_create(&ptr->th[j], NULL, &routine, (void*) ptr) != 0)
			perror("Failed to create a thread");
        j++;
	}
	j = 0;
	while (j < ptr->nb_philo)
	{
		pthread_join(ptr->th[j], NULL);
		j++;
	}
	destroy_mutex(ptr);
}

int	main(int ac, char **av)
{
	t_ele *ptr;

	if (ac == 5 || ac == 6)
	{
		ptr = malloc(sizeof(t_ele));
        init_struct(ptr, av);
		creat_philo(ptr);
	}
	return (0);
}