#include <cs50.h>
#include <stdio.h>

/**
*
* F = (9/5)*C + 32
*
**/

int main(void)
{
    printf("C: ");
	float celsius = GetFloat();
	float fahrenheit = ((celsius * 9) / 5) + 32;
	printf("F: %.01f", fahrenheit);
	
	return 0;
}
