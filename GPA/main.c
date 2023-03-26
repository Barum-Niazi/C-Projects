#include <stdio.h>
#include <stdlib.h>

int main()
{
    int semester, subjects1, count1, semesterCount = 1;
    float marks1, gpa, cp, totalcp = 0, creditHours;
    char grade[2];

    do
    {
    printf("Enter the number of semesters you have completed:"); // taking input from user for semesters
    scanf("%d", &semester);
    if(semester > 8)
    printf("Invalid semester try again\n");
    }while(semester > 8);
    // conditions to determine the start of the code
     if(semester >= 1 && semester <= 8)
     {
         do
         {
         printf("how many subjects did you take in semester %d: (-1 to exit)", semesterCount); // takes input for number of semesters
         scanf("%d", &subjects1);
         } while(subjects1 != -1);
            do
            {
             for(count1 = 1; count1 <= subjects1; count1++)
             {
                 printf("Enter your grade in subject %d\n", count1);
                 scanf("%f", &marks1);
                 if(marks1 >= 85 && marks1 <= 90) // conditions to determine grade and credit points on the basis of marks inputted
                 {
                     grade[2] = "A"; // using string in grade as some grades have more than one character in them
                     cp = 3.67;
                 }
                 if(marks1 >= 90)
                 {
                     grade[2] = "A";
                     cp = 4.00;
                 }
                 if(marks1 >= 80 && marks1 < 84)
                 {
                     grade[2] = "A-";
                     cp = 3.34;
                 }
                 if(marks1 == 84)
                 {
                     grade[2] = "A-";
                     cp = 3.66;
                 }
                 if(marks1 >= 75 && marks1 < 79)
                 {
                     grade[2] = "B+";
                     cp = 3.01;
                 }
                 if(marks1 == 79)
                 {
                     grade[2] = "B+";
                     cp = 3.33;
                 }
                 if(marks1 >= 71 && marks1 < 74)
                 {
                     grade[2] = "B";
                     cp = 2.67;
                 }
                 if(marks1 == 74)
                 {
                     grade[2] = "B";
                     cp = 3.00;
                 }
                 if(marks1 >= 68 && marks1 < 70)
                 {
                     grade[2] = "B-";
                     cp = 2.34;
                 }
                 if(marks1 == 70)
                 {
                     grade[2] = "B-";
                     cp = 2.66;
                 }
                 if(marks1 >= 64 && marks1 < 67)
                 {
                     grade[2] = "C+";
                     cp = 2.01;
                 }
                 if(marks1 == 67)
                 {
                     grade[2] = "C+";
                     cp = 2.33;
                 }
                 if(marks1 >= 61 && marks1 < 63)
                 {
                     grade[2] = "C";
                     cp = 1.67;
                 }
                 if(marks1 == 63)
                 {
                     grade[2] = "C";
                     cp = 2.0;
                 }
                 if(marks1 >= 58 && marks1 < 60)
                 {
                     grade[2] = "C-";
                     cp = 1.31;
                 }
                 if(marks1 == 60)
                 {
                     grade[2] = "C-";
                     cp = 1.66;
                 }
                 if(marks1 >= 54 && marks1 < 57)
                 {
                     grade[2] = "D+";
                     cp = 1.01;
                 }
                 if(marks1 == 57)
                 {
                     grade[2] = "D+";
                     cp = 1.30;
                 }
                 if(marks1 >= 50 && marks1 < 53)
                 {
                     grade[2] = "D";
                     cp = 0.10;
                 }
                 if(marks1 == 53)
                 {
                     grade[2] = "D";
                     cp = 1.00;
                 }
                 if(marks1 < 50)
                 {
                     grade[2] = "F";
                     cp = 0.00;
                 }
                 if(marks1 > 100 || marks1 < 0)
                 {
                     marks1 = 50;
                     grade[2] = "D";
                     cp = 0.10;
                 }

             printf("GRADE : %s\t\t CP :%f\t\t MARKS:%.2f\t\t\n", grade, cp, marks1); // shows the user their marks and grade for subject
             totalcp += (cp * 4);
             creditHours = 4 * subjects1; // credit hours for all subjects assumed to be 4
             gpa = totalcp / creditHours;
             }
         printf("GPA for semester is %f\n", gpa);
         semesterCount++;
         }while(semesterCount <= semester);
     }
}
