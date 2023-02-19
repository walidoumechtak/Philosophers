/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:30:35 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/19 08:54:37 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philos
{
	int					id_philo;
	long				time_last_meal;
	int					nb_time_must_eat;
	struct s_element	*element;

}						t_philos;

typedef struct s_element
{
	pthread_t			th;
	int					ac;
	sem_t				*sem_fork;
	sem_t				*sem_string;
	t_philos			philo;
	int					nb_philo;
	long				time_to_eat;
	long				time_to_sleep;
	long				time_to_die_us;
	long				time_to_sleep_us;
	long				time_to_die;
	long				time_to_eat_us;
	int					is_all_philo_eat;
	int					stop;
	long				design_time;
	int					*pids;
}						t_ele;

int						ft_atoi(const char *str);
void					thinking(t_ele *ptr, int x);
void					died(t_ele *ptr, int x);
void					sleeping(t_ele *ptr, int x);
void					eating(t_ele *ptr, int x);
void					taken_fork(t_ele *ptr, int x);
long					get_current_time(void);
long					ms_to_micro(int ms);
long					micro_to_ms(size_t micro);
int						errors(char **av);
void					init_struct(t_ele *ptr, char **av, int ac);

#endif