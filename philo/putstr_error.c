/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:44:36 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/18 08:47:31 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void    ft_putchar(char c)
{
    write(2, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}