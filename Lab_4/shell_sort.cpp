#include "functions_for_sort.h"


void shell_sort(vector<int> arr, int size, bool is_sorted) {
    for (int step = size / 2; step > 0; step /= 2) {
        for (int i = step; i < size; i++) {
            for (int j = i; (j >= step) && (arr.at(j - step) > arr.at(j)); j -= step) {
                swap(arr[j], arr[j - step]);
            }
        }
    }

    is_sorted = true;

    output(arr, size, is_sorted);
}