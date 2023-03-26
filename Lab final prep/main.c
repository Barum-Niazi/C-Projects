#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    char id[10];
    int age;
    char fName[20];
    char lName[20];
    char salary[20];
    char gender[10];
} emp[5];
int a = 0; // global variable for counting number of emp entered

void addEmployee();
void dispAll();
void displayEmployee();
void dispOld();

int main()
{
    int choice;
    printf("\t\tMAIN MENU");
    printf("\nEnter your choice: ");
    printf("\n1- Add Employee info");
    printf("\n2- Display employee info");
    printf("\n3- Display all employees");
    printf("\n4- Display older employees");
    scanf("\n%d", &choice);
    if(choice == 1)
        addEmployee();
    if(choice == 2)
        displayEmployee();
    if(choice == 3)
        dispAll();
    if(choice == 4);
        dispOld();
}

void addEmployee()
{
    int x;
    int i = 0;
        if(a == 5)
        {
            printf("\nYou cannot enter any more employees!");
            main();
        }
        printf("\nEnter employee ID: ");
        fflush(stdin);
        gets(emp[a].id);
        printf("\nEnter employee first name: ");
        gets(emp[a].fName);
        printf("\nEnter employee last name: ");
        gets(emp[a].lName);
        printf("\nEnter employee age: ");
        scanf("%d", &emp[a].age);
        printf("\nEnter employee salary: ");
        fflush(stdin);
        gets(emp[a].salary);
        printf("\nEnter employee gender: ");
        gets(emp[a].gender);
        printf("Enter 1 to continue adding info, any other to go back to main menu");
        scanf("%d", &x);
        a++;
        if(x == 1)
            addEmployee();
        else
            main();

} // end of function

void dispAll()
{
    int i = 0;
    printf("\nALL EMPLOYEE DETAILS ARE: ");
    for(i = 0; i < a; i++)
    {
        printf("\nEmployee details are:");
        printf("\nEmployee ID is %s", emp[i].id);
        printf("\nEmployee first name is %s", emp[i].fName);
        printf("\nEmployee last name is %s", emp[i].lName);
        printf("\nEmployee Salary is %s", emp[i].salary);
        printf("\nEmployee gender is %s\n", emp[i].gender);
    }
} // end of func

void displayEmployee()
{
    int i = 0;
    char name[20];
    printf("\n\nEnter employee name you want to search: ");
    fflush(stdin);
    gets(name);
    for(i = 0; i <= 4; i++)
    {
        if(strcmp(name,emp[i].fName) == 0)
        {
            printf("\nEmployee details are:");
            printf("\nEmployee ID is %s", emp[i].id);
            printf("\nEmployee first name is %s", emp[i].fName);
            printf("\nEmployee last name is %s", emp[i].lName);
            printf("\nEmployee Salary is %s", emp[i].salary);
            printf("\nEmployee gender is %s\n", emp[i].gender);
            break;
        }
    }
} // end of func

void dispOld()
{
    int c = 0;
    int i = 0;
    for(i = 0; i < a; i++)
    {
        if(emp[i].age > 50)
            c++;
    }
    printf("\nNumber of employees older than 50 is %d", c);
}

/*int main()
{
    int array[5] = {0,5,4,7,2};
    int a = 0;
    int b = 0;
    int temp;
    for(a=0;a<5;a++)
    {
        for(b=0;b<5;b++)
        {
            if(array[b] > array[b+1])
            {
                temp = array[b];
                array[b] = array[b+1];
                array[b+1] = temp;
            }
        }
    }
    printf("%d %d %d %d %d", array[0], array[1], array[2], array[3], array[4]);
}*/
