/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/30 16:21:09 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define LENGHT 250

typedef struct s_ele
{
	pthread_t	*t;
	int			nb_philo;
	int			nb_time_must_eat;
}				t_ele;

int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);

void			thinking(t_ele *ptr, int x);
void			died(t_ele *ptr, int x);
void			sleeping(t_ele *ptr, int x);
void			eating(t_ele *ptr, int x);
void			taken_fork(t_ele *ptr, int x);

#endif