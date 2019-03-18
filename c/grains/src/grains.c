//
// Created by Carl Youngblood on 2019-03-06.
//

#include "grains.h"

#define BOARD_SQUARE_COUNT 64

uint64_t square(int n)
{
    uint64_t returnval = 0;
    if (n > 0 && n <= BOARD_SQUARE_COUNT) {
        returnval = (uint64_t)pow(2, (double)n - 1);
    }
    return returnval;
}

uint64_t total()
{
    return 18446744073709551615ull;
}
