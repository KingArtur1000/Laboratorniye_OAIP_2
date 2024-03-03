#include "functions_for_sort.h"


void shell_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    steady_clock::time_point start_time = start_timer();

    reset(arr_original, arr_sorted, conditions, actions);
    
    for (int step = arr_sorted.size() / 2; step > 0; step /= 2) {
        for (int i = step; i < arr_sorted.size(); i++) {
            for (int j = i; (j >= step) && (arr_sorted.at(j - step) > arr_sorted.at(j)); j -= step) {
                swap(arr_sorted[j], arr_sorted[j - step]);
                actions.swaps++;
                actions.operations++;
            }
        }
    }
    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}