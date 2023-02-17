/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:36:25 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/16 20:07:08 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	destroy_mutex(t_ele *ptr)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&ptr->mut_print);
	pthread_mutex_destroy(&ptr->mut_stop);
	pthread_mutex_destroy(&ptr->mut_stop2);
	while (i < ptr->nb_philo)
	{
		pthread_mutex_destroy(&ptr->mut[i]);
		i++;
	}
}

void	detache_all(t_ele *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->nb_philo)
	{
		pthread_detach(ptr->th[i]);
		i++;
	}
}
