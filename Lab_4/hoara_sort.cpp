#include "functions_for_sort.h"


void hoara_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions, int begin, int end) {
    int i = begin;
    int j = end;
    int pivot = arr_sorted.at((begin + end) / 2); // Выбор опорного элемента посередине вектора

    do {
        // Поиск элемента в левой части, который больше или равен опорному
        while (arr_sorted.at(i) < pivot) {
            i++;
            actions.operations++;
        }   

        // Поиск элемента в правой части, который меньше или равен опорному
        while (arr_sorted.at(j) > pivot) {
            j--;
            actions.operations++;
        }   

        // Производим обмен элементов
        if (i <= j) {
            if (i < j) {
                swap(arr_sorted.at(i), arr_sorted.at(j));
                actions.swaps++;
            }    
            i++;
            j--;
        }
    } while (i <= j);

    // Рекурсивный вызов для сортировки правой части вектора
    if (i < end) {
        hoara_sort(arr_original, arr_sorted, conditions, actions, i, end);
    }

    // Рекурсивный вызов для сортировки левой части вектора
    if (begin < j) {
        hoara_sort(arr_original, arr_sorted, conditions, actions, begin, j);
    }
}


void hoara_sort_combo(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();
    hoara_sort(arr_original, arr_sorted, conditions, actions, 0, (arr_sorted.size() - 1));
    steady_clock::time_point end_time = end_timer();

    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}