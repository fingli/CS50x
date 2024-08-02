/**
*
*  Vigenere's cipher
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
#define AB 26 // numbers of the  alphabet
#define DIF 32 // difference from 'a' to 'A'

int main(int argc, string argv[])
{
	string key, msg;
	
    // if the key is not correct
    if (argc != 2)
    {
        printf("Please, provide a correct key\n");
        return 1; //error msg
    }
    else key = argv[1]; // if the key is correct

	//---
	int l_key = strlen(key);
    //---

	for (int check = 0; check < l_key; check++)
	{
		if (isdigit(key[check]) || ispunct(key[check]) || isspace(key[check]))
		{
            printf("Please, provide a correct key\n");
            return 1; //error msg
        }
	}
	
	// get message from user
	msg = GetString();
	
	//---
	int l_msg = strlen(msg);
	int j;
	int dig_count = 0; // counter of non-alpha chars
	//---
	
	for (int i = 0; i < l_msg; i++) // begin encoding
	{
		// if is not alphabet char
		if (isdigit(msg[i]) || ispunct(msg[i]) || isspace(msg[i]))
		{
			dig_count++;
			printf("%c", msg[i]); // print non-alpha chars
		}
		else
		{
			j = (i - dig_count) % l_key; // key counter
			
			if (islower(msg[i])) // if is lowercase letter
			{
				if (key[j] < 'a') // if the key is uppercase
				        key[j] = key[j] + DIF; // make it lowercase
				        
				unsigned char uc = msg[i];
				uc = uc + key[j];

					uc = (uc - 'z');
					int x = (uc % 'z');

					if (x != 0)
					{
					    uc = (uc + AB - 1);
					    if (uc > 'z')
					        uc = uc - AB;
					}
					
				msg[i] = uc;
				printf("%c", msg[i]); // print lowercase letter
			} // end lowercase
			
			if (isupper(msg[i])) // if is uppercase letter
			{
				unsigned char uc = msg[i];
				uc = uc + key[j];

					uc = (uc - 'Z');
					int x = (uc % 'Z');

					if (x != 0)
					{
					    uc = (uc + AB - 1);
					    if (uc > 'Z')
					        uc = uc - AB;
					}
					
				msg[i] = uc;
				printf("%c", msg[i]); // print uppercase letter
			} // end uppercase
			
		} // end else
	} //end encoding
	printf("\n");

	return 0; //happy end
}
