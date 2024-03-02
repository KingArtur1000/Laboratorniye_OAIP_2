#include "functions_for_sort.h"


void inserts_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    int key = 0;

    conditions.is_reseted = false;
    reset(arr_original, arr_sorted, conditions);
    
    for (int i = 1; i < arr_sorted.size(); i++)
    {
        int key = arr_sorted[i];
        int j = i - 1;

        while (j >= 0 && arr_sorted[j] > key)
        {
            arr_sorted[j + 1] = arr_sorted[j];
            j--;
        }
        arr_sorted[j + 1] = key;
    }

    conditions.is_sorted = true;
    output(arr_original, arr_sorted, conditions);
}