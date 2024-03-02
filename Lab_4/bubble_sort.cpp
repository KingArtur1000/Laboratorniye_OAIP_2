#include "functions_for_sort.h"


void bubble_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions){
    conditions.is_reseted = false;
    reset(arr_original, arr_sorted, conditions);

    for (int i = 0; i < arr_sorted.size() - 1; i++) {
        for (int j = 0; j < arr_sorted.size() - i - 1; j++) {
            if (arr_sorted.at(j) > arr_sorted.at(j + 1)) {
                swap(arr_sorted.at(j), arr_sorted.at(j + 1));
            }
        }
    }

    conditions.is_sorted = true;
    output(arr_original, arr_sorted, conditions);
}