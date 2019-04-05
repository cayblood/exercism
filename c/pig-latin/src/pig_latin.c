//
// Created by Youngblood, Carl on 2019-04-02.
//

#include "pig_latin.h"
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include <stdio.h>

char *translate_word(const char *wrd, char *dest)
{
    char ch = (char)tolower(wrd[0]);
    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': sprintf(dest, "%say", wrd);
        default:;
    }
    switch (ch) {
        case 'b':
        case 'c':
        case 'd':
        case 'f':
        case 'g':
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z': sprintf(dest, "%s%cay", wrd + sizeof(char), ch);
        default:;
    }
    if (strncmp("yt", wrd, 2) == 0) {
        sprintf(dest, "%say", wrd);
    }
    if (strncmp("xr", wrd, 2) == 0) {
        sprintf(dest, "%say", wrd);
    }
    if (strncmp("th", wrd, 2) == 0) {
        sprintf(dest, "%sthay", wrd + (sizeof(char) * 2));
    }
    if (strncmp("qu", wrd, 2) == 0) {
        sprintf(dest, "%squay", wrd + (sizeof(char) * 2));
    }
    if (strncmp("ch", wrd, 2) == 0) {
        sprintf(dest, "%schay", wrd + (sizeof(char) * 2));
    }
    if (strncmp("rh", wrd, 2) == 0) {
        sprintf(dest, "%srhay", wrd + (sizeof(char) * 2));
    }
    if (strncmp("thr", wrd, 3) == 0) {
        sprintf(dest, "%sthray", wrd + (sizeof(char) * 3));
    }
    if (strncmp("squ", wrd, 3) == 0) {
        sprintf(dest, "%ssquay", wrd + (sizeof(char) * 3));
    }
    if (strncmp("sch", wrd, 3) == 0) {
        sprintf(dest, "%sschay", wrd + (sizeof(char) * 3));
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
