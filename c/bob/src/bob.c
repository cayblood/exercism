//
// Created by Youngblood, Carl on 2019-04-13.
//

#include "bob.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char response[MAX_RESPONSE] = "Whatever.";

bool contains_successive_caps(const char *text)
{
    bool has_caps = false;
    int length = strlen(text);
    for (int i = 1; i < length; i++) {
        if (isalpha(text[i]) && toupper(text[i - 1]) == text[i - 1] && toupper(text[i]) == text[i]) {
            has_caps = true;
            break;
        }
    }
    return has_caps;
}

const char *hey_bob(const char *text)
{
    if (text[strlen(text) - 1] == '!' || contains_successive_caps(text)) {
        strcpy(response, "Whoa, chill out!");
    }
    if (text[strlen(text) - 1] == '?') {
        strcpy(response, "Sure.");
    }
    return response;
}
