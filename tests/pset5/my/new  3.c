// assuming first points to the first element 
node* iterator = first;
while (iterator != NULL)
{
	printf("%s\n", iterator->word);
	iterator = iterator->next;
}
//////////
// hash function
int hash(char* word)
{
	int result = 0;
	int n = strlen(word);
	for(int i = 0; i < n; i++)
	{
		result += word[i];
	}
	return result % HASHTABLE_SIZE;
}

/////////
		// hash function
		int hash;

			char* word = new_node->word;
			int result = 0;
			int n = strlen(word);
			for(int i = 0; i < n; i++)
			{
				result += word[i];
			}
			hash = result % HASHTABLE_SIZE;
			//return hash;
// hash function
int hash(char* word)
{
	int result = 0;
	int n = strlen(word);
	for(int i = 0; i < n; i++)
	{
		result += word[i];
	}
	hash = result % HASHTABLE_SIZE;
	return hash;
}