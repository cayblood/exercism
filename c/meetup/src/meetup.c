//
// Created by Carl Youngblood on 2019-03-11.
//

#include <time.h>
#include <stdio.h>

int meetup_day_of_month(int year, int month, const char ordinal[], const char day_of_week[])
{
    const char * const days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    struct tm date;
    time_t t;

    date.tm_sec = 1;
    date.tm_min = 1;
    date.tm_hour = 1;
    date.tm_mday = 13;
    date.tm_mon = month;
    date.tm_year = year;
    date.tm_isdst = 0;
    date.tm_zone = "UTC";

    for (int i = 13; i < 20; i++) {
        date.tm_mday = i;
        t = mktime(&date);
        printf("%02d/%02d/%04d was a %s\n", date.tm_mon, date.tm_mday, date.tm_year, days_of_week[date.tm_wday]);
    }

    return 0;
}
