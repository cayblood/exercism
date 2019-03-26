//
// Created by Carl Youngblood on 2019-03-25.
//

#include "nucleotide_count.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *count(const char *dna_strand)
{
    int a = 0, c = 0, g = 0, t = 0;
    char *response = calloc(MAX_STRING, sizeof(char));
    char bit = ' ';
    bool valid_dna = true;
    int length = (int)strlen(dna_strand);

    for (int i = 0; i < length; i++) {
        bit = dna_strand[i];
        if (bit != 'G' && bit != 'C' && bit != 'T' && bit != 'A') {
            valid_dna = false;
        }
    }

    if (valid_dna) {
        for (int i = 0; i < length; i++) {
            switch (dna_strand[i]) {
                case 'A': a++; break;
                case 'C': c++; break;
                case 'G': g++; break;
                case 'T': t++; break;
                default: break;
            }
        }
        sprintf(response, "A:%d C:%d G:%d T:%d", a, c, g, t);
    }

    return response;
}
