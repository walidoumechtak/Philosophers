/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/16 09:08:02 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

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
	t_philos			*philo;
	int					nb_philo;
	int					*id_philo;
	long				time_to_eat;
	long				time_to_sleep;
	long				time_to_die_us;
	long				time_to_sleep_us;
	long				time_to_die;
	long				time_to_eat_us;
	int					is_all_philo_eat;
	int					stop;
	long				design_time;
	int					is_one_philo;
}						t_ele;

int						ft_atoi(const char *str);
void					thinking(t_ele *ptr, int x);
void					died(t_ele *ptr, int x);
void					sleeping(t_ele *ptr, int x);
void					eating(t_ele *ptr, int x);
void					taken_fork(t_ele *ptr, int x);
long					get_current_time(void);
long					ms_to_micro(int ms);
long						micro_to_ms(size_t micro);
int						errors(char **av);
void					init_struct(t_ele *ptr, char **av, int ac);
void					init_mutex(t_ele *ptr);
void					fill_the_philosophers(t_ele *ptr, char **av, int ac);
void					destroy_mutex(t_ele *ptr);
void					detache_all(t_ele *ptr);
// void    ft_usleep(size_t time);

#endif