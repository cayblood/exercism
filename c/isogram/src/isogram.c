#include "isogram.h"
#include <memory.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define ASCII_OFFSET 97
#define MAX_STRING_LENGTH 256

bool is_isogram(const char phrase[])
{
    bool returnval = false;
    if (phrase)
    {
        int letters[ALPHABET_SIZE];
        int length = (int)strnlen(phrase, MAX_STRING_LENGTH);
        char letter;
        int index = 0, i = 0;

        memset(letters, 0, sizeof(int) * ALPHABET_SIZE);
        returnval = true;

        for (; i < length; i++)
        {
            letter = (char)tolower(phrase[i]);
            index = letter - ASCII_OFFSET;
            if (isalpha(letter))
            {
                letters[index]++;
                if (letters[index] > 1)
                {
                    returnval = false;
                    break;
                }
            }
        }
    }
    return returnval;
}
