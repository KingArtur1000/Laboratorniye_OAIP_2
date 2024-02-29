#include "functions_for_sort.h"


void inserts_sort(vector<int> arr, int size, bool is_sorted) {
    int key = 0;
    
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    is_sorted = true;

    output(arr, size, is_sorted);
}