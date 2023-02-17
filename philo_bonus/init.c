/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:27:39 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/17 07:59:49 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philos.h"

// void	fill_the_philosophers(t_ele *ptr, char **av, int ac)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	j = 0;
// 	while (i <= ptr->nb_philo)
// 	{
// 		ptr->philo[j].id_philo = i;
// 		if (i == 1)
// 			ptr->philo[j].id_right_philo = ptr->nb_philo - 1;
// 		else
// 			ptr->philo[j].id_right_philo = j - 1;
// 		if (i == ptr->nb_philo)
// 			ptr->philo[j].id_left_philo = ptr->nb_philo - 1;
// 		else
// 			ptr->philo[j].id_left_philo = j;
// 		ptr->philo[j].element = ptr;
// 		ptr->philo[j].time_last_meal = get_current_time();
// 		if (ac == 6)
// 			ptr->philo[j].nb_time_must_eat = ft_atoi(av[5]);
// 		else
// 			ptr->philo[j].nb_time_must_eat = 100;
// 		i++;
// 		j++;
// 	}
// }

// void	init_struct(t_ele *ptr, char **av, int ac)
// {
// 	ptr->nb_philo = ft_atoi(av[1]);
// 	ptr->th = malloc(sizeof(pthread_t) * ptr->nb_philo);
// 	ptr->mut = malloc(sizeof(pthread_mutex_t) * ptr->nb_philo);
// 	ptr->philo = malloc(ptr->nb_philo * sizeof(t_philos));
// 	ptr->time_to_die = ft_atoi(av[2]);
// 	ptr->time_to_die_us = ms_to_micro(ptr->time_to_die);
// 	ptr->time_to_eat = ft_atoi(av[3]);
// 	ptr->time_to_eat_us = ms_to_micro(ptr->time_to_eat);
// 	ptr->time_to_sleep = ft_atoi(av[4]);
// 	ptr->time_to_sleep_us = ms_to_micro(ptr->time_to_sleep);
// 	ptr->stop = 1;
// 	ptr->design_time = get_current_time();
// 	ptr->is_one_philo = 0;
// 	ptr->is_all_philo_eat = 0;
// 	fill_the_philosophers(ptr, av, ac);
// }

// void	init_mutex(t_ele *ptr)
// {
// 	int	i;

// 	i = 0;
// 	pthread_mutex_init(&ptr->mut_print, NULL);
// 	while (i < ptr->nb_philo)
// 	{
// 		pthread_mutex_init(&ptr->mut[i], NULL);
// 		i++;
// 	}
// }
