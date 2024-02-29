#include "functions_for_search.h"


void index_sequential_search(vector<int> arr, int target) {
    const int SIZE = arr.size();
    int operations = 0;
    int step = 0;
    int block_index = 0;
    int start_index = 0;
    int end_index = 0;
    vector<int> index_table;

    sort(arr.begin(), arr.end());

    //Выводим отсортированный массив (для наглядности)
    output(arr);

    //Запрашиваем шаг у пользователя:
    cout << "Введите шаг --> ";  cin >> step;   cout << '\n';

    // Проходим по основному массиву данных с шагом и заполняем индексную таблицу
    for (int i = 0; i < SIZE; i += step) {
        index_table.push_back(arr[i]);
    }

    // Определяем блок, в котором должен находиться ключ
    for (int i = 0; i < index_table.size(); i++) {
        if (index_table[i] <= target) {
            block_index = i;
        }
        else {
            break; // Как только текущий индекс в индексном массиве становится больше ключа, прекращаем поиск
        }
    }
    cout << "block index = " << block_index << '\n';

    //Задаем начальную и конечную точки поиска
    start_index = block_index * step;
    end_index = min<int>(start_index + step, SIZE);

    // Перебираем элементы внутри блока
    for (int j = start_index; j < end_index; j++) {
        operations++; // Увеличиваем счетчик сравнений
        if (arr[j] == target) {
            cout << "Элемент " << target << " найден по индексу " << j << '\n';
            cout << "Кол-во сравнений: " << operations << '\n';
            return;
        }
    }

    cout << "Элемент " << target << " не найден" << '\n';
    cout << "Кол-во сравнений: " << operations << '\n'; // Выводим количество сравнений
}