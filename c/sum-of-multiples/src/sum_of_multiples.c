//
// Created by Carl Youngblood on 2019-05-20.
//

#include "sum_of_multiples.h"

int sum_of_multiples(const unsigned int multiples[], int count, int max)
{
    int sum = 0;
    for (int i = 0; i < count; i++) {
        int j = 1;
        int multiple = j * multiples[i];
        while (multiple < max) {
            sum += multiple;
            multiple = ++j * multiples[i];
        }
    }
    return sum;
}
