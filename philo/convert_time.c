/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:48:23 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/16 09:07:55 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

long	ms_to_micro(int ms)
{
	return (ms * 1000);
}

long	micro_to_ms(size_t micro)
{
	return (micro / 1000);
}
