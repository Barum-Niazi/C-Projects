#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int j = 0;
    int temp;
    int array[10];
    printf("Enter 10 elements\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10-i; j++)
        {
            if(array[j] > array[j+1])
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
    for(i = 0; i < 10; i++);
    {
        printf("%d\n", array[i]);
    }
    FILE * fp;
    fp = fopen("sort.txt", "w");
    for(i = 0; i < 10; i++)
    {
        fprintf(fp, "%d\n", array[i]);
    }
    fclose(fp);
}