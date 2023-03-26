#include <stdio.h>
#include <stdlib.h>

// FOR NEGATIVE OR POSITIVE INTEGERS

int main()
{
    int num;
    printf("Enter your number:\n");
    scanf("%d", &num);
    switch(num > 0)
    {
    case 1:
        printf("It is a positive number.\n");
        break;
    case 0:
        switch(num < 0)
        {
          case 1:
          printf("It is a negative number.\n");
          break;
          case 0:
            printf("It is zero.");
            break;
        }
    }
    return 0;}
