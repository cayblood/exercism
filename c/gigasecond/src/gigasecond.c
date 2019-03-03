//
// Created by Carl Youngblood on 2019-03-03.
//

#include "gigasecond.h"

#define GIGASECOND 1e9

time_t gigasecond_after(time_t starting_time)
{
    return starting_time + (time_t)GIGASECOND;
}
