#include "functions_for_sort.h"


void bubble_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions){
    steady_clock::time_point start_time = start_timer();

    reset(arr_original, arr_sorted, conditions, actions);

    for (int i = 0; i < arr_sorted.size() - 1; i++) {
        for (int j = 0; j < arr_sorted.size() - i - 1; j++) {
            actions.operations++;

            if (arr_sorted.at(j) > arr_sorted.at(j + 1)) {
                swap(arr_sorted.at(j), arr_sorted.at(j + 1));
                actions.swaps++;
            }
        }
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}