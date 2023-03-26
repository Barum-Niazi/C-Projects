#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a;
    int n = 3;
    int b;
    for (a = 0; a < n; a++)
    {
        for (b = a; b < n; b++)
        {
            if (b < n)
                printf(" ");
        }
    }
    return 0;
}