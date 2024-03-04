#include "functions_for_sort.h"


void dwarves_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();

    int index = 0;
    
    while (index < arr_sorted.size()) {
        if (index == 0)
            index++;
        if (arr_sorted[index] >= arr_sorted[index - 1]) {
            index++;
            actions.operations++;
        }    
        else {
            swap(arr_sorted[index], arr_sorted[index - 1]);
            index--;
            actions.swaps++;
        }
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}