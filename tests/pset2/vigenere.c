/**
*
*  Vigenere's cipher
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
// j = j % strlen('ohaio'); repeating the key

int main(int argc, string argv[])
{
	string key, msg;
	
    // if the key is not correct
    if (argc > 2 || argc <= 1)
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
	printf("Your message: ");
	msg = GetString(); // the message to be encrypted
	
	//---
	int l_msg = strlen(msg);
	int j;
	int dig_count = 0;
	//---
	
	for (int i = 0; i < l_msg; i++) // begin encoding
	{
			//j = i % l_key; // key counter
			//printf("j: %d\n", j);
		// if is not alphabet char
		if (isdigit(msg[i]) || ispunct(msg[i]) || isspace(msg[i]))
		{
		   dig_count++; printf("dig_count: %d\n", dig_count);
			//j = (i - dig_count) % l_key; printf("j--: %d\n", j);
			printf("%c\n", msg[i]);
		}
		else
		{
		    j = (i - dig_count) % l_key; printf("j-dig: %d\n", j);
			//j = i % l_key; // key counter
			//printf("j: %d\n", j);
			
			if (islower(msg[i])) // if is lowercase letter
			{
				unsigned char c = msg[i]; printf("c: %d\n", c);
				    if (key[j] < 'a')
				        key[j] = key[j] + 32;
				c = c + key[j]; printf("c+k: %d\n", c);
				printf("key[j]: %d\n", key[j]);
				//if (c >= 'z') 
				//{ 
					c = (c - 'z'); printf("c-z: %d\n", c);
					int x = (c % 'z'); printf("x: %d\n", x);
						
					
					if (x != 0)
					{
					    c = (c + 26 - 1); printf("c+a: %d\n", c);
					    if (c > 'z')
					        c = c - 26;
					}
				//}
				msg[i] = c;
				printf("%c\n", msg[i]); // print lowercase letter
			} // end lowercase
			
			
		} // end else
	} //end encoding
	printf("\n");

	return 0; //happy end
}
