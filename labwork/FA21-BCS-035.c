#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	char item;
	int bill = 0;
	int quantity;
	do
	{
	printf("\nEnter the food item you want to add to cart: (press x to checkout)");
	printf("\nB: Burger \t\tRs200");
	printf("\nF: French Fries \tRs50");
	printf("\nP: Pizza \t\tRs500");
	printf("\nS: Sandwiches \t\tRs150\n");
	item = getch();
	switch(item)
	{
		case 'b':
			printf("Enter the quantity:");
			scanf("%d", &quantity);
			printf("%d burger(s) added to your cart\n", quantity);
			bill = bill + (200*quantity);
			break;
		case 'f':
			printf("Enter the quantity:");
			scanf("%d", &quantity);
			printf("%d orders of french fries added to your cart\n", quantity);
			bill = bill + (50 * quantity);
			break;
		case 'p':
			printf("Enter the quantity:");
			scanf("%d", &quantity);
			printf("%d pizza(s) added to your cart\n", quantity);
			bill = bill + (500 * quantity);
			break;
		case 's':
			printf("Enter the quantity:");
			scanf("%d", &quantity);
			printf("%d sandwich(es) added to your cart\n", quantity);
			bill = bill + (150 * quantity);
			break;
		case 'B':
			printf("Enter the quantity:");
			scanf("%d", &quantity);
			printf("%d burger(s) added to your cart\n", quantity);
			bill = bill + (200 * quantity);
			break;
		case 'F':
			printf("Enter the quantity:");
			scanf("%d", &quantity);
			printf("%d french fries added to your cart\n", quantity);
			bill = bill + (50 * quantity);
			break;
		case 'P':
			printf("Enter the quantity:");
			scanf("%d", &quantity);
			printf("%d pizza added to your cart\n", quantity);
			bill = bill + (500 * quantity);
			break;
		case 'S':
			printf("Enter the quantity:");
			scanf("%d", &quantity);
			printf("%d sandwich added to your cart\n", quantity);
			bill = bill + (150 * quantity);
			break;
		}
	}
	while(item != 'x');

	printf("\nYour total bill is \tRs%d", bill);
	return 0;
}
