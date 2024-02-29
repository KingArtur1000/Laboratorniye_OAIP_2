#include "functions_for_sort.h"


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


void recursive_sort(vector<int> arr, int size, bool is_sorted, int index) {
    int min_index = 0;

    // Выводим массив, когда index и size будут одинаковыми
    if (index == size) {
        is_sorted = true;
        output(arr, size, is_sorted);
        return;
    }

    // Вызов функции min_index для получения минимального индекса
    min_index = find_min_index(arr, index, size);

    // Меняем местами, когда индекс и минимальный индекс не совпадают
    if (min_index != index)     swap(arr[min_index], arr[index]);

    // Рекурсивный вызов функции сортировки
    recursive_sort(arr, size, is_sorted, index + 1);
}