#include <stdio.h>
#include <time.h>
#include <sys/time.h>



void main()
{
    struct timeval tv;
    time_t t;
    gettimeofday(&tv, NULL);
    //tv.tv_sec;      // seconds
    //tv.tv_usec; // microseconds

    t = time(NULL);
    printf("%d time\n", t);
    printf("%d mili seconds\n", tv.tv_usec);
    printf("%d sec\n", tv.tv_sec);

    printf("__________________\n");




}