#include "philo.h"

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("sec : %zu \n", tv.tv_sec);
    printf("usec : %d \n", tv.tv_usec);
}