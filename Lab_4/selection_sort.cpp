#include "functions_for_sort.h"


void selection_sort(vector<int> arr, int size, bool is_sorted) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (arr.at(j) < arr.at(min_index)) {
                min_index = j;
            }
        }

        swap(arr.at(i), arr.at(min_index));
    }

    is_sorted = true;

    output(arr, size, is_sorted);
}