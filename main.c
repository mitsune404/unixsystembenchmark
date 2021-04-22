#include <stdio.h>

int main()
{
  int n, i = 3, count, c;

  printf("Enter the number of prime numbers required :  ");
  scanf("%d", &n);
  printf("\n");
  printf(system("date +%T"));

  if (n >= 1)
  {
    printf("\n%dth prime number is :  ", n);
    if (n == 1)
    {
      printf("2 ");
    }
  }

  // iteration for n prime numbers
  // i is the number to be checked in each iteration starting from 3
  for (count = 2; count <= n; i++)
  {
    // iteration to check c is prime or not
    for (c = 2; c < i; c++)
    {
      if (i % c == 0)
        break;
    }

    if (c == i) // c is prime
    {
      //printf("%d ", i);
      //printf("%d ", c);
      count++; // increment the count of prime numbers
    }
  }
  printf("\n%d\n", i);

  printf(system("date +%T"));
  return 0;
}