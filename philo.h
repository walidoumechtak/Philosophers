/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/01 15:42:46 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define LENGHT 250

typedef struct s_philos
{
	// t_ele			elem;
}					t_philos;

typedef struct s_element
{
	pthread_t		*th;
	pthread_mutex_t	*mut;
	t_philos		philo;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_must_eat;

}					t_ele;

int					ft_atoi(const char *str);
char				**ft_split(char const *s, char c);

void				thinking(t_ele *ptr, int x);
void				died(t_ele *ptr, int x);
void				sleeping(t_ele *ptr, int x);
void				eating(t_ele *ptr, int x);
void				taken_fork(t_ele *ptr, int x);
size_t				get_current_time(void);

#endif