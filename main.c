#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int int_input_validity_and_assign();
double time_cast();
int load();

int main()
{
    int score = 0, val = 0, num = 0;

    printf("\n>>>>>>>> Select benchmark accuracy <<<<<<<<\n\n(1) Low\n(2) Medium\n(3) High\n# Your input : ");
    do
    {
        val = int_input_validity_and_assign(&num);

        if ((num > 3 || num < 1) && val == 1)
        {
            val = 0;
            printf("Invalid input... Enter value again : ");
        }
    } while (val != 1);

    printf("\n");
    system("date +%T");


    printf("Initializing system benchmark...\n");

    switch (num)
    {
        case 1:
            score = load(250);
            break;
        case 2:
            score = load(500);
            break;
        case 3:
            score = load(1000);
            break;
        default:
            break;
    }

    printf("\nBenchmark finished!\n");
    system("date +%T");
    printf("\nScore : %d\n", score);
    
    return 0;
}


int int_input_validity_and_assign(int *input)
{

    char string[256];
    char *ptr;
    int number;

    fgets(string, sizeof(string), stdin);

    /* strtol function returns integers from character arrays and assigns the first non integer character to the pointer character passed to it as the second input
  
    there is also strtod which is the same but for float values */

    number = strtol(string, &ptr, 10);

    if (string[0] == '\n')
    {
        *ptr = '\0';
    }

    /* if the string doesnt contain any non number characters *ptr will be new line character, so */
    if (*ptr == '\n')
    {
        *input = number;
        return 1;
    }
    else
    {
        printf("Invalid input... Enter value again : ");
        return 0;
    }
}


double time_cast(struct timeval sec)
{
    double time = sec.tv_sec + sec.tv_usec/1000000.0;
    return time;
}


int load (int acc)
{   
    int i = 0, score_ = 0;
    long buff = 0;
    double double_buff = 0;
    struct timeval t1, t2;

    for (i = 0; i < acc; i++)
    {
        srand(time(NULL));
        gettimeofday(&t1, NULL);

        do
        {
            buff = buff + rand();               // addition

            buff = buff - rand();                 // substration

            buff = buff * rand();               // multiplication

            buff = buff / rand();                // division
            
            double_buff = log(rand() / 1.0);     // special funcs
            double_buff = sin(buff / 1.0);       // special funcs

            score_++;
            gettimeofday(&t2, NULL);
        } while (time_cast(t2) < time_cast(t1) + 0.01);
    }
    score_ = score_ / (acc * 100);
    return score_;
}
