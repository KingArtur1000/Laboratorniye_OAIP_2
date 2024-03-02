#include "functions_extra.h"

void exit(bool& flag) {
	cout << "\tЗавершение программы...\n";
	flag = false;
}


void error() {
	cout << "Неверный выбор! Напишите только ЦИФРУ вашего выбора (без скобки)\n\n";
}


void reset(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions) {
	if (!conditions.is_reseted) {
		conditions.is_reseted = true;
		arr_sorted = arr_original;
	}
}