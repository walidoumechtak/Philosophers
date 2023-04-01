/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:00:36 by woumecht          #+#    #+#             */
/*   Updated: 2023/04/01 18:33:37 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	thinking(t_ele *ptr, int x)
{
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zu %d is thinking\n", get_current_time() - ptr->design_time, x);
	pthread_mutex_unlock(&ptr->mut_print);
}

void	died(t_ele *ptr, int x)
{
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zu %d died\n", get_current_time() - ptr->design_time, x);
}

void	sleeping(t_ele *ptr, int x)
{
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zu %d is sleeping\n", get_current_time() - ptr->design_time, x);
	pthread_mutex_unlock(&ptr->mut_print);
	ft_sleep(ptr->time_to_sleep_us);
}

void	eating(t_ele *ptr, int x)
{
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zu %d is eating\n", get_current_time() - ptr->design_time, x);
	pthread_mutex_unlock(&ptr->mut_print);
	pthread_mutex_lock(&ptr->mut_stop);
	ptr->philo[x - 1].time_last_meal = get_current_time();
	pthread_mutex_unlock(&ptr->mut_stop);
	ft_sleep(ptr->time_to_eat_us);
	if (ptr->ac == 6)
	{
		ptr->philo[x - 1].nb_time_must_eat--;
		if (ptr->philo[x - 1].nb_time_must_eat == 0)
			ptr->is_all_philo_eat--;
	}
}

void	taken_fork(t_ele *ptr, int x)
{
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zu %d has taken a fork\n", get_current_time() - ptr->design_time,
		x);
	pthread_mutex_unlock(&ptr->mut_print);
}
