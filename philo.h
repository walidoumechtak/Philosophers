/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/03 11:48:12 by woumecht         ###   ########.fr       */
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
	int				id_philo;
	int				id_right_philo;
	int				id_left_philo;
	struct s_philos	*element;
	
}					t_philos;

typedef struct s_element
{
	pthread_t		*th;
	pthread_mutex_t	*mut;
	t_philos		*philo;
	int				nb_philo;
	int				time_to_die;
	size_t			time_to_die_us;
	int				time_to_eat;
	size_t			time_to_eat_us;
	int				time_to_sleep;
	size_t			time_to_sleep_us;
	int				nb_time_must_eat;
	int				*id_philo;

}					t_ele;

int					ft_atoi(const char *str);
char				**ft_split(char const *s, char c);

void				thinking(t_ele *ptr);
void				died(t_ele *ptr);
void				sleeping(t_ele *ptr);
void				eating(t_ele *ptr);
void				taken_fork(t_ele *ptr);
size_t				get_current_time(void);
size_t				ms_to_micro(int ms);
int					micro_to_ms(size_t micro);

#endif