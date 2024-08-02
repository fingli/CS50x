/**
*
*  Caesar's cipher
*
* by Yulian Yordanov
*    CS50 2012
*
**/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> // atoi - convert a string to an integer
#include <string.h> // strlen - returns the length of a string
#include <ctype.h>


int main(int argc, string argv[])
{
    int ab = 26; // number of chars in ascii alphabet
	int key;
	
    // if the key is not correct
    if (argc > 2 || argc <= 1)
    {
        printf("Please, provide a correct key\n");
        return 1; //error msg
    }

    // if the key is correct
    else key = atoi(argv[1]);

		while (key > ab)
		key = key - ab;

    // ask user to input a message to be encrypted
    string phrase;

    phrase = GetString();

	int length = strlen(phrase);

		for(int i = 0; i < length; i++)
		{
		    if islower(phrase[i])
			{   printf("dec: %d\n", phrase[i]); //
			phrase[i] = phrase[i] + key;  printf("+key: %d\n", phrase[i]); //
			    if (phrase[i] < 0)
				   phrase[i] = phrase[i] * (-1); printf("-1: %d\n", phrase[i]);
			    if (phrase[i] >= 'z') 
			    {
			        int j = (phrase[i] % 'z'); printf("j: %d\n", phrase[i]);
					phrase[i] = (phrase[i] - 'z'); printf("-z: %d\n", phrase[i]);
					
					if (j != 0)
						phrase[i] = (phrase[i] + 'a' - 1);printf("+a: %d\n", phrase[i]);
					if (j == 0) // 
						phrase[i] = (phrase[i] + 'a' - 1);printf("+a: %d\n", phrase[i]);
			    } // ??
			printf("%c", phrase[i]);
			}
			if isupper(phrase[i])
			{   
			phrase[i] = (phrase[i] + key);
			    if (phrase[i] > 'Z') // ??
			        phrase[i] = phrase[i] % 'Z' + ('A' - 1);
			        
			printf("%c", phrase[i]);
			}
			// -------------
			if ( isdigit(phrase[i]) || ispunct(phrase[i]) || isspace(phrase[i]))
                 printf("%c", phrase[i]);
			// -------------
		}
        printf("\n");
	
	
	

    return 0; // happy end
}
