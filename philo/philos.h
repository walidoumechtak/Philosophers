/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/24 09:57:17 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
#include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philos
{
	int					id_philo;
	int					id_right_philo;
	int					id_left_philo;
	long				time_last_meal;
	int					nb_time_must_eat;
	struct s_element	*element;
	int					cpt;
}						t_philos;

typedef struct s_element
{
	int					ac;
	pthread_t			*th;
	pthread_mutex_t		*mut;
	pthread_mutex_t		mut_print;
	pthread_mutex_t		mut_stop;
	pthread_mutex_t		mut_stop2;
	t_philos			*philo;
	int					nb_philo;
	int					*id_philo;
	unsigned long				time_to_eat;
	unsigned long				time_to_sleep;
	unsigned long				time_to_die_us;
	unsigned long				time_to_sleep_us;
	unsigned long				time_to_die;
	unsigned long				time_to_eat_us;
	int					is_all_philo_eat;
	int					stop;
	unsigned long				design_time;
	int					is_one_philo;
}						t_ele;

int						ft_atoi(const char *str);
void					thinking(t_ele *ptr, int x);
void					died(t_ele *ptr, int x);
void					sleeping(t_ele *ptr, int x);
void					eating(t_ele *ptr, int x);
void					taken_fork(t_ele *ptr, int x);
unsigned long					get_current_time(void);
unsigned long					ms_to_micro(int ms);
unsigned long					micro_to_ms(unsigned long micro);
int						errors(char **av);
void					init_struct(t_ele *ptr, char **av, int ac);
void					init_mutex(t_ele *ptr);
void					fill_the_philosophers(t_ele *ptr, char **av, int ac);
void					destroy_mutex(t_ele *ptr);
void					detache_all(t_ele *ptr);
void					ft_putstr(char *str);
void					ft_sleep(unsigned long time);

#endif