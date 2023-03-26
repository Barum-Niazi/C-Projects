#include <stdio.h>
#include <stdlib.h>

void concatenate(char [], char []);

int main()
{
    char string1[50];
    char string2[50];
    int a;
    printf("Enter string 1: ");
    gets(string1);
    printf("Enter string 2: ");
    gets(string2);
    concatenate(string1, string2);
    printf("Concatenated string is %s", string1);

    return 0;
}

void concatenate(char p[], char q[])
{
    int i, length = 0;
    while(p[length] != '\0')
    {
        length++;
    }
    for(i = 0; q[i] != '\0'; i++, length++)
    {
        p[length] = q[i];
    }
    p[length] = '\0';
}
