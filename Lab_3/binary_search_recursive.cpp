#include "functions_for_search.h"


void binary_search_recursive(vector <int> arr, int target, const int &left, const int &right, int &operations, bool &flag_2){
    const int SIZE = arr.size();

    sort(arr.begin(), arr.end());

    if (flag_2) {
        int operations = 0;
        flag_2 = false;
    }

    while (left <= right) {
        int middle = (left + right) / 2;
        operations++;

        if (arr.at(middle) == target) {
            cout << "Элемент " << target << " найден под индексом " << middle << '\n';
            cout << "Кол-во сравнений: " << operations << '\n';
        }

        if (arr.at(middle) < target)
            return binary_search_recursive(arr, target, middle + 1, right, operations, flag_2);
        else
            return binary_search_recursive(arr, target, left, middle - 1, operations, flag_2);
    }
}