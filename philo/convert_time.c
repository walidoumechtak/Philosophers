/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:48:23 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/19 15:14:36 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

unsigned long	ms_to_micro(int ms)
{
	return (ms * 1000);
}

unsigned long	micro_to_ms(unsigned long micro)
{
	return (micro / 1000);
}
