#include "functions_for_sort.h"


// Функция для слияния двух отсортированных подмассивов [left, middle] и [middle+1, right] в один отсортированный массив arr[left, right]
void merge(vector<int>& arr, int left, int middle, int right) {
    // Вычисляем размеры двух подмассивов
    int size1 = middle - left + 1;
    int size2 = right - middle;

    // Создаем временные массивы для хранения левого и правого подмассивов
    vector<int> left_arr(size1), right_arr(size2);

    // Копируем данные из основного массива во временные массивы
    for (int i = 0; i < size1; i++)
        left_arr.at(i) = arr.at(left + i);
    for (int j = 0; j < size2; j++)
        right_arr.at(j) = arr.at(middle + 1 + j);

    // Индексы для обхода левого, правого и основного массивов
    int i = 0, j = 0, k = left;

    // Слияние двух временных массивов в один основной массив
    while (i < size1 && j < size2) {
        if (left_arr.at(i) <= right_arr.at(j)) {
            arr.at(k) = left_arr.at(i);
            i++;
        }
        else {
            arr.at(k) = right_arr.at(j);
            j++;
        }
        k++;
    }

    // Дописываем оставшиеся элементы из левого временного массива, если такие есть
    while (i < size1) {
        arr.at(k) = left_arr.at(i);
        i++;
        k++;
    }

    // Дописываем оставшиеся элементы из правого временного массива, если такие есть
    while (j < size2) {
        arr.at(k) = right_arr.at(j);
        j++;
        k++;
    }
}


// Функция сортировки слиянием
void merging_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    int current_size = 0;
    int left_start = 0;
    int end_element = static_cast<int>(arr_sorted.size() - 1);  //Чтобы функция min не выпендривалась :) (а то unsigned int нельзя)

    conditions.is_reseted = false;
    reset(arr_original, arr_sorted, conditions);

    // Цикл по подмассивам заданного размера
    for (current_size = 1; current_size <= arr_sorted.size() - 1; current_size = 2 * current_size) {
        // Цикл по подмассивам текущего размера
        for (left_start = 0; left_start < arr_sorted.size() - 1; left_start += 2 * current_size) {
            // Находим середину и конец правого подмассива
            int middle = min((left_start + current_size - 1), end_element);
            int right_end = min(left_start + 2 * current_size - 1, end_element);

            // Вызываем функцию слияния для текущих подмассивов
            merge(arr_sorted, left_start, middle, right_end);
        }
    }

    conditions.is_sorted = true;
    output(arr_original, arr_sorted, conditions);
}