//
// Created by Youngblood, Carl on 2019-03-23.
//

#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>

char *to_rna(const char *dna)
{
    int length = (int)strlen(dna);
    char *rna = NULL;
    char bit = ' ';
    bool valid_dna = true;

    for (int i = 0; i < length; i++) {
        bit = dna[i];
        if (bit != 'G' && bit != 'C' && bit != 'T' && bit != 'A') {
            valid_dna = false;
        }
    }

    if (valid_dna) {
        rna = calloc((size_t)length + 1, sizeof(char));
        for (int i = 0; i < length; i++) {
            switch (dna[i]) {
                case 'G': rna[i] = 'C'; break;
                case 'C': rna[i] = 'G'; break;
                case 'T': rna[i] = 'A'; break;
                case 'A': rna[i] = 'U'; break;
            }
        }
    }
    return rna;
}
