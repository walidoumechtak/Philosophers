/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:05:02 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/12 15:24:20 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

/*

    100 ==> oen of the arguments isn't a valid number
    110 ==> need at least one philosopher to start it means you write (Exe : -5)

*/

int check_argument_format(char **av)
{
    int i;
    int j;
    
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[1][0] == '-' || av[1][0] == '0')
                return (110);
            else if (av[i][0] == '+')
                j++;
            else if (av[i][0] == '-')
                return (120);
            if (av[i][j] < '0' || av[i][j] > '9')
                return (100);
            j++;
        }
        i++;
    }
    return (1);
}

int errors(char **av)
{
    if (check_argument_format(av) == 100)
        return (printf("One of the arguments isn't a valid number.\n"), 0);
    else if (check_argument_format(av) == 110)
        return (printf("Need at least one philosopher to start.\n"), 0);
    else if (check_argument_format(av) == 120)
        return (printf("The time must be greather than 60ms.\n"), 0);
    return (1);
}