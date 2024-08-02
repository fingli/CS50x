    for (int i = 0; i < WORDS; i++)
	{
        if (strcmp(s, dictionary.words[i].letters) != 0) // if not in dictionary
		{
            result = false;
        }
        else if (strcmp(s, dictionary.words[i].letters) == 0) // if is in dictionary
		{
			if (dictionary.words[i].found == true) // if word is already used
				result = false;
			else
			{
			result = true;
			dictionary.words[i].found = true; // mark word as found
			}
        }
		
    if ((result == true) || (dictionary.words[i].found == true))
        break;
    }
//---------------------------------

int min = 0;
int max = WORDS;
    for (int i = 0; i < WORDS; i++)
	{
		int midpoint = (min + max) / 2;
		if (strcmp(s, dictionary.words[midpoint].letters) > 0) 
			max = midpoint - 1;