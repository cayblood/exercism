//
// Created by Youngblood, Carl on 2019-03-20.
//

#include "beer_song.h"

#define MAX_NUMBER 10

void capitalize(char *buffer)
{
    buffer[0] = (char)toupper(buffer[0]);
}

void format_bottles(char *buffer, int count)
{
    const char phrase1[] = "%s bottle%s of beer";
    char number[MAX_NUMBER] = "";
    char plural[2] = "";

    if (count == -1) {
        count = 99;
    }
    if (count == 0) {
        strcpy(number, "no more");
    } else {
        sprintf(number, "%d", count);
    }
    if (count == 1) {
        strcpy(plural, "");
    } else {
        strcpy(plural, "s");
    }
    sprintf(buffer, phrase1, number, plural);
}

void verse(char *response, int beer_count)
{
    const char preposition[] = "on the wall";
    const char phrase2[] = "Take %s down and pass it around";
    const char phrase3[] = "Go to the store and buy some more";
    char bottles[MAX_STRING] = "";
    char bottles_after[MAX_STRING] = "";
    char capitalized_bottles[MAX_STRING] = "";
    char middle[MAX_STRING] = "";

    if (beer_count == 0) {
        strcpy(middle, phrase3);
    } else {
        sprintf(middle, phrase2, beer_count == 1 ? "it" : "one");
    }
    format_bottles(bottles, beer_count);
    format_bottles(bottles_after, beer_count - 1);
    format_bottles(capitalized_bottles, beer_count);
    capitalize(capitalized_bottles);

    sprintf(response, "%s %s, %s.\n%s, %s %s.\n", capitalized_bottles, preposition, bottles, middle, bottles_after, preposition);
}

void sing(char *response, int start, int end)
{
    memset(response, 0, MAX_STRING);
    char verse_buffer[MAX_STRING] = "";

    for (int i = start; i >= end; i--) {
        verse(verse_buffer, i);
        strcat(response, verse_buffer);
        if (i == end) {
            break;
        }
        strcat(response, "\n");
    }
}
