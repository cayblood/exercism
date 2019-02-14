#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word_count.h"

#define NOT_FOUND -1

void make_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char)tolower(str[i]);
    }
}

int get_word_index(const char *word, word_count_word_t *words) {
    int index = NOT_FOUND;
    int i = 0;
    while (i < MAX_WORDS) {
        if (strcmp(word, words[i].text) == 0) {
            index = i;
        }
        i++;
    }
    return index;
}

int get_next_empty_index(word_count_word_t *words) {
    int i = 0;
    while (strnlen(words[i].text, MAX_WORD_LENGTH) > 0) {
        i++;
    }
    return i;
}

void increment_word_count(const char *word, word_count_word_t *words) {
    int index = get_word_index(word, words);
    strncpy(words[index].text, word, MAX_WORD_LENGTH + 1);
    words[index].count++;
}

void add_word(const char *word, word_count_word_t *words) {
    int index = get_next_empty_index(words);
    strncpy(words[index].text, word, MAX_WORD_LENGTH + 1);
    words[index].count = 1;
}

bool word_has_quotes(const char *word) {
    return word[0] == '\'' && word[strnlen(word, MAX_WORD_LENGTH) - 1] == '\'';
}

int word_count(const char *input_text, word_count_word_t *words) {
    char delimeters[] = " .,!@$%^&:\n";
    char *token = NULL;
    char word[MAX_WORD_LENGTH + 1] = "";
    char *input_copy = NULL;
    int count = 0;
    int unique_words = 0;
    size_t length = 0;

    memset(word, 0, sizeof(char) * (MAX_WORD_LENGTH + 1));
    memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);
    input_copy = strdup(input_text);
    token = strtok(input_copy, delimeters);
    while (token) {
        strncpy(word, token, MAX_WORD_LENGTH + 1);
        make_lowercase(word);
        length = strnlen(word, MAX_WORD_LENGTH + 1);
        if (length == MAX_WORD_LENGTH + 1) {
            unique_words = EXCESSIVE_LENGTH_WORD;
            break;
        }
        if (unique_words > MAX_WORDS)                                   /* too many words */
        {
            unique_words = EXCESSIVE_NUMBER_OF_WORDS;
            break;
        }
        if (length > 0) {
            count++;
            if (get_word_index(word, words) == NOT_FOUND)               /* new word */
            {
                int index = 0;
                if (word_has_quotes(word)) {
                    index++;
                    word[strnlen(word, MAX_WORD_LENGTH + 1) - 1] = '\0';
                }
                add_word(word + index, words);
                unique_words++;
            } else                                                     /* existing word */
            {
                increment_word_count(word, words);
            }
        }
        token = strtok(NULL, delimeters);
    }
    free(input_copy);
    return unique_words;
}
