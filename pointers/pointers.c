#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[];
    printf("Enter the name of your organization");
    fgets(name,sizeof(name),stdin);
    puts(name);
}
