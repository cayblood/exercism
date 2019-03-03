#include <memory.h>
#include <ctype.h>
#include <stdlib.h>

#include "pangram.h"

#define LETTERS_IN_ALPHABET 26

void make_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char)tolower(str[i]);
    }
}

bool all_found(const bool *letters) {
    bool found = true;
    for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
        if (!letters[i]) {
            found = false;
        }
    }
    return found;
}


bool is_pangram(const char *sentence)
{
    bool found = false;

    if (sentence) {
        bool letters[LETTERS_IN_ALPHABET];
        char *copy_of_sentence = NULL;
        char letter;
        int length = strlen(sentence) + 1;
        int i, index;

        copy_of_sentence = (char *)calloc(length, sizeof(char));
        strncpy(copy_of_sentence, sentence, length);
        make_lowercase(copy_of_sentence);
        memset(letters, 0, sizeof(bool) * LETTERS_IN_ALPHABET);

        for (i = 0; i < length; i++) {
            letter = copy_of_sentence[i];
            index = letter - 'a';
            if (index < LETTERS_IN_ALPHABET) {
                letters[index] = true;
            }
        }

        free(copy_of_sentence);
        found = all_found(letters);
    }
    return found;
}
