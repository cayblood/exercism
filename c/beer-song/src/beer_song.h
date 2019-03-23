//
// Created by Youngblood, Carl on 2019-03-20.
//

#ifndef BEERSONG_BEER_SONG_H
#define BEERSONG_BEER_SONG_H

#define MAX_NUMBER 10
#define MAX_STRING 1024

#include <memory.h>
#include <stdio.h>
#include <ctype.h>

void verse(char *response, int beer_count);
void sing(char *response, int start, int end);

#endif //BEERSONG_BEER_SONG_H
