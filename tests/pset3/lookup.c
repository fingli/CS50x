dictionary.words[].found 
//============
bool lookup(string s)
{
    bool result = false;
    
    //make everything capitized
    for (int i = 0, n = strlen(s); i < n; i++) {
        if (s[i] >= 65 || s[i] <= 90) {
            s[i]+= 32;
        }
    }
    
    //attempt at linear search
    bool result = false;
    for (int i = 0; i<WORDS; i++) {
        for (int j = 0, n = strlen(s); j < n; j++) {
            do {
                if (s[j] == dictionary.words[i].letters[j]) {
                    result = true;
                }
                else if (s[j] != dictionary.words[i].letters[j]) {
                    result = false;
                }
            } while (result == true);
            if (result == true)
                break;
        }
    }
    
    return result;
}

//-------------
if strcmp (string1,string2)==0 then s1 and s2 are equals

if strcmp (string1,string2)>0 then s1 is greater than s2
//-------------

bool lookup(string s)
{
    bool result = false;
    
    //make everything capitized
    for (int i = 0, n = strlen(s); i < n; i++) {
        if (s[i] >= 65 || s[i] <= 90) {
            s[i]+= 32;
        }
    }
    
    //attempt at linear search
    bool result = false;
    for (int i = 0; i < WORDS; i++) {
       //for (int j = 0, n = strlen(s); j < n; j++) {
            do {
                if (strcmp(s, dictionary.words[i].letters) == 0) {
                    result = true;
                }
                else if (strcmp(s, dictionary.words[i].letters) != 0) {
                    result = false;
                }
            } while (result == true);
            if (result == true)
                break;
        //}
    }
    
    return result;
	
//-------------------
    // make everything capitized
    for (int i = 0, n = strlen(s); i < n; i++)
	{
        if (s[i] >= 'a')
            s[i] -= 32;
    }
// ----- ORIGINAL ---- 
        if (strcmp(s, dictionary.words[i].letters) == 0) // if is in dictionary
		{
			if (dictionary.words[i].found == true) // if word is already used
				result = false;
			else
			{
			result = true;
			dictionary.words[i].found = true; // mark word as found
			}
        }
        else if (strcmp(s, dictionary.words[i].letters) != 0) // if not in dictionary
		{
            result = false;
        }

    if ((result == true) || (dictionary.words[i].found == true))
        break;
// -------- END ----- 

//'---- Drow
    for (int row = 0; row < DIMENSION; row++)
        {
            for (int col = 0; col < DIMENSION; col++)
            {
                printf("%c ", grid[row][col]);
                if (col == DIMENSION - 1)
                    printf("\n"); // new line after 4-th column
            }
        }
// ------ END --- 
    for (int row = 0; row < DIMENSION; row++)
        {
            for (int col = 0; col < DIMENSION; col++)
            {
                grid[row][col] = temp[row][col];
                
            }
        }
    for (int row = 0; row < DIMENSION; row++)
        {
            for (int col = 0; col < DIMENSION; col++)
            {
				for (int col1 = (DIMENSION - 1); col1 > 0; col1--)
                temp[row][col] = grid[col1][row];
                
            }
        }		
