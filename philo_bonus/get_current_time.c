/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:35:23 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/16 10:25:18 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_current_time(void)
{
	int				time;
	struct timeval	tv;
	size_t			fulltime;

	time = gettimeofday(&tv, NULL);
	if (time == -1)
		return (0);
	fulltime = tv.tv_sec * 1000 + (tv.tv_usec / 1000);
	return (fulltime);
}
