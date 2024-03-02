#include "functions_for_sort.h"


void hoara_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions, int begin, int end) {
    int i = begin;
    int j = end;
    int pivot = arr_sorted.at((begin + end) / 2); // Выбор опорного элемента посередине вектора

    do {
        // Поиск элемента в левой части, который больше или равен опорному
        while (arr_sorted.at(i) < pivot)
            i++;

        // Поиск элемента в правой части, который меньше или равен опорному
        while (arr_sorted.at(j) > pivot)
            j--;

        // Производим обмен элементов
        if (i <= j) {
            if (i < j)
                swap(arr_sorted.at(i), arr_sorted.at(j));
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
    conditions.is_sorted = true;
    conditions.is_reseted = false;
    reset(arr_original, arr_sorted, conditions);

    hoara_sort(arr_original, arr_sorted, conditions, actions, 0, (arr_sorted.size() - 1));

    output(arr_original, arr_sorted, conditions);
}