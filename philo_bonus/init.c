/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:27:39 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/18 16:53:48 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void init_struct(t_ele *ptr, char **av, int ac)
{
    ptr->ac = ac;
    ptr->nb_philo = ft_atoi(av[1]);
    ptr->pids = malloc(ptr->nb_philo * sizeof(int));
	ptr->time_to_die = ft_atoi(av[2]);
	ptr->time_to_die_us = ms_to_micro(ptr->time_to_die);
	ptr->time_to_eat = ft_atoi(av[3]);
	ptr->time_to_eat_us = ms_to_micro(ptr->time_to_eat);
	ptr->time_to_sleep = ft_atoi(av[4]);
	ptr->time_to_sleep_us = ms_to_micro(ptr->time_to_sleep);
	ptr->stop = 1;
    ptr->philo.time_last_meal = get_current_time();
	if (ac == 6)
		ptr->philo.nb_time_must_eat = ft_atoi(av[5]);
	else
		ptr->philo.nb_time_must_eat = 100;
	ptr->design_time = get_current_time();
	ptr->is_all_philo_eat = 0;
}