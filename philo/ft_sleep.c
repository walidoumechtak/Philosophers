/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:58:50 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/18 15:14:58 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void    ft_sleep(long time)
{
    long start_time;

    start_time = get_current_time();
    while (get_current_time() - start_time <= time)
        usleep(50);
}