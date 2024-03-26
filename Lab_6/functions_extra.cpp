#include "functions_extra.h"


void exit(bool& flag) {
	cout << "\tВыходим...\n";
	flag = false;
}


void error() {
	cout << "Неверный выбор! Напишите только ЦИФРУ вашего выбора (без скобки)\n\n";
}