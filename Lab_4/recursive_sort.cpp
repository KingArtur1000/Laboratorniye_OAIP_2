#include "functions_for_sort.h"


void recursive_sort(vector<int>& arr_original, vector<int>& arr_sorted, int left, int right, Conditions& conditions, Actions& actions) {
    int pivot; // разрешающий элемент
    int index; // индекс разрешающего элемента
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = arr_sorted.at(left);

    // пока границы не сомкнутся
    while (left < right) {
        while ((arr_sorted.at(right) > pivot) && (left < right)) {
            actions.operations++; // увеличиваем счетчик сравнений
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        }

        // если границы не сомкнулись
        if (left != right) {
            arr_sorted.at(left) = arr_sorted.at(right); // перемещаем элемент [right] на место разрешающего
            actions.swaps++; // увеличиваем счетчик перестановок
            left++; // сдвигаем левую границу вправо
        }

        while ((arr_sorted.at(left) < pivot) && (left < right)) {
            actions.operations++; // увеличиваем счетчик сравнений
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        }

        // если границы не сомкнулись
        if (left != right) {
            arr_sorted.at(right) = arr_sorted.at(left); // перемещаем элемент [left] на место [right]
            actions.swaps++; // увеличиваем счетчик перестановок
            right--; // сдвигаем правую границу влево
        }
    }

    arr_sorted.at(left) = pivot; // ставим разрешающий элемент на место
    index = left;
    left = l_hold;
    right = r_hold;

    if (left < index) // Рекурсивно вызываем сортировку для левой и правой части массива
        recursive_sort(arr_original, arr_sorted, left, index - 1, conditions, actions);
    if (right > index)
        recursive_sort(arr_original, arr_sorted, index + 1, right, conditions, actions);
}


void recursive_sort_combo(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();
    recursive_sort(arr_original, arr_sorted, 0, arr_original.size() - 1, conditions, actions);
    steady_clock::time_point end_time = end_timer();

    actions.time = duration_time(start_time, end_time);

    conditions.is_sorted = true;
    output(arr_original, arr_sorted, conditions, actions);
}