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