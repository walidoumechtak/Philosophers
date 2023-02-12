/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/12 10:36:03 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philos
{
	int					id_philo;
	int					id_right_philo;
	int					id_left_philo;
	size_t				time_last_meal;
	int					nb_time_must_eat;
	struct s_element	*element;

}						t_philos;

typedef struct s_element
{
	int					ac;
	pthread_t			*th;
	pthread_mutex_t		*mut;
	pthread_mutex_t		*mut_stop;
	t_philos			*philo;
	int					nb_philo;
	int					*id_philo;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				time_to_die_us;
	size_t				time_to_sleep_us;
	size_t				time_to_die;
	size_t				time_to_eat_us;

	int					stop;
	size_t				design_time;
	int					is_one_philo;
}						t_ele;

int						ft_atoi(const char *str);
char					**ft_split(char const *s, char c);

void					thinking(t_ele *ptr, int x);
void					died(t_ele *ptr, int x);
void					sleeping(t_ele *ptr, int x);
void					eating(t_ele *ptr, int x);
void					taken_fork(t_ele *ptr, int x);
size_t					get_current_time(void);
size_t					ms_to_micro(int ms);
int						micro_to_ms(size_t micro);

#endif