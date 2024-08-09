#include <stdio.h>
#include <math.h>

int main(void)
{
	// User's input
	float cost1, cost2, cost3, totalcost;
	// Cost of item 1
	printf("Enter the cost of item 1: $");
	scanf("%f", &cost1);
	// Cost of item 2
	printf("Enter the cost of item 2: $");
	scanf("%f", &cost2);
	// Cost of item 3
	printf("Enter the cost of item 3: $");
	scanf("%f", &cost3);

	// calculation of dollars, quarters, dimes, nickels and pennies
	int dollars, quarters, dimes, nickels, pennies;
	if (cost1 + cost2 + cost3 > 0)
	{
		// Total cost of all items
		totalcost = cost1 + cost2 + cost3;
		printf("Total Cost is: %.2f$\n", totalcost);

		// turning totalcost to a whole number
		totalcost *= 100;
		totalcost = round(totalcost);

		dollars = totalcost / 100;
		quarters = ((int)totalcost % 100) / 25;
		dimes = (((int)totalcost % 100) % 25) / 10;
		nickels = ((((int)totalcost % 100) % 25) % 10) / 5;
		pennies = totalcost - ((dollars * 100) + (quarters * 25) + (dimes * 10) + (nickels * 5));

		// output
		printf("You used %i dollars, %i quarters, %i dimes, %i nickels, and %i pennies.", dollars, quarters, dimes, nickels, pennies);
	}
	else
	{
		printf("Enter a valid input");
	}
	return 0;
}