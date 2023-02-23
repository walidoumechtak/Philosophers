/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:43:10 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/23 09:47:00 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    ft_sleep(long sleep_time)
{
    long current_time;

    current_time = ms_to_micro(get_current_time());
    while (ms_to_micro(get_current_time()) - current_time < sleep_time)
    {
        usleep(200);
    }   
}