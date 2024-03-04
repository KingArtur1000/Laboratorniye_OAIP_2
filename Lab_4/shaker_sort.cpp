#include "functions_for_sort.h"



void shaker_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();

    bool is_swapped = true;
    int start = 0;
    int end = arr_sorted.size() - 1;

    while (is_swapped) {
        is_swapped = false;

        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (arr_sorted.at(i) > arr_sorted.at(i + 1)) {
                swap(arr_sorted.at(i), arr_sorted.at(i + 1));
                is_swapped = true;
                actions.operations++;
               
            }
            actions.operations++;
        }

        if (!is_swapped) // Если не было перестановок, то массив уже отсортирован
            break;

        is_swapped = false;

        // Уменьшаем правую границу
        --end;

        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (arr_sorted.at(i) > arr_sorted.at(i + 1)) {
                swap(arr_sorted.at(i), arr_sorted.at(i + 1));
                is_swapped = true;
                actions.swaps++;
            }
            actions.operations++;
        }

        // Увеличиваем левую границу
        ++start;
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}