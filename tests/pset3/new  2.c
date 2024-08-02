   for (int i = 0; i < WORDS; i++)
	{
        if (strcmp(s, dictionary.words[i].letters) != 0) // if not in dictionary
            result = false;
            
        else if (strcmp(s, dictionary.words[i].letters) == 0) // if is in dictionary
		{
			if (dictionary.words[i].found == true) // if word is already used
			{
				result = false;
				break;
			}
			else
				result = true; // word exist
        }

        if (result == true)
        {
            dictionary.words[i].found = true; // mark word as found
            break;
        }
    }
//----------------------------------
	int search;
	// binary search
	search = bsearch(strcmp(s, dictionary.words[i].letters));

	if (search != 0) // if not in dictionary
		result false;
	
	else if (search == 0) // if is in dictionary
	{
		if (dictionary.words[i].found == true) // if word is already used
		{
			result false;
			break;
		}
		else
			result true; // word exist
	}
    if (result == true)
    {
		dictionary.words[i].found = true; // mark word as found
		break;
	}	