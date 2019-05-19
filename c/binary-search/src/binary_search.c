//
// Created by Carl Youngblood on 2019-05-14.
//

#include "binary_search.h"
#include <stdio.h>

int *binary_search(int to_find, int arr[], int length)
{
    int *to_return = NULL;
    int max = length - 1;
    int min = 0;
    int index = max - (length / 2);

    if (to_find && length > 0) {
        int current_val = arr[index];

        while (current_val != to_find) {
            if (current_val > to_find) {
                max = index - 1;
            } else {
                min = index + 1;
            }
            length = max - min;
            index = max - (length / 2);
            current_val = arr[index];
            if (length < 1) {
                break;
            }
        }
        if (current_val == to_find) {
            to_return = &arr[index];
        }
    }
    return to_return;
}
