#include "functions_for_search.h"


void incremental_search(vector <int> arr, int SIZE, int target) {
	bool is_element_find = false;
	int operations = 0;

	for (int i = 0; i < SIZE; i++) {
		operations++;

		if (arr.at(i) == target) {
			cout << "������� ������! ������ �������� = " << i << '\n' << '\n';
			cout << "���-�� ���������: " << operations << '\n' << '\n';
			is_element_find = true;
		}
	}

	if (!is_element_find) {
		cout << target << " - �� ������ � �������!";
	}
}