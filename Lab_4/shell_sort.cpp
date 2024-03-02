#include "functions_for_sort.h"


void shell_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    conditions.is_reseted = false;
    reset(arr_original, arr_sorted, conditions);
    
    for (int step = arr_sorted.size() / 2; step > 0; step /= 2) {
        for (int i = step; i < arr_sorted.size(); i++) {
            for (int j = i; (j >= step) && (arr_sorted.at(j - step) > arr_sorted.at(j)); j -= step) {
                swap(arr_sorted[j], arr_sorted[j - step]);
            }
        }
    }

    conditions.is_sorted = true;
    output(arr_original, arr_sorted, conditions);
}