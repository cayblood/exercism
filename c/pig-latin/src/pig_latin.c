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
        case 'u': sprintf(returnval, "%say", phrase);
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
        case 'z': sprintf(returnval, "%s%cay", phrase + sizeof(char), ch);
    }
    if (strncmp("yt", phrase, 2) == 0) {
        sprintf(returnval, "%say", phrase);
    }
    if (strncmp("xr", phrase, 2) == 0) {
        sprintf(returnval, "%say", phrase);
    }
    if (strncmp("th", phrase, 2) == 0) {
        sprintf(returnval, "%sthay", phrase + (sizeof(char) * 2));
    }
    if (strncmp("qu", phrase, 2) == 0) {
        sprintf(returnval, "%squay", phrase + (sizeof(char) * 2));
    }
    if (strncmp("ch", phrase, 2) == 0) {
        sprintf(returnval, "%schay", phrase + (sizeof(char) * 2));
    }
    if (strncmp("rh", phrase, 2) == 0) {
        sprintf(returnval, "%srhay", phrase + (sizeof(char) * 2));
    }
    if (strncmp("thr", phrase, 3) == 0) {
        sprintf(returnval, "%sthray", phrase + (sizeof(char) * 3));
    }
    if (strncmp("squ", phrase, 3) == 0) {
        sprintf(returnval, "%ssquay", phrase + (sizeof(char) * 3));
    }
    if (strncmp("sch", phrase, 3) == 0) {
        sprintf(returnval, "%sschay", phrase + (sizeof(char) * 3));
    }
    return returnval;
}
