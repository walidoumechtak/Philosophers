/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:05:02 by woumecht          #+#    #+#             */
/*   Updated: 2023/04/01 15:34:54 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

/*

    100 ==> oen of the arguments isn't a valid number
    110 ==> need at least one philosopher to start it means you write (Exe : -5)

*/

int	is_valid_arg(char *str)
{
	int	i;

	i = 0;
	printf("okokok\n");
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue ;
		}
		if (str[i] < '0' || str[i] > '9')
			return (100);
		i++;
	}
	return (0);
}

int	check_argument_format(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (100);
		if (is_valid_arg(av[i]) != 0)
			return (100);
		else if (av[1][0] == '0')
			return (100);
		else if (av[i][0] == '-' || (i < 4 && av[i + 1] != NULL
				&& ft_atoi(av[i + 1]) < 60))
			return (100);
		i++;
	}
	return (1);
}

int	errors(char **av)
{
	if (check_argument_format(av) == 100)
		return (ft_putstr("One of the arguments isn't valid\n"), 0);
	return (1);
}
