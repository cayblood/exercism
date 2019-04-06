//
// Created by Youngblood, Carl on 2019-04-02.
//

#include "pig_latin.h"
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include <stdio.h>

#define VOWEL_COUNT 5
#define CONSONANT_COUNT 21
#define PREFIX_COUNT 7

char *translate_word(const char *wrd, char *dest)
{
    const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
    const char consonants[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's',
                                't', 'v', 'w', 'x', 'y', 'z' };
    const char *prefixes[] = {"th", "qu", "ch", "rh", "thr", "squ", "sch" };
    char ch = (char)tolower(wrd[0]);

    for (int i = 0; i < VOWEL_COUNT; i++) {
        if (ch == vowels[i]) {
            sprintf(dest, "%say", wrd);
        }
    }

    for (int i = 0; i < CONSONANT_COUNT; i++) {
        if (ch == consonants[i]) {
            sprintf(dest, "%s%cay", wrd + sizeof(char), ch);
        }
    }

    for (int i = 0; i < PREFIX_COUNT; i++) {
        if (strncmp(prefixes[i], wrd, strlen(prefixes[i])) == 0) {
            sprintf(dest, "%s%say", wrd + (sizeof(char) * strlen(prefixes[i])), prefixes[i]);
        }
    }

    if (strncmp("yt", wrd, 2) == 0) {
        sprintf(dest, "%say", wrd);
    }

    if (strncmp("xr", wrd, 2) == 0) {
        sprintf(dest, "%say", wrd);
    }

    return dest;
}

char *translate(const char *phrase)
{
    char *returnval = calloc(strlen(phrase) + 1, sizeof(char));
    char translation[MAX_WORD] = { 0 };
    char tokenizable_string[MAX_STRING] = { 0 };
    strcpy(tokenizable_string, phrase);
    for (char *wrd = strtok(tokenizable_string, " "); wrd; wrd = strtok(NULL, " ")) {
        if (strlen(returnval) > 0) {
            strcat(returnval, " ");
        }
        translate_word(wrd, translation);
        strcat(returnval, translation);
    }
    return returnval;
}
