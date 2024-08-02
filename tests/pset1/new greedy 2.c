	// coins -> quarter = 25c, dime = 10c, nickel = 5c, penny = 1c
	int quarter = 25, dime = 10, nickel = 5, penny = 1;
	int subtotal = 0, coins_counter = 0;
	
	// calculate quarters
	if (change >= quarter)
	{
		subtotal = change - quarter;
		coins_counter++;
			while (subtotal >= quarter)
 			{
				subtotal = subtotal - quarter;
				coins_counter++;
			}
	} // end quarters
	
	// calculate dimes
	if (change < quarter && change >= dime)
	{
		subtotal = change - dime;
		coins_counter++;
			while (subtotal >= dime)
 			{
				subtotal = subtotal - dime;
				coins_counter++;
			}
	} // end dimes
	
	// calculate nickels
	if (change < quarter && change < dime && change >= nickel)
	{
		subtotal = change - nickel;
		coins_counter++;
			while (subtotal >= nickel)
 			{
				subtotal = subtotal - nickel;
				coins_counter++;
			}
	} // end nickels
	
	// calculate pennies
	if (change < quarter && change < dime && change < nickel && change >= penny)
	{
		subtotal = change - penny;
		coins_counter++;
			while (subtotal >= penny)
 			{
				subtotal = subtotal - penny;
				coins_counter++;
			}
	} // end pennies
	
	// calculate remaiming subtotal to dimes
	if (subtotal < quarter && subtotal >= dime)
	{
		while (subtotal >= dime)
		{
			subtotal = subtotal - dime;
			coins_counter++;
		}
	} //end dimes
	
	// calculate remaiming subtotal to nickels
	if (subtotal < dime && subtotal >= nickel)
	{
		while (subtotal >= nickel)
		{
			subtotal = subtotal - nickel;
			coins_counter++;
		}
	} //end nickels	
	
	// calculate remaiming subtotal to pennies
	if (subtotal < nickel && subtotal >= penny)
	{
		while (subtotal >= penny)
		{
			subtotal = subtotal - penny;
			coins_counter++;
		}
	} //end pennies
	
    printf("%d\n", coins_counter);
        printf("%d .\n", subtotal);