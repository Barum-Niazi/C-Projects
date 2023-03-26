#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int dayCount;
    int month;
    do{
    printf("Enter the month number: (-1 to exit)\n");
    printf("1 for January\n");
    printf("2 for February\n");
    printf("3 for March\n");
    printf("4 for April\n");
    printf("5 for May\n");
    printf("6 for June\n");
    printf("7 for July\n");
    printf("8 for August\n");
    printf("9 for September\n");
    printf("10 for October\n");
    printf("11 for November\n");
    printf("12 for December\n");
    scanf("%d", &month);
    switch(month)
    {
    case 1 :
    case 3 :
    case 5 :
    case 7 :
    case 8 :
    case 10 :
    case 12 :
       printf("Your month has 31 days.\n");
       break;
    case 4 :
    case 6 :
    case 9 :
    case 11 :
        printf("Your month has 30 days.\n");
        break;
    case 2 :
        printf("Your month has 28 days (29 if leap year)\n");
        break;
       }
    }
    while(month != -1);
    return 0;
}
