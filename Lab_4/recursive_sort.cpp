﻿#include "functions_for_sort.h"


int find_min_index(vector<int> arr, int begin, int end)
{
    int min_index = begin; // Предполагаем, что минимальный элемент - это arr[i]

    // Идем по оставшимся элементам и обновляем min_index, если находим элемент меньше текущего минимального
    for (int k = begin + 1; k < end; k++) {
        if (arr[k] < arr[min_index]) {
            min_index = k;
        }
    }

    return min_index;
}


void recursive_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions, int index) {
    int min_index = 0;
  

    // Выводим массив, когда index и size будут одинаковыми
    if (index == arr_sorted.size()) {
        return;
    }

    // Вызов функции min_index для получения минимального индекса
    min_index = find_min_index(arr_sorted, index, arr_sorted.size());

    // Меняем местами, когда индекс и минимальный индекс не совпадают
    if (min_index != index)     swap(arr_sorted[min_index], arr_sorted[index]);

    // Рекурсивный вызов функции сортировки
    recursive_sort(arr_original, arr_sorted, conditions, actions, index + 1);
}


void recursive_sort_combo(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions);

    recursive_sort(arr_original, arr_sorted, conditions, actions, 0);
    conditions.is_sorted = true;
    conditions.is_reseted = false;
    output(arr_original, arr_sorted, conditions);
}