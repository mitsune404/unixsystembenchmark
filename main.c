#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int int_input_validity_and_assign();

int main()
{
    time_t t1, t2;
    struct timeval timea;
    {
        /* data */
    };
    
    int score = 0, val = 0, num = 0;
    int i, j, k, x = 2, buff;

    printf("\n>>>>>>>> Select benchmark type <<<<<<<<\n\n(1) Addition\n(2) Multiplication\n(3) Logarithmic\n# Your input : ");
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
    t1 = time(NULL);
    printf(ctime(&t1));
    printf("\n hmmmm\n");
    gettimeofday(&timea, NULL);
    printf(ctime(&timea));
    srand(time(NULL));

    printf("Initializing system benchmark...\n");

    switch (num)
    {
    case 1:
        for (k = 0; k != x; k++)
        {
            t1 = time(NULL);
            while (time(NULL) < t1 + 1)
            {
                buff = rand()^rand()^rand();
                score++;
            }
            printf("Hmm");
        }
        score = score/x;
        break;
    case 2:
        while (time(NULL) != t1 + 1)
        {
            score++;
        }
        break;
    case 3:
        while (time(NULL) != t1 + 1)
        {
            score++;
        }
        break;
    default:
        break;
    }

    printf("\nBenchmark finished!\n");
    t2 = time(NULL);
    printf(ctime(&t2));
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