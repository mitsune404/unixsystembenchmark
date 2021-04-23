#include <stdio.h>
#include <time.h>
#include <ctype.h>

int int_input_validity_and_assign();

void main()
{
  time_t t1, t2;
  int score = 0, wait = 1, val = 0, num = 0, buff = 0;
  char *t;

  printf(">>>>>>>> Select benchmark duration <<<<<<<<\n\n(1) Small\n(2) Medium\n(3) Large\n# Your input : ");
  do
  {
    val = int_input_validity_and_assign(&num);

    if ((num > 3 || num < 1) && val == 1)
    {
      val = 0;
      printf("Invalid input... Enter value again : ");
    }
  } while (val != 1);

  switch (wait)
  {
  case 1:
    wait = 1;
    break;
  case 2:
    wait = 2;
    break;
  case 3:
    wait = 3;
    break;
  default:
    break;
  }

  printf("\n");
  t1 = time(NULL);
  printf(ctime(&t1));

  printf("Initializing system benchmark...\n");

  // the prime algo here

  while (time(NULL) < t1 + wait)
  {
    buff = 69^69;
    score++;
  }

  //

  printf("\nBenchmark finished!\n");
  t2 = time(NULL);
  printf(ctime(&t2));
  printf("\nScore : %d", score);
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