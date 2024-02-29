#include "functions_for_search.h"


void binary_search(vector <int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int middle = 0;
    int operations = 0;
    bool flag = false;
    const int SIZE = arr.size();


    sort(arr.begin(), arr.end());

    output(arr);

    while ((left <= right) && (flag != true)) {
        middle = (left + right) / 2;        // считываем серединный индекс отрезка
        operations++;

        if (arr[middle] == target) flag = true;         //проверяем ключ (искомое значение) со серединным элементом
        if (arr[middle] > target) right = middle - 1;       // проверяем, какую часть нужно отбросить
        else left = middle + 1;
    }

    if (flag) {
        cout << "Найден элемент " << target << " под индексом " << middle << '\n';
        cout << "Кол-во сравнений: " << operations << '\n' << '\n';
    } 
    else cout << "Элемент " << target <<  " НЕ был найден!\n\n";
}