#include <stdio.h>
#include <stdlib.h>

void get_marks(int *marks, int size); // function prototype for the function that takes marks from user
int total_marks(int *marks, int size); // function prototype for the total marks
void show_marks(int *marks, int size); // function prototype for the function that is going to display the marks

int main()
{
    int s;
    int a;
    int subject[5]; // array of 5 elements
    get_marks(&subject, 5); // function is called and address of array is passed which becomes a pointer in the function
    show_marks(&subject, 5); // function call again with same arguments
    s = total_marks(&subject, 5); // function call and value to be returned is stored in this variable
    printf("------Total and Average------\n");
    printf("Sum of Marks = %d\n", s); // displays the total marks
    printf("Avg of Marks = %0.2f\n", (float) s/5.0); // implicit typecasting for average
    printf("Enter 1 to continue, any other to exit: "); // allows user to re-run the program or exit it
    scanf("%d", &a);
    if(a == 1)
        main(); // calls the main function again if 1 is entered by the user, exits program if anything else is entered
}
void get_marks(int *marks, int size) // function body, data type is void as nothing is to be returned
{
    int a; // iterator for the for loop
    for(a=0; a<5; a++)
    {
        printf("Enter marks of subject %d: ", a + 1);
        scanf("%d", marks + a); // taking input from user while increasing the address
    }
}

int total_marks(int *marks, int size) // data type is int as a value needs to be returned
{
    int sum = 0; // variable for storing sum
    int k; // iterator
    for(k=0; k<5; k++)
    {
        sum = sum + *(marks + k); // adds the sum of each element one by one and stores it in the variable sum
    }
    return sum; // returns the answer of sum back to main
}

void show_marks(int *marks, int size)
{
    int k; // iterator
    printf("------Marks in subjects------\n");
    for(k=0; k<5; k++)
    {
        printf("Subject %d Marks:\t%d\n", k + 1, *(marks+k)); // using dereferencing operator displays marks one by one for each subject through address
    }
}
