#include "functions_for_sort.h"


void dwarves_sort(vector<int> arr, int size, bool is_sorted) {
    int index = 0;  
    
    while (index < size) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }

    is_sorted = true;

    output(arr, size, is_sorted);
}