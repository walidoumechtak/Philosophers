/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:00:36 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/16 09:19:19 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	thinking(t_ele *ptr, int x)
{
	(void)ptr;
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zums\t| %d | is thinking\n", get_current_time() - ptr->design_time,
		x);
	pthread_mutex_unlock(&ptr->mut_print);
}

void	died(t_ele *ptr, int x)
{
	(void)ptr;
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zums\t| %d | died\n", get_current_time() - ptr->design_time, x);
	pthread_mutex_unlock(&ptr->mut_print);
}

void	sleeping(t_ele *ptr, int x)
{
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zums\t| %d | is sleeping\n", get_current_time() - ptr->design_time,
		x);
	pthread_mutex_unlock(&ptr->mut_print);
	usleep(ptr->time_to_sleep_us);
}

void	eating(t_ele *ptr, int x)
{
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zums\t| %d | is eating\n", get_current_time() - ptr->design_time,
		x);
	ptr->philo[x - 1].time_last_meal = get_current_time();
	pthread_mutex_unlock(&ptr->mut_print);
	usleep(ptr->time_to_eat_us);
	if (ptr->ac == 6)
		ptr->philo[x - 1].nb_time_must_eat--;
}

void	taken_fork(t_ele *ptr, int x)
{
	(void)ptr;
	pthread_mutex_lock(&ptr->mut_print);
	printf("%zums\t| %d | has taken a fork\n", get_current_time()
		- ptr->design_time, x);
	pthread_mutex_unlock(&ptr->mut_print);
}
