/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:22:47 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/30 16:19:13 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_struct(t_ele *ptr, char **av)
{
    ptr->nb_philo = ft_atoi(av[1]);
    ptr->t = malloc(sizeof(pthread_t) * ptr->nb_philo);
}

void	*routine(void *arg)
{
	
	return (NULL);
}

void	creat_philo(t_ele *ptr)
{
	int	*i;
    int j;
	
    j = 0;
    i = NULL;
	while (j < ptr->nb_philo)
	{
        i = malloc(sizeof(int));
        *i = j;
		if (pthread_create(&ptr->t[j], NULL, &routine, i) != 0)
			perror("Failed to create a thread");
        j++;
	}
	j = 0;
	while (j < ptr->nb_philo)
	{
		pthread_join(ptr->t[j], NULL);
		j++;
	}
}

int	main(int ac, char **av)
{
	t_ele *ptr;

	if (ac == 5 || ac == 6)
	{
		ptr = malloc(sizeof(t_ele));
        init_struct(ptr, av);
		creat_philo(ptr);
	}
	return (0);
}