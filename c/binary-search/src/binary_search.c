//
// Created by Carl Youngblood on 2019-05-14.
//

#include "binary_search.h"

int *binary_search(int to_find, int arr[], int length)
{
    int index = length - 1 - (length / 2);
    if (to_find && length > 0) {
        return &arr[index];
    }
    return &arr[0];
}
