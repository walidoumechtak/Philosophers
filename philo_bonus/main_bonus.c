/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:25:39 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/14 10:02:31 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


int main(void)
{
   pid_t pid;
    sem_t *sem1;
    sem1 = sem_open("sem11", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
    sem_t *sem2;
    sem2 = sem_open("sem22", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
   pid = fork();

   if (pid == 0)
   {
        printf("1\n");
        sem_post(sem1);
        sem_wait(sem2);
        printf("3\n");
        sem_post(sem1);

        sem_close(sem1);
        sem_close(sem2);
   }
   else
   {
        sem_wait(sem1);
        printf("2\n");
        sem_post(sem2);
        sem_wait(sem1);
        printf("4\n");

        wait(NULL);

        sem_close(sem1);
        sem_close(sem2);
   }
}