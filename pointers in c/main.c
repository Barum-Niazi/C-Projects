#include <stdio.h>
#include <stdlib.h>

void arr(int *array, int size);

int main()
{
    int num[5] = {1,2,3,4,5};
    arr(&num, 5);
}

void arr(int *array, 5)
{
    int i = 0;
    for(i = 0; i >=4 ; i++)
    {
        printf("Element %d is: %d", i+1, *array );
        array++;
    }
}