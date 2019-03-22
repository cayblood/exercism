//
// Created by Youngblood, Carl on 2019-03-20.
//

#include <memory.h>
#include <stdio.h>

#define MAX_STRING 256

void verse(char *response, int beer_count)
{
    const char phrase1[] = "%d bottle%s of beer";
    const char phrase2[] = "Take one down and pass it around";
    const char phrase3[] = "on the wall";
    const char phrase4[] = "Go to the store and buy some more";
    const char template[] = "%s on the wall, %s.\n%s, %s on the wall.";
    char before[MAX_STRING] = "";
    char after[MAX_STRING] = "";

    sprintf(before, phrase1, beer_count, beer_count > 1 ? "s" : "");
    sprintf(after, phrase1, beer_count - 1, beer_count - 1 > 1 ? "s" : "");
    sprintf(response, "%s %s, %s.\n%s, %s %s.\n", before, phrase3, before, phrase2, after, phrase3);
}

void sing(char *response, int start, int end)
{
    // test
    strcpy(response, "");
}