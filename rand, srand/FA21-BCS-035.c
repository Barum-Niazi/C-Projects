#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int num6;
    srand(time(NULL));
    num1 = 1 + rand()%2;
    printf("Integer 1 (1-2) is %d ", num1);
    num2 = 1+rand()%100;
    printf("\n2nd integer (1-100) is %d", num2);
    num3 = rand()%10;
    printf("\n3rd integer (0-9) is %d", num3);
    num4 = 1000 + rand()%113;
    printf("\n4th integer (1000-1112) is %d", num4);
    num5 = -1 + rand()%3;
    printf("\n5th integer (-1 to 1) is %d", num5);
    num6 = -3 + rand()%15;
    printf("\n6th integer (-3 to 11) is %d", num6);
    return 0;
}