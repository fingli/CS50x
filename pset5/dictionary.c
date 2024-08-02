/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 *
 * by Yulian Yordanov
 *     CS50 2013
 ***************************************************************************/
 /**
	## HASH SOURCES ##
	
	http://www.cse.yorku.ca/~oz/hash.html
	http://planetmath.org/GoodHashTablePrimes.html
	http://en.wikipedia.org/wiki/Hash_function#Hashing_variable-length_data
	
 **/

#include <stdbool.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "dictionary.h"

#define HASHTABLE_SIZE 98317 // (prime number)

// define our data structure
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// define our hash table with size
node* hashtable[HASHTABLE_SIZE];

int word_count = 0; // count words in dict.

// hash function
int hash(const char* word)
{
	int i;
	int h = 0;
	int len = strlen(word);
	
	// modified DJB2 hash algorithm
	for (i = 0; i < len; i++)
	{
		h = 33 * h + word[i]; 
		h = h % HASHTABLE_SIZE;
	}
	
	return h;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
	// temporary storage for a word
	char storage[LENGTH + 1];
	int w_length = strlen(word);

	// convert word to lowercase
	for (int j = 0; j < w_length; j++)
	{
		storage[j] = tolower(word[j]);
	}
	storage[w_length] = '\0';

	int index = hash(storage); // hash the word
	
	node* iterator = hashtable[index]; // node to compare words
	
	// if there is no such value in hashtable, return false
	if (iterator == NULL)
	{
		return false;
	}

	// search for word in hashtable and compare
	while (iterator != NULL)
	{
		if (strcmp(storage, iterator->word) == 0)
		{
			return true;
		}
		else
			iterator = iterator->next;
	}
		
	// otherwise return false
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
	// open dictionary file
    FILE* fpd = fopen(dictionary, "r");
    if (fpd == NULL)
    {
        printf("Could not open %s.\n", dictionary);
		return false;
    }

	// create hashtable with next to NULL
	for (int i = 0; i < HASHTABLE_SIZE; i++)
	{
		hashtable[i] = malloc(sizeof(node));
		strcpy(hashtable[i]->word, "NULL");
		hashtable[i]->next = NULL;
	}

	char container[LENGTH + 1]; // container for word from file

	// loop until end of dictionary file
	while (fscanf(fpd, "%s\n", container) != EOF)
	{
		// allocate memory for new word
		node* new_node = malloc(sizeof(node));

		// insert word in the new node
		strcpy(new_node->word, container);
		new_node->next = NULL;
		
		int index = hash(container); // hash value of the given word
		
		// insert in hashtable
		if (hashtable[index] == NULL) // if hashtable is empty - insert
        {
            hashtable[index] = new_node;
			new_node->next = NULL;
        }
        else // if not empty - append at the beginning 
        {
            new_node->next = hashtable[index];
            hashtable[index] = new_node;
        }

		word_count++; // count how many words are inserted
	}
	
	fclose(fpd); // close dictionary
		
	return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
	if (word_count > 0)
	{
		return word_count;
	}
	else
		return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    int indx = 0;
	
	while (indx < HASHTABLE_SIZE)
	{
		if (hashtable[indx] == NULL) // if is empty
		{
			indx++; // go to next
		}
		
		else // iterate through nodes
		{
			while (hashtable[indx] != NULL)
			{
				node* iter = hashtable[indx];
				hashtable[indx] = iter->next;
				free(iter); // unload
			}
			indx++; // go to next
		}
	}
	
	// on success
	return true;
}

