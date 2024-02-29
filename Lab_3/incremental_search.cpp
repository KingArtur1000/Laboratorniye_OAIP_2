#include "functions_for_search.h"


void incremental_search(vector <int> arr, int target) {
	const int SIZE = arr.size();
	bool is_element_find = false;
	int operations = 0;

	output(arr);

	for (int i = 0; i < SIZE; i++) {
		operations++;

		if (arr.at(i) == target) {
			cout << "Элемент найден! Индекс элемента = " << i << '\n' << '\n';
			cout << "Кол-во сравнений: " << operations << '\n' << '\n';
			is_element_find = true;
		}
	}

	if (!is_element_find) {
		cout << target << " - не найден в массиве!";
	}
}