#include "functions_for_sort.h"


void inserts_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    steady_clock::time_point start_time = start_timer();

    int key = 0;

    conditions.is_reseted = false;
    reset(arr_original, arr_sorted, conditions, actions);
    
    for (int i = 1; i < arr_sorted.size(); i++)
    {
        int key = arr_sorted[i];
        int j = i - 1;

        while (j >= 0 && arr_sorted[j] > key)
        {
            arr_sorted[j + 1] = arr_sorted[j];
            j--;

            actions.operations++;
            actions.swaps++;
        }
        arr_sorted[j + 1] = key;
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}