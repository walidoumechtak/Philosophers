/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:25:39 by woumecht          #+#    #+#             */
/*   Updated: 2023/02/13 15:16:34 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int cpt = 0;

void    *routine(void *arg)
{
    sem_t *s;

    s = (sem_t *) arg;
    if (sem_wait(s) == -1)
    {
        perror("sem_wait");
    }
    // printf("\n\n HEHE");
    cpt++;
    if(sem_post(s) == -1)
        perror("sem_post");
    return (NULL);
}

int main(void)
{
    int i;

    i = 0;
    sem_t *ptr = sem_open("test", O_CREAT, 0777, 100);
  
    pthread_t th[100000];

    while (i < 100000)
    {
        pthread_create(&th[i], NULL, &routine, ptr);
        i++;
        printf("-- %d --\n", i);
    }
     
    i=0;
    while (i < 100000)
    {
        pthread_join(th[i], NULL);
        i++;
    }
    
    sem_close(ptr);
    sem_unlink("test");

    printf("cpt : %d\n", cpt);
    return 0;
}