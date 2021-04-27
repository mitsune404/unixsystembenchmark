#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main(void)
{
    struct timeval rest, best;
    time_t t;
    int test, i;


    printf("\n----------\n");

    t = time(NULL);
    printf(ctime(&t));

    for (i = 0; i != 10; i++)
    {
        gettimeofday(&rest, NULL);

        do
        {
            test = 100^100;
            gettimeofday(&best, NULL);
        } while (best.tv_usec < rest.tv_usec + 250000);
        
        test++;

    }

    t = time(NULL);
    printf(ctime(&t));

}