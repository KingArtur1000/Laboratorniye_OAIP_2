#include "functions_extra.h"


void exit(bool& flag) {
	cout << "\tЗавершение программы...\n";
	flag = false;
}


void error() {
	cout << "Неверный выбор! Напишите только ЦИФРУ вашего выбора (без скобки)\n\n";
}


void reset(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions) {
	conditions.is_reseted = false;
	actions.operations = 0;
	actions.swaps = 0;
	actions.time = 0;

	if (!conditions.is_reseted) {
		conditions.is_reseted = true;
		arr_sorted = arr_original;
	}
}


// Функция начинает отсчет времени
steady_clock::time_point start_timer() {
	return steady_clock::now();
}

// Функция заканчивает отсчет времени
steady_clock::time_point end_timer() {
	return steady_clock::now();
}

// Функция считает разницу во времени
long duration_time(steady_clock::time_point start, steady_clock::time_point end) {
	return duration_cast<microseconds>(end - start).count();
}