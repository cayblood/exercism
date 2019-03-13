//
// Created by Carl Youngblood on 2019-03-11.
//

#include <time.h>
#include <stdio.h>
#include <memory.h>

#define THIRTEENTH 12
#define TWENTIETH 19
#define DAYS_IN_WEEK 7
#define MAX_DAYS_IN_MONTH 31
#define MAX_ORDINAL 5

const char * const DAYS_OF_WEEK[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char * const ORDINALS[] = {"first", "second", "third", "fourth", "fifth"};

int get_index_for_day(const char day_of_week[])
{
    int returnval = -1;
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        if (strcmp(DAYS_OF_WEEK[i], day_of_week) == 0) {
            returnval = i;
        }
    }
    return returnval;
}

int get_index_for_ordinal(const char ordinal[])
{
    int returnval = -1;
    for (int i = 0; i < MAX_ORDINAL; i++) {
        if (strcmp(ORDINALS[i], ordinal) == 0) {
            returnval = i;
        }
    }
    return returnval;
}

void set_date(int month, int day, int year, struct tm *date)
{
    date->tm_sec = 0;
    date->tm_min = 0;
    date->tm_hour = 0;
    date->tm_mday = day;
    date->tm_mon = month;
    date->tm_year = year;
    date->tm_isdst = 0;
    date->tm_zone = "UTC";
}

int meetup_day_of_month(int year, int month, const char ordinal[], const char day_of_week[])
{
    int returnval = -1;
    struct tm date;
    time_t t;
    int desired_day = get_index_for_day(day_of_week);

    if (strcmp(ordinal, "teenth") == 0) {
        for (int i = THIRTEENTH; i < TWENTIETH; i++) {
            set_date(month - 1, i, year, &date);
            t = mktime(&date);
            if (date.tm_wday == desired_day) {
                returnval = i + 1;
                break;
            }
        }
    } else {
        int desired_ordinal = get_index_for_ordinal(ordinal);
        int times_seen = 0;
        for (int i = 0; i < MAX_DAYS_IN_MONTH; i++) {
            set_date(month - 1, i, year, &date);
            t = mktime(&date);
            if (date.tm_wday == desired_day) {
                if (times_seen == desired_ordinal) {
                    returnval = i + 1;
                    break;
                }
                times_seen++;
            }
        }
    }

    return returnval;
}
