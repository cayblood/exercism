//
// Created by Carl Youngblood on 2019-05-14.
//

#include "binary_search.h"
#include <stdio.h>

int *binary_search(int to_find, int arr[], int length)
{
    int *returnval = NULL;
    int max = length - 1;
    int min = 0;
    int index = max - (length / 2);

    if (to_find && length > 0) {
        while (arr[index] != to_find) {
            if (arr[index] > to_find) {
                max = index - 1;
            } else {
                min = index + 1;
            }
            if (length < 1) {
                break;
            }
            length = max - min;
            index = max - (length / 2);
        }
        returnval = &arr[index];
    }
    return returnval;
}
