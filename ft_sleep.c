/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:58:50 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/19 16:35:37 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void    ft_sleep(unsigned long time)
{
    unsigned long start_time;

    start_time = ms_to_micro(get_current_time());
    while (ms_to_micro(get_current_time()) - start_time < time)
        usleep(250);
}