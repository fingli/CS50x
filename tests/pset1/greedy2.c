/**
*
* %%
*
**/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	// ask user to insert the amount of change
	float c;
	do
	{
		printf("The amount of change: ");
		c = GetFloat();
	}
	while (c < 0);
	
	// converting $ to cents
	c = (c * 100);
    int change = round(c);
	
	// coins -> quarter = 25c, dime = 10c, nickel = 5c, penny = 1c
	int quarter = 25, subtotal = 0, coins_counter = 0;
    if (change >= quarter) // calculate quarters
    {
        subtotal = change - quarter;
        coins_counter++;					
			while (subtotal >= quarter)
 			{
                subtotal = subtotal - quarter;
             	coins_counter++;
            }
    } // end quarters
	
    printf("%d\n", coins_counter);
        printf("%d .\n", subtotal);
	return 0; // happy end
}