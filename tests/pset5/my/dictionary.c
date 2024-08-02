/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "dictionary.h"

#define HASHTABLE_SIZE 4096

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
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
		if (isalpha(word[i]))
		{
            n = word[i] - 'a' + 1;
        }   
        hash = ((hash << 3) + n) % HASHTABLE_SIZE;
    }
	return hash;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
	// temporary storage for a word
	char temp[LENGTH + 1];
	int w_length = strlen(word);
	for (int j = 0; j < w_length; j++)
	{
		// convert word to lowercase
		temp[j] = tolower(word[j]);
	}
	temp[w_length] = '\0';

	int index = hash(temp); // hash the word
	
	// if there is no such value in hashtable, return false
	if (hashtable[index] == NULL)
	{
		return false;
	}
	
	node* iterator = hashtable[index]; // node to compare words
	
	// search for word in hashtable and compare
	while (iterator != NULL)
	{
		if (strcmp(temp, iterator->word) == 0)
		{
			return true;
		}
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
		hashtable[i]->next = NULL;
	}
	
	char word[LENGTH + 1]; // place for word from file
	
	// loop until end of dictionary file
	while (fscanf(fpd, "%s\n", word) != EOF)
	{
		// allocate memory for new word
		node* new_node = malloc(sizeof(node));
		
		// insert word in the new node
		strcpy(new_node->word, word);
		new_node->next = NULL; //@@??
		
		int index = hash(word); // hash value of the given word
		
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
	
	// close dictionary
	fclose(fpd);
		
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
		if (hashtable[indx] == NULL) // if is empty go to next
		{
			indx++;
		}
		
		else // iterate through nodes
		{
			while (hashtable[indx] != NULL)
			{
				node* iterator = hashtable[indx];
				hashtable[indx] = iterator->next;
				free(iterator); // free
			}
			indx++; // go to next
		}
	}
	
	// on success
	return true;
}

