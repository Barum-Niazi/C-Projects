#include <stdlib.h>

int main()
{
    int a, b;
    printf("Enter ur first number: ");
    scanf("%d", &a);

    printf("Enter ur second number: ");
    scanf("%d", &b);

    int choice;
    printf("Enter 1 to add, 2 to subtract");
    scanf("%d", &choice);
    if (choice == 1)
        addNum(a, b);
    if (choice == 2)
        subNum(a, b);
    if (choice > 2 || choice < 1)
    {
        printf("Invalid choice, restarting program");
        main();
    }
}

int addNum(int a, int b)
{
    int c = a + b;
    return c;
}

int subNum(int a, int b)
{
    int c = a - b;
    return c;
}