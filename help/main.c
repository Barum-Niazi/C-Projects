#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int n;
    int array[n];
    int even = 0;
    int odd = 0;
    printf("Enter the number of elements you want to enter: (minimum 10)");
    scanf("%d", &n);
    while(n < 10)
    {
        printf("Enter number of elements again:");
        scanf("%d", &n);
    }
    for(i=0;i<=n;i++)
    {
        printf("\nEnter element %d:", i);
        scanf("%d", &array[i]);
        if(array[i]%2)
        {
            even++;
        }
        else
        odd++;
    }
    printf("The number of even elements are %d and number of odd elements are %d", even, odd);
    return 0;
}

