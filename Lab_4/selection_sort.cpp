#include "functions_for_sort.h"


void selection_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    
    conditions.is_reseted = false;
    reset(arr_original, arr_sorted, conditions);
    
    for (int i = 0; i < arr_sorted.size() - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < arr_sorted.size(); j++) {
            if (arr_sorted.at(j) < arr_sorted.at(min_index)) {
                min_index = j;
            }
        }

        swap(arr_sorted.at(i), arr_sorted.at(min_index));
    }

    conditions.is_sorted = true;
    output(arr_original, arr_sorted, conditions);
}
