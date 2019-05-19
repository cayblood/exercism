//
// Created by Carl Youngblood on 2019-05-14.
//

#include "binary_search.h"

int *binary_search(int to_find, int arr[], int length)
{
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
            length = max - min;
            index = max - (length / 2);
        }
        return &arr[index];
    }
    return &arr[0];
}
