#include "functions_for_sort.h"


void selection_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();
    
    for (int i = 0; i < arr_sorted.size() - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < arr_sorted.size(); j++) {
            if (arr_sorted.at(j) < arr_sorted.at(min_index)) {
                min_index = j;
                actions.operations++;
            }
        }

        swap(arr_sorted.at(i), arr_sorted.at(min_index));
        actions.swaps++;
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}
