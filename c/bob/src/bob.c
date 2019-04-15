//
// Created by Youngblood, Carl on 2019-04-13.
//

#include "bob.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char response[MAX_RESPONSE] = "";

bool all_caps(const char *text)
{
    bool all_caps = true;
    bool has_alpha = false;
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            has_alpha = true;
        }
        if (toupper(text[i]) != text[i]) {
            all_caps = false;
            break;
        }
    }
    return all_caps && has_alpha;
}

bool is_blank(const char *text)
{
    int length = strlen(text);
    bool is_blank = true;
    for (int i = 0; i < length; i++) {
        if (!isblank(text[i])) {
            is_blank = false;
            break;
        }
    }
    return is_blank;
}

void stripright(char *text)
{
    int length = strlen(text);
    for (int i = length - 1; i >= 0; i--) {
        if (!(isblank(text[i]) || text[i] == '\r' || text[i] == '\n')) {
            break;
        }
        text[i] = '\0';
    }
}

const char *hey_bob(const char *text)
{
    char buffer[MAX_RESPONSE] = "";
    strcpy(buffer, text);
    stripright(buffer);
    strcpy(response, "Whatever.");
    if (all_caps(buffer)) {
        strcpy(response, "Whoa, chill out!");
    }
    if (buffer[strlen(buffer) - 1] == '?') {
        strcpy(response, "Sure.");
    }
    if (all_caps(buffer) && text[strlen(buffer) - 1] == '?') {
        strcpy(response, "Calm down, I know what I'm doing!");
    }
    if (is_blank(buffer)) {
        strcpy(response, "Fine. Be that way!");
    }
    return response;
}
