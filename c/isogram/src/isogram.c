#include "isogram.h"
#include <memory.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define ASCII_OFFSET 97

bool is_isogram(const char phrase[])
{
    bool returnval = false;
    if (phrase)
    {
        int letters[ALPHABET_SIZE];
        size_t length;
        length = strlen(phrase);
        memset(letters, 0, sizeof(int) * ALPHABET_SIZE);
        char letter;
        int index = 0;

        returnval = true;
        for (size_t i = 0; i < length; ++i)
        {
            letter = (char)tolower(phrase[i]);
            index = letter - ASCII_OFFSET;
            if (isalpha(letter))
            {
                letters[index]++;
                if (letters[index] > 1)
                {
                    returnval = false;
                }
            }
        }
    }
    return returnval;
}
