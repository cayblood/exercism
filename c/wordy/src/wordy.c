//
// Created by Youngblood, Carl on 2019-04-21.
//

#include "wordy.h"

#include <string.h>
#include <regex.h>
#include <stdio.h>
#include <inttypes.h>

#define REGEX_PATTERN "\AWhat is (\d+) (\w+) (\d+)?\Z"
#define REGEX_EXPECTED_MATCHES 4

bool answer(const char *question, int *result)
{
    regex_t regex;
    regmatch_t pmatch[REGEX_EXPECTED_MATCHES];
    if (regcomp(&regex, "^What is ([[:digit:]]+) ([[:alpha:]]+) ([[:digit:]]+)?", REG_EXTENDED) == 0) {
        if (regexec(&regex, question, REGEX_EXPECTED_MATCHES, pmatch, 0) == 0) {
            char operand1[10] = { 0 };
            char operator[10] = { 0 };
            char operand2[10] = { 0 };
            uintmax_t op1, op2;

            strncpy(operand1, question + pmatch[1].rm_so, pmatch[1].rm_eo - pmatch[1].rm_so);
            strncpy(operator, question + pmatch[2].rm_so, pmatch[2].rm_eo - pmatch[2].rm_so);
            strncpy(operand2, question + pmatch[3].rm_so, pmatch[3].rm_eo - pmatch[3].rm_so);

            op1 = strtoumax(operand1, NULL, 10);
            op2 = strtoumax(operand2, NULL, 10);
            *result = (int)op1 + op2;
        }
        regfree(&regex);
    }
    return true;
}
