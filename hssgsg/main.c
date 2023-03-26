#include <stdio.h>
#include <stdlib.h>

int marks(int *b);
int main()
{
    int a=0;
    int array[2];
    for(a=0;a<2;a++)
    {
        scanf("%d", &array[a]);
        marks(&array);
        printf("%d\n", array[a]);
    }
    return 0;
}
int marks(int *b)
{
    *b = *b + 1;

}
