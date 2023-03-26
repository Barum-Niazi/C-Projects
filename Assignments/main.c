#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct inventory{
	int record_num;
    char tool_name[20];
    int quantity;
    float cost;
	int deleted; 
} tools[100];

// function prototypes
void fillData(); 
void menu();
void addTools();
void editTool();
void removeTool();
void displayTools();

int main()
{
	fillData(); 
    printf("Enter data for the tools");
	menu(); 
}

void menu()
{
	int input; 

	printf("\nPlease select an option: ");
	printf("\n1 - Add Tool ");
	printf("\n2 - Display Tools ");
	printf("\n3 - Remove Tool");
	printf("\n4 - Edit Tool");
	printf("\n5 - Exit");
	printf("\nYour choice: ");

	fflush(stdin);
	scanf("%d", &input);

	switch (input)
	{
	case 1:
		addTools();
		break;
	case 2:
		displayTools(); 
		break;
	case 3:
		removeTool(); 
		break;
	case 4:
		editTool(); 
		break;
	case 5:
		return;
	}
	menu();
}

void fillData() 
{

	int i = 0, loop = 0;
	tools[i].record_num = 3;
	strcpy(tools[i].tool_name, "Electric sander");
	tools[i].quantity = 7;
	tools[i++].cost = 57.98;

	tools[i].record_num = 17;
	strcpy(tools[i].tool_name, "Hammer");
	tools[i].quantity = 76;
	tools[i++].cost = 11.99;

	tools[i].record_num = 24;
	strcpy(tools[i].tool_name, "Jigsaw");
	tools[i].quantity = 21;
	tools[i++].cost = 11.0;

	tools[i].record_num = 39;
	strcpy(tools[i].tool_name, "Lawnmower");
	tools[i].quantity = 3;
	tools[i++].cost = 79.5;

	tools[i].record_num = 56;
	strcpy(tools[i].tool_name, "Powersaw");
	tools[i].quantity = 18;
	tools[i++].cost = 99.99;

	tools[i].record_num = 68;
	strcpy(tools[i].tool_name, "Screwdriver");
	tools[i].quantity = 106;
	tools[i++].cost = 6.99;

	tools[i].record_num = 77;
	strcpy(tools[i].tool_name, "Sledgehammer");
	tools[i].quantity = 11;
	tools[i++].cost = 21.5;

	tools[i].record_num = 83;
	strcpy(tools[i].tool_name, "Wrench");
	tools[i].quantity = 34;
	tools[i++].cost = 7.5;

	for (loop = 0; loop < 100; loop++)
		tools[loop].deleted = (loop < i) ? 0 : 1; 
}

void addTools()
{

    int i,k, found;
	for (i = 0; i < 100; i++)
	{
		if(tools[i].deleted == 1) 
			break;
	}

	if(i > 99) 
	{
		printf("Can not add anymore records!\n");
		return; // function ends
	}
	
    printf("\nEnter tool record number: ");
    scanf("%d", &tools[i].record_num);

	for (k = 0; k < 100; k++)
	{
		if(tools[k].deleted == 1) continue;
		if(tools[k].record_num == tools[i].record_num) 
		{
			printf("Tool for this id already exists, please use the edit option.");
			return;
		}
	}
	// taking input for a new tool 
    printf("\nEnter tool name: ");
    fflush(stdin); // clearing buffer
    gets(tools[i].tool_name);
    fflush(stdin);
    printf("\nEnter quantity of tools: ");
    scanf("%d", &tools[i].quantity); 
    printf("\nEnter cost of tool: ");
    scanf("%f", &tools[i].cost);
	tools[i].deleted = 0; 
}

void editTool(){

    int i, edit, found = 0;
	printf("Please enter the record no to edit: ");
	scanf("%d", &edit);

	for (i = 0; i < 100; i++)
	{
		if(tools[i].deleted == 1) continue;  
		if(tools[i].record_num == edit)
		{
			found = 1; 
			break;
		}
	}

	if(found == 0) 
	{
		printf("Record not found\n");
		return; // func ends
	}
	
    printf("\nEnter new name (%s): ", tools[i].tool_name);
    fflush(stdin);
    gets(tools[i].tool_name);
    fflush(stdin);
    printf("\nEnter new quanity (%d): ", tools[i].quantity);
    scanf("%d", &tools[i].quantity);
    printf("\nEnter cost of tool (%0.2f): ", tools[i].cost);
    scanf("%f", &tools[i].cost);
}

void removeTool(){

    int i, edit, found = 0;
	printf("Please enter the record no to delete: ");
	scanf("%d", &edit);

	for (i = 0; i < 100; i++)
	{
		if(tools[i].deleted == 1) continue;
		if(tools[i].record_num == edit)
		{
			found = 1;
			break;
		}
	}

	if(found == 0)
	{
		printf("Record not found\n");
		return;
	}
	
    tools[i].deleted = 1;
	printf("Tool removed\n");
}

void displayTools()
{
	int i;
	printf("\n---- List of tools ---");
	for (i = 0; i < 100; i++)
	{
		if(tools[i].deleted == 1) continue;
		printf("\n%d - %s (%d) - $%0.2f", tools[i].record_num, tools[i].tool_name, tools[i].quantity, tools[i].cost);
	}
	printf("\n----------------------\n\n");
}