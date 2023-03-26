#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if(n == 1)
    return 0;
    else if(n == 2)
    return 1;
    else
    return ( fibonacci(n-1) + fibonacci (n-2));
}
int main()
{
    int n;
    int i;
    int c;
    printf("Enter the value of n:");
    scanf("%d", &n);
    c = fibonacci(n);
    printf("The nth term is as follows: %d\n", c);
    printf("FIBONACCI SERIES:\n");
    for(i=1; i<=n; i++ )
    printf("%d\n", fibonacci(i));
    return 0;

}