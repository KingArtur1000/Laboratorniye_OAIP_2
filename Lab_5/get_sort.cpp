#include "functions_for_sorting.h"

// Функция для получения указателя на функцию сортировки
void (*get_sort_function())(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
    int choice = 0;

    cout << "\n\tВыберите нужную функцию сортировки:" << '\n';
    cout << "\t1. Сортировка пузырьком" << '\n';
    cout << "\t2. Шейкерная сортировка" << '\n';
    cout << "\t3. Гномья сортировка" << '\n';
    cout << "\t4. Сортировка вставками" << '\n';
    cout << "\t5. Сортировка выбором" << '\n';
    cout << "\t6. Сортировка Шелла" << '\n';
    cout << "\t7. Рекурсивная сортировка" << '\n';
    cout << "\t8. Сортировка Хоара" << '\n';
    cout << "\t9. Сортировка слиянием" << '\n';
    cout << "\tВаш выбор --> ";    cin >> choice;   cout << '\n';

    // Массив указателей на функции сортировки
    void (*sort_functions[])(vector<int>&arr_original, vector<int>&arr_sorted, Conditions & conditions, Actions & actions) = {
        bubble_sort,
        shaker_sort,
        dwarves_sort,
        inserts_sort,
        selection_sort,
        shell_sort,
        recursive_sort_combo,
        hoara_sort_combo,
        merging_sort
    };

    int num_sort_functions = sizeof(sort_functions) / sizeof(sort_functions[0]);

    if (choice > 0 && choice <= num_sort_functions) {
        return sort_functions[choice - 1];
    }
    else {
        cout << "Неверный ввод. Перезапустите программу!\n";
        return dwarves_sort;
    }
}


// typedef
typedef void (*sort_function_typedef)(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);

sort_function_typedef get_sort_function_typedef() {
    int choice = 0;

    cout << "\n\tВыберите нужную функцию сортировки:" << '\n';
    cout << "\t1. Сортировка пузырьком" << '\n';
    cout << "\t2. Шейкерная сортировка" << '\n';
    cout << "\t3. Гномья сортировка" << '\n';
    cout << "\t4. Сортировка вставками" << '\n';
    cout << "\t5. Сортировка выбором" << '\n';
    cout << "\t6. Сортировка Шелла" << '\n';
    cout << "\t7. Рекурсивная сортировка" << '\n';
    cout << "\t8. Сортировка Хоара" << '\n';
    cout << "\t9. Сортировка слиянием" << '\n';
    cout << "\tВаш выбор --> ";    cin >> choice;   cout << '\n';

    // Массив указателей на функции сортировки
    void (*sort_functions[])(vector<int>&arr_original, vector<int>&arr_sorted, Conditions & conditions, Actions & actions) = {
        bubble_sort,
        shaker_sort,
        dwarves_sort,
        inserts_sort,
        selection_sort,
        shell_sort,
        recursive_sort_combo,
        hoara_sort_combo,
        merging_sort
    };

    int num_sort_functions = sizeof(sort_functions) / sizeof(sort_functions[0]);

    if (choice > 0 && choice <= num_sort_functions) {
        return sort_functions[choice - 1];
    }
    else {
        cout << "Неверный ввод. Перезапустите программу!\n";
        return dwarves_sort;
    }
}


//using
using sort_function_using = void (*)(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);

sort_function_using get_sort_function_using() {
    int choice = 0;

    cout << "\n\tВыберите нужную функцию сортировки:" << '\n';
    cout << "\t1. Сортировка пузырьком" << '\n';
    cout << "\t2. Шейкерная сортировка" << '\n';
    cout << "\t3. Гномья сортировка" << '\n';
    cout << "\t4. Сортировка вставками" << '\n';
    cout << "\t5. Сортировка выбором" << '\n';
    cout << "\t6. Сортировка Шелла" << '\n';
    cout << "\t7. Рекурсивная сортировка" << '\n';
    cout << "\t8. Сортировка Хоара" << '\n';
    cout << "\t9. Сортировка слиянием" << '\n';
    cout << "\tВаш выбор --> ";    cin >> choice;   cout << '\n';

    // Массив указателей на функции сортировки
    void (*sort_functions[])(vector<int>&arr_original, vector<int>&arr_sorted, Conditions & conditions, Actions & actions) = {
        bubble_sort,
        shaker_sort,
        dwarves_sort,
        inserts_sort,
        selection_sort,
        shell_sort,
        recursive_sort_combo,
        hoara_sort_combo,
        merging_sort
    };

    int num_sort_functions = sizeof(sort_functions) / sizeof(sort_functions[0]);

    if (choice > 0 && choice <= num_sort_functions) {
        return sort_functions[choice - 1];
    }
    else {
        cout << "Неверный ввод. Перезапустите программу!\n";
        return dwarves_sort;
    }
}