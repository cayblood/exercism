//
// Created by Carl Youngblood on 2019-03-03.
//

#include "hamming.h"
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 256

int compute(char *string1, char *string2)
{
    int hamming_distance = -1;

    if (string1 && string2) {
        int i = 0;
        int length1 = (int)strnlen(string1, MAX_STRING_LENGTH),
            length2 = (int)strnlen(string2, MAX_STRING_LENGTH);

        if (length1 == length2) {
            hamming_distance = 0;
            char letter1, letter2;

            for (; i < length1; i++) {
                letter1 = (char)tolower(string1[i]);
                letter2 = (char)tolower(string2[i]);
                if (letter1 != letter2) {
                    hamming_distance++;
                }
            }
        }
    }
    return hamming_distance;
}
