//
// Created by Youngblood, Carl on 2019-05-10.
//

#include "two_fer.h"
#include <string.h>
#include <stdio.h>

void two_fer(char *response, const char *name)
{
    strcpy(response, "One for you, one for me.");
    if (name) {
        sprintf(response, "One for %s, one for me.", name);
    }
}
