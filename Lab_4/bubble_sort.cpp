#include "functions_for_sort.h"


void bubble_sort(vector<int> arr, int size, bool is_sorted) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr.at(j) > arr.at(j + 1)) {
                swap(arr.at(j), arr.at(j + 1));
            }
        }
    }

    is_sorted = true;

    output(arr, size, is_sorted);
}