#include <stdio.h>
#include <string.h>
 
struct student 
{
            int id;
            char name[20];
            float percentage;
};
 
void func(struct student test);
 
int main() 
{
            struct student record;
 
            record.id=1;
            strcpy(record.name, "Raju");
            record.percentage = 86.5;
 
            func(record);
            printf(" Id is :%d \n", record.id);
            printf("Name is: %s \n", record.name);
    
            return 0;
}
 
void func(struct student test)
{
            printf(" Id is: %d \n", test.id);
            printf(" Name is: %s \n", test.name);
            printf(" Percentage is: %f \n", test.percentage);
}