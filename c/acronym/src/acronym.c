#include "acronym.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ACRONYM_LENGTH 50

char *abbreviate(const char *phrase)
{
    char delimiters[] = " -";
    char *token = NULL;
    char *copy = NULL;
    char *acronym = NULL;
    if (phrase && strcmp(phrase, "") != 0)
    {
        int i = 0;
        acronym = calloc(MAX_ACRONYM_LENGTH, sizeof(char));

        copy = strdup(phrase);
        token = strtok(copy, delimiters);
        while (token)
        {
            acronym[i++] = (char)toupper(token[0]);
            token = strtok(NULL, delimiters);
        }
        free(copy);
    }
    return acronym;
}
