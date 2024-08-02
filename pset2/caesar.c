/**
*
*  Caesar's cipher
*
* by Yulian Yordanov
*    CS50 2013
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
    if (argc != 2)
    {
        printf("Please, provide a correct key\n");
        return 1; //error msg
    }

    // if the key is correct
    else key = atoi(argv[1]);

		while (key > ab)
		key = key - ab;

    string phrase;
    phrase = GetString(); // get message to be encrypted

	int length = strlen(phrase);

		for(int i = 0; i < length; i++) // begin encoding
		{
		    if islower(phrase[i])
			{
			    unsigned char c = phrase[i];
			    c = c + key;
			    
			    if (c >= 'z') 
			    {
			        int j = (c % 'z');
					c = (c - 'z');
					
					if (j != 0)
						c = (c + 'a' - 1);
			    }
			    phrase[i] = c;
			    
			printf("%c", phrase[i]); // print lowercase letters
			}

			if isupper(phrase[i])
			{
			phrase[i] = (phrase[i] + key);
			    if (phrase[i] > 'Z') 
			        phrase[i] = phrase[i] % 'Z' + ('A' - 1);

			printf("%c", phrase[i]); // print uppercase letters
			}

			// if is other than alphabet char
			if (isdigit(phrase[i]) || ispunct(phrase[i]) || isspace(phrase[i]))
                printf("%c", phrase[i]);
			
		} // end encoding
        printf("\n");

	return 0; // happy end
}
