/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:00:36 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/20 15:47:38 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thinking(t_ele *ptr, int x)
{
	sem_wait(ptr->sem_string);
	printf("%zums\t| %d | is thinking\n", get_current_time() - ptr->design_time,
		x);
	sem_post(ptr->sem_string);
}

void	died(t_ele *ptr, int x)
{
	sem_wait(ptr->sem_string);
	printf("%zums\t| %d | died\n", get_current_time() - ptr->design_time, x);
	sem_post(ptr->sem_string);
}

void	sleeping(t_ele *ptr, int x)
{
	sem_wait(ptr->sem_string);
	printf("%zums\t| %d | is sleeping\n", get_current_time() - ptr->design_time,
		x);
	sem_post(ptr->sem_string);
	ft_sleep(ptr->time_to_sleep_us);
	// usleep(ptr->time_to_sleep_us);
}

void	eating(t_ele *ptr, int x)
{
	sem_wait(ptr->sem_string);
	printf("%zums\t| %d | is eating\n", get_current_time() - ptr->design_time,
		x);
	sem_post(ptr->sem_string);
	ptr->philo.time_last_meal = get_current_time();
	ft_sleep(ptr->time_to_eat_us);
	// usleep(ptr->time_to_eat_us);
	if (ptr->ac == 6)
		ptr->philo.nb_time_must_eat--;
}

void	taken_fork(t_ele *ptr, int x)
{
	sem_wait(ptr->sem_string);
	printf("%zums\t| %d | has taken a fork\n", get_current_time()
		- ptr->design_time, x);
	sem_post(ptr->sem_string);
}
