//
// Created by Carl Youngblood on 2019-03-28.
//

#include "leap.h"

bool is_leap_year(unsigned int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
