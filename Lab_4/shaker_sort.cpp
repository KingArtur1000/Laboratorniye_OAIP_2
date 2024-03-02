#include "functions_for_sort.h"



void shaker_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    bool is_swapped = true;
    int start = 0;
    int end = arr_sorted.size() - 1;

    conditions.is_reseted = false;
    reset(arr_original, arr_sorted, conditions);

    while (is_swapped) {
        is_swapped = false;

        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (arr_sorted.at(i) > arr_sorted.at(i + 1)) {
                swap(arr_sorted.at(i), arr_sorted.at(i + 1));
                is_swapped = true;
            }
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
            }
        }

        // Увеличиваем левую границу
        ++start;
    }

    conditions.is_sorted = true;
    output(arr_original, arr_sorted, conditions);
}
