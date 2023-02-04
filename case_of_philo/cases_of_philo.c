/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:00:36 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/04 16:11:02 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t get_current_time()
{
    int  time; 
    struct timeval tv;
    size_t  fullTime;
    
    time = gettimeofday(&tv, NULL);
    if (time == -1)
        return (0);
    fullTime = tv.tv_sec * 1000 + (tv.tv_usec / 1000);
    return (fullTime);
}

void    thinking(t_ele *ptr, int x)
{
    printf("%zu %d is thinking\n", get_current_time(), x);
    usleep(ptr->time_to_sleep_us);
}

void    died(t_ele *ptr, int x)
{
    (void)ptr;
    printf("%zu %d died\n", get_current_time(), x);
}

void    sleeping(t_ele *ptr, int x)
{
    printf("%zu %d is sleeping\n", get_current_time(), x);
    usleep(ptr->time_to_sleep_us);
}

void    eating(t_ele *ptr, int x)
{
    printf("%zu %d is eating\n", get_current_time(), x);
    ptr->philo[x-1].time_last_meal = get_current_time();
    usleep(ptr->time_to_eat_us);
}

void    taken_fork(t_ele *ptr, int x)
{
     (void)ptr;
    printf("%zu %d  has taken a fork\n", get_current_time(), x);
}