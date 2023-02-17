/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:25:39 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/17 07:56:42 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void init_struct(t_ele *ptr, char **av, int ac)
{
     ptr->ac = ac;
     ptr->nb_philo = ft_atoi(av[1]);
     // ptr->th = malloc(sizeof(pthread_t) * ptr->nb_philo);
	// ptr->philo = malloc(ptr->nb_philo * sizeof(t_philos));
     ptr->pids = malloc(ptr->nb_philo * sizeof(int));
	ptr->time_to_die = ft_atoi(av[2]);
	ptr->time_to_die_us = ms_to_micro(ptr->time_to_die);
	ptr->time_to_eat = ft_atoi(av[3]);
	ptr->time_to_eat_us = ms_to_micro(ptr->time_to_eat);
	ptr->time_to_sleep = ft_atoi(av[4]);
	ptr->time_to_sleep_us = ms_to_micro(ptr->time_to_sleep);
	ptr->stop = 1;
     // ptr->philo->time_last_meal = get_current_time();
	ptr->design_time = get_current_time();
	ptr->is_all_philo_eat = 0;
}

void routine(t_ele *ptr)
{
     if (ptr->id_philo % 2 == 0)
          usleep(100);
     while (ptr->stop == 1)
     {
          sem_wait(ptr->sem_fork);
          taken_fork(ptr, ptr->id_philo);
          sem_wait(ptr->sem_fork);
          taken_fork(ptr, ptr->id_philo);
          eating(ptr, ptr->id_philo);
          sem_post(ptr->sem_fork);
          sem_post(ptr->sem_fork);
          sleeping(ptr, ptr->id_philo);
          thinking(ptr, ptr->id_philo);
     }     
}

void philosophers(t_ele *ptr)
{
     int  i;
     
     i = 0;
     ptr->pids[0] = fork();
     while (i < ptr->nb_philo)
     {
          if (ptr->pids[i] == 0)
          {    
               printf("go\n");
               ptr->id_philo = i+1;
               routine(ptr);
          }
          ptr->pids[++i] = fork();
     }
     
}

int main(int ac, char **av)
{
     t_ele     *ptr;
     
     if(errors(av) == 0)
          return (2);
     ptr = malloc(sizeof(struct s_element));
     if (ac == 5 || ac == 6)
     {
          init_struct(ptr, av, ac);
          ptr->sem_fork = sem_open("sem_f", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, ptr->nb_philo);
          ptr->sem_string = sem_open("sem_s", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
          philosophers(ptr);
          sem_unlink("sem_f");
          sem_unlink("sem_s");
     } 
}