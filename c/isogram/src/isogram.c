#include "isogram.h"
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define ASCII_OFFSET 97

void make_lowercase(char *dest, const char *src)
{
    int i = 0;
    while (src[i]) {
        dest[i] = (char)tolower(src[i]);
        i++;
    }
}

bool is_isogram(const char phrase[])
{
    bool returnval = false;
    if (phrase)
    {
        int letters[ALPHABET_SIZE];
        size_t length;
        length = strlen(phrase);
        memset(letters, 0, sizeof(int) * ALPHABET_SIZE);
        char *lowercase = (char *)calloc(length, sizeof(char));
        int index = 0;

        returnval = true;
        make_lowercase(lowercase, phrase);

        for (int i = 0; i < length; ++i)
        {
            index = lowercase[i] - ASCII_OFFSET;
            if (index >= 0 && index < ALPHABET_SIZE)
            {
                letters[index]++;
                if (letters[index] > 1)
                {
                    returnval = false;
                }
            }
        }

        free(lowercase);
    }
    return returnval;
}