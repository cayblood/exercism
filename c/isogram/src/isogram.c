#include "isogram.h"
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
        int letters[ALPHABET_SIZE] = { 0 };
        int length = (int)strnlen(phrase, MAX_STRING_LENGTH);
        char letter;
        int index = 0, i = 0;

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
