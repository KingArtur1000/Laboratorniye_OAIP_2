#include "functions_for_sorting.h"


void bubble_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();

    for (int i = 0; i < arr_sorted.size() - 1; i++) {
        for (int j = 0; j < arr_sorted.size() - i - 1; j++) {
            actions.operations++;

            if (arr_sorted.at(j) > arr_sorted.at(j + 1)) {
                swap(arr_sorted.at(j), arr_sorted.at(j + 1));
                actions.swaps++;
            }
        }
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}


void dwarves_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();

    int index = 0;

    while (index < arr_sorted.size()) {
        if (index == 0)
            index++;
        if (arr_sorted[index] >= arr_sorted[index - 1]) {
            index++;
            actions.operations++;
        }
        else {
            swap(arr_sorted[index], arr_sorted[index - 1]);
            index--;
            actions.swaps++;
        }
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}


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


void inserts_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();

    int key = 0;

    for (int i = 1; i < arr_sorted.size(); i++)
    {
        int key = arr_sorted[i];
        int j = i - 1;

        while (j >= 0 && arr_sorted[j] > key)
        {
            arr_sorted[j + 1] = arr_sorted[j];
            j--;

            actions.operations++;
            actions.swaps++;
        }
        arr_sorted[j + 1] = key;
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}


// Функция для слияния двух отсортированных подмассивов [left, middle] и [middle+1, right] в один отсортированный массив arr[left, right]
void merge(vector<int>& arr, int left, int middle, int right, Actions& actions) {
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
        actions.operations++;
        if (left_arr.at(i) <= right_arr.at(j)) {
            arr.at(k) = left_arr.at(i);
            i++;
            actions.swaps++;
        }
        else {
            arr.at(k) = right_arr.at(j);
            j++;
            actions.swaps++;
        }
        k++;
    }

    // Дописываем оставшиеся элементы из левого временного массива, если такие есть
    while (i < size1) {
        arr.at(k) = left_arr.at(i);
        i++;
        k++;
        actions.swaps++;
    }

    // Дописываем оставшиеся элементы из правого временного массива, если такие есть
    while (j < size2) {
        arr.at(k) = right_arr.at(j);
        j++;
        k++;
        actions.swaps++;
    }
}


// Функция сортировки слиянием
void merging_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();

    int current_size = 0;
    int left_start = 0;
    int end_element = static_cast<int>(arr_sorted.size() - 1);  //Чтобы функция min не выпендривалась :) (а то unsigned int нельзя)

    // Цикл по подмассивам заданного размера
    for (current_size = 1; current_size <= arr_sorted.size() - 1; current_size = 2 * current_size) {
        // Цикл по подмассивам текущего размера
        for (left_start = 0; left_start < arr_sorted.size() - 1; left_start += 2 * current_size) {
            // Находим середину и конец правого подмассива
            int middle = min((left_start + current_size - 1), end_element);
            int right_end = min(left_start + 2 * current_size - 1, end_element);

            // Вызываем функцию слияния для текущих подмассивов
            merge(arr_sorted, left_start, middle, right_end, actions);
        }
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = start_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}


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


void selection_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();

    for (int i = 0; i < arr_sorted.size() - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < arr_sorted.size(); j++) {
            if (arr_sorted.at(j) < arr_sorted.at(min_index)) {
                min_index = j;
                actions.operations++;
            }
        }

        swap(arr_sorted.at(i), arr_sorted.at(min_index));
        actions.swaps++;
    }

    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}


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


void shell_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    reset(arr_original, arr_sorted, conditions, actions);

    steady_clock::time_point start_time = start_timer();

    for (int step = arr_sorted.size() / 2; step > 0; step /= 2) {
        for (int i = step; i < arr_sorted.size(); i++) {
            for (int j = i; (j >= step) && (arr_sorted.at(j - step) > arr_sorted.at(j)); j -= step) {
                swap(arr_sorted[j], arr_sorted[j - step]);
                actions.swaps++;
                actions.operations++;
            }
        }
    }
    conditions.is_sorted = true;

    steady_clock::time_point end_time = end_timer();
    actions.time = duration_time(start_time, end_time);

    output(arr_original, arr_sorted, conditions, actions);
}