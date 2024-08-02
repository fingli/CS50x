/**
*
* Itsa Mario Pyramid
*
* by Yulian Yordanov
*    CS50x 2012
*
**/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// prompt user to insert desired height
	int height;
	do
	{
		printf("Insert height: ");
		height = GetInt();
	}
	while (height <= 0 || height > 23);
	
	// initialize half-pyramid parameters
	int number_of_rows = height;
    int number_of_spaces = (height - 1);
    int number_of_hashes = 2;
	
	// start biulding half-pyramid
	for (int row = 0; row < number_of_rows; row++)
	{
		for (int spaces = 0; spaces < number_of_spaces; spaces++)
			printf(" "); // print space
		for (int hashes = 0; hashes < number_of_hashes; hashes++)
			printf("#"); // print hash
		printf("\n");
        number_of_spaces = number_of_spaces - 1;
        number_of_hashes = number_of_hashes + 1;
	}	
	return 0; // end (kthxbye)
}