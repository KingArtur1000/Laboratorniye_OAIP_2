#include "lab_3.h"	//Подключили собственный заголовочный файл


int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");


	int choice = 0;
	int SIZE = 0;
	int target = 0;
	int operations = 0;
	bool flag = true;
	bool flag_2 = true;
	vector <int> arr;	//Да-да наконец-то используем vector :)


	input_size_of_arr(arr, SIZE);
	fill_arr(arr, SIZE);
	output(arr);
	input_searched_value(target);

	const int left = 0;
	const int right = arr.size() - 1;

	do {
		cout << "\n\t*МЕНЮ ПРОГРАММЫ*\n";
		cout << "1) Изменить значение для поиска\n";
		cout << "2) Последовательный поиск\n";
		cout << "3) Поиск прыжками\n";
		cout << "4) Индексно-последовательный поиск\n";
		cout << "5) Бинарный поиск (циклические операторы)\n";
		cout << "6) Бинарный поиск (рекурсия)\n";
		cout << "7) Вывод массива\n";
		cout << "8) Завершение программы\n\n";
		cout << "\tВыберите нужную функцию --> ";	 cin >> choice;		cout << '\n' << '\n';


		switch (choice) {
		case static_cast<int>(MENU::INPUT):						input_searched_value(target);											break;
		case static_cast<int>(MENU::INCREMENTAL_SEARCH):		incremental_search(arr, target);										break;
		case static_cast<int>(MENU::JUMP_SEARCH):				jump_search(arr, target);												break;
		case static_cast<int>(MENU::INDEX_SEQUENTIAL_SEARCH):	index_sequential_search(arr, target);									break;
		case static_cast<int>(MENU::BINARY_SEARCH):				binary_search(arr, target);												break;
		case static_cast<int>(MENU::BINARY_SEARCH_RECURSIVE):	binary_search_recursive(arr, target, left, right, operations, flag_2);	break;
		case static_cast<int>(MENU::OUTPUT):					output(arr);															break;
		case static_cast<int>(MENU::EXIT):						exit(flag);		system("pause");										break;

		default:	error();	break;
		}
	} while (flag);


	return 0;
}