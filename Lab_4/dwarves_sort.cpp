#include "functions_for_sort.h"


void dwarves_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    int index = 0;  

    conditions.is_reseted = false;
    reset(arr_original, arr_sorted, conditions);
    
    while (index < arr_sorted.size()) {
        if (index == 0)
            index++;
        if (arr_sorted[index] >= arr_sorted[index - 1])
            index++;
        else {
            swap(arr_sorted[index], arr_sorted[index - 1]);
            index--;
        }
    }

    conditions.is_sorted = true;
    output(arr_original, arr_sorted, conditions);
}