//
// Created by Carl Youngblood on 2019-05-20.
//

#include <stdbool.h>
#include "sum_of_multiples.h"

bool multiple_already_included(const unsigned int multiples[], int index, int multiple)
{
    bool included = false;
    for (int i = 0; i < index; i++) {
        if (multiple % multiples[i] == 0) {
            included = true;
            break;
        }
    }
    return included;
}

int sum_of_multiples(const unsigned int multiples[], int count, int max)
{
    int sum = 0;
    if (multiples) {
        for (int i = 0; i < count; i++) {
            int j = 1;
            int multiple = j * multiples[i];
            while (multiple > 0 && multiple < max) {
                if (!multiple_already_included(multiples, i, multiple)) {
                    sum += multiple;
                }
                multiple = ++j * multiples[i];
            }
        }
    }
    return sum;
}
