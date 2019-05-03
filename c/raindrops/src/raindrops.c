//
// Created by Youngblood, Carl on 2019-05-01.
//

#include "raindrops.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 256

void convert(char *result, int drops)
{
    bool has_factor = false;
    char tempstr[MAX_STRING_LENGTH] = "";

    if (drops % 3 == 0) {
        strcat(tempstr, "Pling");
        has_factor = true;
    }
    if (drops % 5 == 0) {
        strcat(tempstr, "Plang");
        has_factor = true;
    }
    if (drops % 7 == 0) {
        strcat(tempstr, "Plong");
        has_factor = true;
    }
    if (has_factor) {
        strcpy(result, tempstr);
    } else {
        sprintf(result, "%d", drops);
    }
}
