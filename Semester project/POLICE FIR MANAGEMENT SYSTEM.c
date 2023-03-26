/*                                              PROGRAMMING FUNDAMENTALS SEMESTER PROJECT
                                                        POLICE FIR MANAGEMENT SYSTEM

                                                    ANAS ASIF FA21-BCS-131
                                                    MUHAMMAD BARUM KHAN FA21-BCS-035

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>

struct records
{
    char id[10];
    char gender[10];
    int age;
    char name[20];
    char height[10];
    char weight[15];
    char eyeColor[10];
    char hairColor[10];
    char birthMark[20];
    char contactNum[60];
    char dateArrest[20];
    char crime[50];
    char penalCode[10];
    char crimAddress[50];
    char polAddress[50];
} criminal;


int x = 0; // global variable which will act as a counter for login function

void login(); // prototype for login function
void recordAdd(); // prototype for adding records function
void recordSearch(); // prototype for searching records function
void recordList(); // prototype for listing records function
void recordEdit(); // prototype for editing records function
void recordDelete(); // prototype for deleting records function

int main()
{

    int ch; // variable for choice

    if(x == 0) // login screen to be only shown once even if main function is called again
        login(); // calls the login function

    printf("\n\t\t\t--------------   Police FIR Record Management System   -------------");
    printf("\n\t\t------ Main menu ------");
    printf("\n\n\t\t1. Add New FIR Record");
    printf("\n\t\t2. Search Existing Records");
    printf("\n\t\t3. List All Records");
    printf("\n\t\t4. Modify Any Record");
    printf("\n\t\t5. Delete Any Record");
    printf("\n\t\t6. Exit the program");
    printf("\n\n\t\t->Enter your choice:");
    scanf("%d",&ch);

    if(ch == 1) // if user inputs 1 then add record function is called
        recordAdd();

    if(ch == 2) // if user inputs 2 then search record function is called
        recordSearch();

    if(ch == 3) // if user inputs 3 then record list function is called
        recordList();

    if(ch == 4) // if 4 is input then edit record function is called
        recordEdit();

    if(ch == 5) // if 5 is input then delete record function is called
        recordDelete();

    if(ch == 6) // if 6 is input program exits
        exit(0);

    if(ch > 6)
    {
        printf("Invalid Option, try again");
        sleep(1);
        system("cls");
        main();
    }
}

void login() // function for login starts
{
    x = 1; // assigning value of 1 to x so this function is not called again
    int a = 0; // counter
    char c; // variable for storing password character by character
    int i = 0; // variable for indexing
    char user[20]; // character array that stores input from user
    char password[10];

    do // loop because we want the user to be able to try multiple times in case of wrong password
    {

        printf("\n\t\t ============  LOGIN DETAILS ============\n");
        printf("\n\t\tEnter Username:");

        gets(user); // takes a string from the user and stores it in the user array
        printf("\n\t\tEnter Password:");

        while(i < 10) // loop as we are taking input character by character
        {
            fflush(stdin);
            password[i] = getch(); // char by char input without showing the values on screen
            c = password[i]; // storing input

            if(c == '\r') // as soon as user presses the enter key the loop ends
                break;
            else
                printf("*"); // this is shown instead of what the user enters

            i++; // increments addresses
        }

        password[i] = '\0'; // assigns value of null character to the last index
        i = 0; // i is assigned 0 because we want the addresses to start from 0

        if(strcmp(user, "anas") == 0 && strcmp(password, "anas") == 0) // compares strings
        {
            printf("\n\n\n\t\tSUCCESSFULLY LOGGED IN\n"); // successful if both strings are equal
            sleep(1); // pauses the screen for a specified amount of time
            system("cls"); // clears the screen
            break; // ends the loop because login is successful
        }
        else
        {
            printf("\n\n\t\tLogin unsuccessful");// unsuccessful if both are not equal
            a++;
            printf("\n\n\n\n\t\tPress any key to try again"); // prompts user to try entering the password again
            getch();
            system("cls");
        }

    } while(a <= 2); // loop ends if user enters wrong password three times

    if(a > 2) // if condition if user enters wrong password thrice
    {
        printf("\n\n\t\t\tToo many attempts");
        printf("\n\n\t\t\tSYSTEM WILL NOW CLOSE!");
        sleep(1); // pauses for one second
        exit(0); // exits the program
    }

} // function for login ends

void recordAdd() // function for adding records
{
    char id[10];
    char option; // variable used to ask if user wants to enter new record
    FILE * fp; // fp is a pointer that points to address of a file
    system("cls"); // clears screen

    printf("\n\t\t\t---------------  Add a Record  ---------------");
    fp = fopen("record.txt", "ab+"); // opens record.txt file for appending

    if(fp == NULL) // conditions for if file does not exist
    {
        fp=fopen("record.txt", "wb+"); // creates a new file for writing
        if(fp == NULL) // if file still does not get created
        {
            printf("File does not exist");
            exit(0); // program exits
        }
    }

    fflush(stdin); // clears buffer
    printf("\nEnter ID to check if it exists or not:");
    fflush(stdin);
    gets(id);

    while(!feof(fp)) // reads file till the end of file
    {
        fread(&criminal, sizeof(criminal), 1, fp); // reads the address of struct to compare strings
        if(strcmp(id, criminal.id) == 0)
        {
            printf("\n\t\tRecord already exists");
            printf("\n\t\tEnter a new record!");
            sleep(2);
            system("cls");
            recordAdd(); // if id exists then function is called again
        }
    }

    printf("\nEnter Name:");
    gets(criminal.name);

    printf("\nEnter Age:");
    scanf("%d", &criminal.age);

    if(criminal.age < 18) // conditions for if the age of criminal is entered less than 18
    {
        printf("\n\n\t\tYou can not add record of a person under 18!");
        printf("\n\n\t\t REDIRECTING TO MAIN MENU!");
        sleep(2);
        system("cls");
        main(); // calls main function again but this time login screen wont be shown
    }

    // prompting user to enter the details //
    fflush(stdin);
    printf("\nEnter ID: ");
    gets(criminal.id);

    if(strcmp(id, criminal.id) != 0) // condition if user tries to enter an existing id after bypassing first check
    {
        printf("\n\t\tDid not match with the ID first entered\n");
        printf("\n\t\tEnter record again!");
        sleep(2); // pauses for 2 seconds
        system("cls");
        recordAdd(); // calls function again
    }

    printf("\nEnter Gender: ");
    gets(criminal.gender);

    printf("\nEnter Height: ");
    gets(criminal.height);

    printf("\nEnter Weight: ");
    gets(criminal.weight);

    printf("\nEnter Hair Color: ");
    gets(criminal.hairColor);

    printf("\nEnter Eye Color: ");
    gets(criminal.eyeColor);

    printf("\nEnter Birthmark: ");
    gets(criminal.birthMark);

    printf("\nEnter Contact Number: ");
    gets(criminal.contactNum);

    printf("\nEnter Crime: ");
    gets(criminal.crime);

    printf("\nEnter Penal Code: ");
    gets(criminal.penalCode);

    printf("\nEnter Date of Arrest: ");
    gets(criminal.dateArrest);

    printf("\nEnter Criminal Address: ");
    gets(criminal.crimAddress);

    printf("\nEnter Police Station Address: ");
    gets(criminal.polAddress);

    fwrite(&criminal, sizeof(criminal), 1, fp); // writes all the data entered by the user into the file
    fclose(fp); // closes file

    printf("\n\nAdd Another Record: (Y/N) ");
    option = getche(); // gets user choice
    sleep(1); // pauses the program for one second

    if(option == 'Y' || option == 'y')
        {
        recordAdd();
        } // if user enters y then function is recalled

    if(option == 'N' || option == 'n')
    {
        system("cls");
        main(); // if user enters n main is called
    }

    if(option != 'N' || option != 'n' || option != 'Y' || option != 'y') // in case user enters a wrong option
    {
        printf("\nInvalid choice, redirecting to main menu!");
        sleep(1);
        system("cls");
        main();
    }
} // adding record function ends

void recordSearch() // searching record function
{
    FILE * fp;
    char che; // variable to ask user if they want to recall this function or go back to main
    fp = fopen("record.txt", "rb"); // opens record.txt in reading mode
    char id[20];
    int a; // variable for choice
    system("cls"); // clears screen

    printf("\n\t\t-----------------Search Records--------------------------");
    printf("\nEnter id to be searched:");
    fflush(stdin);
    gets(id);

    while(fread(&criminal, sizeof(criminal), 1, fp) == 1) // checks till end of file
    {

        if(strcmp(criminal.id, id) == 0) // if id matches an existing one in file then it is displayed
        {
             // displaying record //
            printf("\n\n");
            printf("Criminal's ID : %s", criminal.id);
            printf("\nCriminal's Name: %s", criminal.name);
            printf("\nCriminal's Age: %d", criminal.age);
            printf("\nCriminal's Gender: %s", criminal.gender);
            printf("\nCriminal's Height: %s", criminal.height);
            printf("\nCriminal's Weight: %s", criminal.weight);
            printf("\nCriminals Eye Color: %s", criminal.eyeColor);
            printf("\nCriminal's Birth Mark: %s", criminal.gender);
            printf("\nCriminal's Contact Number: %s", criminal.contactNum);
            printf("\nCriminal's Crime: %s", criminal.crime);
            printf("\nCriminal's Penal Code: %s", criminal.penalCode);
            printf("\nCriminal's Address: %s", criminal.crimAddress);
            printf("\nCriminal's date of arrest: %s", criminal.dateArrest);
            printf("\nPolice Address: %s", criminal.polAddress);
        }
    }

    printf("\nDo you want to search another record (Y/N): "); // prompts user
    che = getche(); // gets user choice

    if(che == 'y' || che == 'Y') // if user enters y then function is called again to search record
    {
        sleep(1); // pauses the program for one second
        recordSearch();
    }

    if(che == 'n' || che == 'N') // if user enters n then main is called without having to log in
    {
        sleep(1); // pauses the program for one second
        system("cls");
        main();
    }

    if(che != 'N' || che != 'n' || che != 'Y' || che != 'y') // in case user enters a wrong option
    {
        printf("\nInvalid choice, redirecting to main menu!");
        sleep(1);
        system("cls");
        main();
    }
} // searching record function ends

void recordList() // viewing record list function
{
    int b; // variable to ask user if they want to exit or go back to main
    FILE * fp;
    fp = fopen("record.txt", "rb"); // opens file in reading mode
    system("cls");

    while(fread(&criminal, sizeof(criminal), 1, fp) == 1) // checks till end of file
    {
        // displaying the records //
        printf("\n\n");
        printf("Criminal's ID : %s", criminal.id);
        printf("\nCriminal's Name: %s", criminal.name);
        printf("\nCriminal's Age: %d", criminal.age);
        printf("\nCriminal's Gender: %s", criminal.gender);
        printf("\nCriminal's Height: %s", criminal.height);
        printf("\nCriminal's Weight: %s", criminal.weight);
        printf("\nCriminals Eye Color: %s", criminal.eyeColor);
        printf("\nCriminal's Birth Mark: %s", criminal.gender);
        printf("\nCriminal's Contact Number: %s", criminal.contactNum);
        printf("\nCriminal's Crime: %s", criminal.crime);
        printf("\nCriminal's Penal Code: %s", criminal.penalCode);
        printf("\nCriminal's Address: %s", criminal.crimAddress);
        printf("\nCriminal's date of arrest: %s", criminal.dateArrest);
        printf("\nPolice Address: %s", criminal.polAddress);
        printf("\n\n");
    }

    fclose(fp); // closes file

    printf("\nEnter 1 to go back to main menu or any other key to exit the program ");
    scanf("%d", &b); // if 1 is input the program goes back to main menu

    if(b == 1)
    {
        system("cls");
        main(); // recalls main function
    }
    else
        exit(1); // exits the program
} // viewing record function ends

void recordEdit() // edit record func start
{

    system("cls");
    FILE * fp;
    char id[10];
    char choice;
    int select, status = 0;

    printf("\n\n\t\t------------------------------------\n");
    printf("\t\t\t- EDIT RECORDS -");
    printf("\n\t\t--------------------------------------\n\n");

    do
    {



        printf("\n\tENTER ID:");
        fflush(stdin);
    	gets(id);
        fp = fopen ( "record.txt", "rb+" ) ;



        while ( fread ( &criminal, sizeof ( criminal ), 1, fp ) == 1 )
        {

            if(strcmp(criminal.id, id) == 0) // if an id matches to the one input by the user
            {
                // displaying old record //

                printf("\nYOUR OLD RECORD :");
                printf("\nCRIMINAL'S NAME: %s",criminal.name);
                printf("\nCRIMINAL'S Gender: %s",criminal.gender);
                printf("\nCRIMINAL'S AGE: %d",criminal.age);
                printf("\nCRIMINAL'S WEIGHT: %s",criminal.weight);
                printf("\nCRIMINAL'S HEIGHT: %s",criminal.height);
                printf("\nCRIMINAL'S HAIRCOLOR: %s",criminal.hairColor);
				printf("\nCRIMINAL'S EYECOLOR: %s",criminal.eyeColor);
                printf("\nCRIMINAL'S CRIME: %s",criminal.crime);
                printf("\nADDRESS OF POLICE STATION: %s",criminal.polAddress);
                printf("\nARRESTED DATE: %s",criminal.dateArrest);



                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");
                printf("\n\n");
                printf("\n1.NAME");
                printf("\n2.GENDER");
                printf("\n3.AGE");
                printf("\n4.WEIGHT");
                printf("\n5.HEIGHT");
                printf("\n6.HAIRCOLOR");
                printf("\n7.EYECOLOR");
                printf("\n8.CRIME");
                printf("\n9.ADDRESS OF POLICE STATION");
                printf("\n10.DATE OF ARREST");
                printf("\n11.TO EDIT ENTIRE RECORD");
                printf("\n12.GO BACK TO MAIN MENU");
                printf("\n\n");

                do
                {
                    // taking input on what to edit //
                    printf("\nENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d", &select); // using switch statements
                    fflush(stdin);

                    switch(select)
                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNAME: ");
                        gets(criminal.name);
                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nGender: ");
                        gets(criminal.gender);
                        break;

                    case 3:
                        printf("\nCRIMINAL AGE CANNOT BE CHANGED!");
                        sleep(2);
                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nWEIGHT: ");
                        gets(criminal.weight);
                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");

                        printf("\nHEIGHT: ");
                        gets(criminal.height);
                        break;

                    case 6:
                        printf("ENTER THE NEW DATA:");

                        printf("\nHAIRCOLOR: ");
                        gets(criminal.hairColor);
                        break;

                    case 7:
                        printf("ENTER THE NEW DATA:");

                        printf("\nEYECOLOR: ");
                        gets(criminal.eyeColor);
                        break;

                    case 8:
                        printf("ENTER THE NEW DATA:");

                        printf("\nCRIME: ");
                        gets(criminal.crime);
                        break;

                    case 9:
                        printf("ENTER THE NEW DATA:");

                        printf("\nADDRESS OF POLICE STATION: ");
                        gets(criminal.polAddress);
                        break;

                    case 10:
                        printf("ENTER THE NEW DATA:");

                        printf("\nARRESTED DATE: ");
                        gets(criminal.dateArrest);
                        break;

                    case 11:
                        printf("\n");
                    	printf("\nENTER THE NEW DATA:");

                        printf("\nCRIMINAL NAME: ");
			            gets(criminal.name);

                        printf("GENDER: ");
			            gets(criminal.gender);

                        printf("AGE: ");
			            fflush(stdin);
			            scanf("%d",&criminal.age);

                        printf("WEIGHT: ");
			            fflush(stdin);
			            gets(criminal.weight);

                        printf("HEIGHT: ");

                        gets(criminal.height);
			            printf("HAIRCOLOR: ");

                        gets(criminal.hairColor);
			            printf("EYECOLOR: ");

                        gets(criminal.eyeColor);
			            printf("ADDRESS OF POLICE STATION: ");

                        gets(criminal.polAddress);
			            printf("ARRESTED DATE: ");

                        gets(criminal.dateArrest);
                        break;

                    case 12:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");
                        system("cls");
                        main(); // calling main func to go back to menu
                        break;

                    default:
                        printf("\nINVALID CHOICE...TRY AGAIN\n");
                        break;

                    }

                }
                while(select < 1||select > 20);

                fseek(fp, -sizeof(criminal), SEEK_CUR); // goes to the location of the data

                fwrite(&criminal, sizeof(criminal), 1, fp); // writing the new data into the file

                fseek(fp, -sizeof(criminal), SEEK_CUR);

                fread(&criminal, sizeof(criminal), 1, fp);

                choice = 5;

                break;

            }
        }

        if(choice == 5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD :\n");
            printf("--------------------\n");
            printf("\nCRIMINAL NAME IS: %s",criminal.name);
            printf("\nCRIMINAL SEX IS: %s",criminal.gender);
            printf("\nCRIMINAL AGE IS: %d",criminal.age);
            printf("\nCRIMINAL WEIGHT IS: %s",criminal.weight);
            printf("\nCRIMINAL HEIGHT IS: %s",criminal.height);
            printf("\nCRIMINAL HAIRCOLOR IS: %s",criminal.hairColor);
			printf("\nCRIMINAL EYECOLOR IS: %s",criminal.eyeColor);
            printf("\nCRIMINAL CRIME IS: %s",criminal.crime);
        	printf("\nADDRESS OF POLICE STATION: %s",criminal.polAddress);
            printf("\nARRESTED DATE: %s",criminal.dateArrest);
            fclose(fp);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD (Y/N): ");
            scanf("%c",&choice);

        }
        else
        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
        	scanf("%c",&choice);

        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp ) ;
    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    system("cls");
    main();
    getch();

}
void recordDelete()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t=============================================");
    printf("\n\t\tAN FIR CANNOT BE DELETED!!!!");
    printf("\n\t\tIT IS RESTRICTED BY THE LAW");
    printf("\n\t\tYOU ARE BEING REDIRECTED TO MAIN MENU!!!");
    printf("\n\t\t=============================================");
    sleep(4);
    system("cls");
    main();
}






