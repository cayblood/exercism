//
// Created by Youngblood, Carl on 2019-04-21.
//

#include "wordy.h"

#include <string.h>
#include <regex.h>
#include <stdio.h>
#include <inttypes.h>

#define REGEX_PATTERN "^What is (-?[[:digit:]]+) (plus|minus|multiplied by|divided by) (-?[[:digit:]]+)\\?$"
#define REGEX_MAX_MATCHES 7
#define MAX_MATCH_LENGTH 100

bool answer(const char *question, int *result)
{
    regex_t regex;
    regmatch_t pmatch[REGEX_MAX_MATCHES];
    if (regcomp(&regex, REGEX_PATTERN, REG_EXTENDED) == 0) {
        if (regexec(&regex, question, REGEX_MAX_MATCHES, pmatch, 0) == 0) {
            char expression1[MAX_MATCH_LENGTH] = { 0 };
            char expression2[MAX_MATCH_LENGTH] = { 0 };
            char operand1[MAX_MATCH_LENGTH] = { 0 };
            char operand2[MAX_MATCH_LENGTH] = { 0 };
            char operand3[MAX_MATCH_LENGTH] = { 0 };
            char operator1[MAX_MATCH_LENGTH] = { 0 };
            char operator2[MAX_MATCH_LENGTH] = { 0 };
            intmax_t op1, op2, op3, op4;

            strncpy(expression1, question + pmatch[0].rm_so, pmatch[0].rm_eo - pmatch[0].rm_so);
//            strncpy(expression2, question + pmatch[1].rm_so, pmatch[1].rm_eo - pmatch[1].rm_so);
            strncpy(operand1, question + pmatch[1].rm_so, pmatch[1].rm_eo - pmatch[1].rm_so);
            strncpy(operator1, question + pmatch[2].rm_so, pmatch[2].rm_eo - pmatch[2].rm_so);
            strncpy(operand2, question + pmatch[3].rm_so, pmatch[3].rm_eo - pmatch[3].rm_so);
//            strncpy(operator2, question + pmatch[4].rm_so, pmatch[5].rm_eo - pmatch[5].rm_so);
//            strncpy(operand3, question + pmatch[6].rm_so, pmatch[6].rm_eo - pmatch[6].rm_so);

            op1 = strtoimax(operand1, NULL, 10);
            op2 = strtoimax(operand2, NULL, 10);
            if (strcmp(operator1, "plus") == 0) {
                *result = (int)op1 + op2;
            }
            if (strcmp(operator1, "minus") == 0) {
                *result = (int)op1 - op2;
            }
            if (strcmp(operator1, "multiplied by") == 0) {
                *result = (int)op1 * op2;
            }
            if (strcmp(operator1, "divided by") == 0) {
                *result = (int)op1 / op2;
            }
        }
        regfree(&regex);
    }
    return true;
}
