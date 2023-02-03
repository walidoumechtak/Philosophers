/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:00:36 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/02 16:17:31 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t get_current_time()
{
    int  time; 
    struct timeval tv;
    
    time = gettimeofday(&tv, NULL);
    if (time == -1)
        return (0);
    return (tv.tv_usec);
}

void    thinking(t_ele *ptr)
{
    printf("%zu %d is thinking\n", get_current_time(), ptr->philo->id_philo);
    usleep(ptr->time_to_sleep_us);
}

void    died(t_ele *ptr)
{
    printf("%zu %d died\n", get_current_time(), ptr->philo->id_philo);
}

void    sleeping(t_ele *ptr)
{
    printf("%zu %d is sleeping\n", get_current_time(), ptr->philo->id_philo);
    usleep(ptr->time_to_sleep_us);
}

void    eating(t_ele *ptr)
{
    printf("%zu %d is eating\n", get_current_time(), ptr->philo->id_philo);
    usleep(ptr->time_to_eat_us);
}

void    taken_fork(t_ele *ptr)
{
    printf("%zu %d  has taken a fork\n", get_current_time(), ptr->philo->id_philo);
}