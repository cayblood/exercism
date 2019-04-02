//
// Created by Carl Youngblood on 2019-03-30.
//

#include "bracket_push.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STACK_SIZE 50

typedef struct
{
    int max_size;
    int top;
    char *items;
} Stack;

Stack* initialize(int size)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->max_size = size;
    p->top = -1;
    p->items = (char *)malloc(sizeof(char) * size);
    return p;
}

int size(Stack *p)
{
    return p->top + 1;
}

bool is_empty(Stack *p)
{
    return p->top == -1;
}

bool is_full(Stack *p)
{
    return p->top == p->max_size - 1;
}

void push(Stack *p, char item)
{
    if (is_full(p)) {
        printf("OverFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    p->items[++p->top] = item;
}

char peek(Stack *p)
{
    return p->items[p->top];
}

char pop(Stack *p)
{
    if (is_empty(p)) {
        printf("UnderFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
    return p->items[p->top--];
}

void cleanup(Stack *p)
{
    free(p->items);
    free(p);
}

char opposite_of(char ch) {
    char returnval = ' ';
    if (ch == ']') returnval = '[';
    if (ch == ')') returnval = '(';
    if (ch == '}') returnval = '{';
    return returnval;
}

bool is_paired(const char *input)
{
    int length = (int)strlen(input);
    Stack *s = initialize(MAX_STACK_SIZE);
    bool returnval;
    bool mismatch = false;

    for (int i = 0; i < length; i++) {
        char ch = input[i];
        if (ch == '[' || ch == '{' || ch == '(') {
            push(s, ch);
        } else {
            if ((ch == ']' || ch == '}' || ch == ')') && size(s) > 0) {
                if (peek(s) != opposite_of(ch)) {
                    mismatch = true;
                } else {
                    pop(s);
                }
            }
        }
    }

    returnval = is_empty(s) && !mismatch;
    cleanup(s);
    return returnval;
}
