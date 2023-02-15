/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:53:56 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:25 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void    ft_usleep(size_t time)
{
    long st;

    st = get_current_time();
    while (get_current_time() - st < time)
        usleep(200);
}