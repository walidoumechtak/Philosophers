/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:35:23 by woumecht          #+#    #+#             */
/*   Updated: 2023/04/01 18:32:55 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

unsigned long	get_current_time(void)
{
	int				time;
	struct timeval	tv;
	unsigned long	fulltime;

	time = gettimeofday(&tv, NULL);
	if (time == -1)
		return (0);
	fulltime = tv.tv_sec * 1000 + (tv.tv_usec / 1000);
	return (fulltime);
}
