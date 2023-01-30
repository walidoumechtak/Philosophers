/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:00:36 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/30 16:20:31 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    thinking(t_ele *ptr, int x)
{
    printf("%d %d is thinking\n");
}

void    died(t_ele *ptr, int x)
{
    printf("%d %d died\n");
}

void    sleeping(t_ele *ptr, int x)
{
    printf("%d %d is sleeping\n");
}

void    eating(t_ele *ptr, int x)
{
    printf("%d %d is eating\n");
}

void    taken_fork(t_ele *ptr, int x)
{
    printf("%d %d  has taken a fork\n");
}