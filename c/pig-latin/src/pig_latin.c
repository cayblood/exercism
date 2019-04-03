//
// Created by Youngblood, Carl on 2019-04-02.
//

#include "pig_latin.h"
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include <stdio.h>

char *translate(const char *phrase)
{
    char *returnval = NULL;
    returnval = malloc(sizeof(char) * MAX_STRING);
    char ch = (char)tolower(phrase[0]);
    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': sprintf(returnval, "%say", phrase); break;
        default: break;
    }
    return returnval;
}
