/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:25:39 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/25 11:15:16 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void kill_all_process(t_ele *ptr, int skip)
void kill_all_process(t_ele *ptr)
{
     int  i;

     i = 0;
     while (i < ptr->nb_philo)
     {
          kill(ptr->pids[i], SIGTERM);
          i++;
     }
}

// void *dead(void *arg)
void dead(t_ele *ptr)
{
     // ptr = (t_ele *) arg;
     int  i;
     while (1)
     {
          i = 0;
          while (i < ptr->nb_philo)
          {
               // if (ptr->pids[i] == 0)
               if (get_current_time() - ptr->philo.time_last_meal >= ptr->time_to_die)
               {
                    ptr->stop = 0;
                    died(ptr, ptr->philo.id_philo);
                    exit(0);
               }
               i++;
          }
     }
     // return (NULL);
}

void *routine(void *arg)
{
     t_ele     *ptr;
     
     ptr = (t_ele *) arg;
     // if (ptr->philo.id_philo % 2 == 0)
     //      usleep(200);
     while (ptr->philo.nb_time_must_eat > 0)
     {
          sem_wait(ptr->sem_fork);
          taken_fork(ptr, ptr->philo.id_philo);
          sem_wait(ptr->sem_fork);
          taken_fork(ptr, ptr->philo.id_philo);
          eating(ptr, ptr->philo.id_philo);
          if (ptr->philo.nb_time_must_eat == 0)
               pthread_detach(ptr->th);
          sem_post(ptr->sem_fork);
          sem_post(ptr->sem_fork);
          if (ptr->philo.nb_time_must_eat == 0)
               break ;
          // if (ptr->stop == 0)
          //      break ;
          sleeping(ptr, ptr->philo.id_philo);
          thinking(ptr, ptr->philo.id_philo);
     }
     return (NULL);
}



void philosophers(t_ele *ptr)
{
     int  i;
     int status;
     
     i = 0;
     ptr->pids[0] = fork();
     while (i < ptr->nb_philo)
     {
          if (ptr->pids[i] == 0)
          {
               ptr->philo.id_philo = i+1;
               pthread_create(&ptr->th, NULL, &routine, ptr);
               dead(ptr);
               pthread_join(ptr->th, NULL);
          }
          else
               ptr->pids[++i] = fork();
     }
     while (waitpid(-1, &status, 0))
     {
          if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
          {
               continue ;
          }
          if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
          {
               kill_all_process(ptr);
               return ;
          }
     }
}

int main(int ac, char **av)
{
     t_ele     *ptr;
     
     if(errors(av) == 0)
          return (2);
     if (ac == 5 || ac == 6)
     {
          ptr = malloc(sizeof(struct s_element));
          init_struct(ptr, av, ac);
          ptr->sem_fork = sem_open("sem_f", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, ptr->nb_philo);
          ptr->sem_string = sem_open("sem_s", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
          philosophers(ptr);
          sem_close(ptr->sem_fork);
          sem_close(ptr->sem_string);
          sem_unlink("sem_f");
          sem_unlink("sem_s");
          free(ptr);
     } 
}