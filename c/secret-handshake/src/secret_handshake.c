//
// Created by Youngblood, Carl on 2019-04-12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secret_handshake.h"

#define REVERSE_ORDER 16


struct Command {
    unsigned int code;
    const char *word;
};

struct Command cmds[] = {
    { 1, "wink" },
    { 2, "double blink" },
    { 4, "close your eyes" },
    { 8, "jump" }
};


void add_indexed_command_to_list_at_offset(const char **returnval, int index, int offset)
{
    char *p = (char *)(returnval + COMMAND_COUNT) + (offset * MAX_COMMAND_LENGTH);
    strcpy(p, cmds[index].word);
    returnval[offset] = p;
}


const char **commands(unsigned int n)
{
    const char **returnval = NULL;
    int offset = 0;

    returnval = calloc(COMMAND_COUNT, MAX_COMMAND_LENGTH);
    if (n) {
        if (n & REVERSE_ORDER) {
            for (int i = COMMAND_COUNT - 1; i >= 0; i--) {
                if (n & cmds[i].code) {
                    add_indexed_command_to_list_at_offset(returnval, i, offset++);
                }
            }
        } else {
            for (int i = 0; i < COMMAND_COUNT; i++) {
                if (n & cmds[i].code) {
                    add_indexed_command_to_list_at_offset(returnval, i, offset++);
                }
            }
        }
    }
    return returnval;
}
