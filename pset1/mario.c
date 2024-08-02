
/**
*
* Itsa Mario Pyramid
*
* by Yulian Yordanov
*    CS50x 2013
*
**/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// prompt user to input desired height
	int height;
	do
	{
		printf("Input height: ");
		height = GetInt();
	}
	while (height < 0 || height > 23);
	
	// initialize half-pyramid parameters
	int number_of_rows = height;
    int number_of_spaces = (height - 1);
    int number_of_hashes = 2;
	
	// start building half-pyramid
	for (int row = 0; row < number_of_rows; row++)
	{
		for (int spaces = 0; spaces < number_of_spaces; spaces++)
			printf(" "); // print spaces
		for (int hashes = 0; hashes < number_of_hashes; hashes++)
			printf("#"); // print hashes
		printf("\n");
        number_of_spaces = number_of_spaces - 1;
        number_of_hashes = number_of_hashes + 1;
	}	
	return 0; // happy end
}