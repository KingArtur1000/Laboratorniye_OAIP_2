#include "lab_4.h"	//Подключили собственный заголовочный файл


int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");


	int choice = 0;
	int size = 0;
	bool flag = true;
	vector <int> arr_original;	//Да-да наконец-то используем vector :)
	vector <int> arr_sorted;
	Conditions conditions;
	Actions actions;


	input_size_of_arr(size);
	fill_arr(arr_original, arr_sorted, size);
	output(arr_original, arr_sorted, conditions);


	do {
		cout << "\n\t*МЕНЮ ПРОГРАММЫ*\n";
		cout << "1) Пузырьковая сортировка\n";
		cout << "2) Миксерная (шейкерная) сортировка\n";
		cout << "3) Гномья сортировка\n";
		cout << "4) Вставочная сортировка\n";
		cout << "5) Выборочная сортировка\n";
		cout << "6) Cортировка оболочки\n";
		cout << "7) Рекурсивная сортировка\n";
		cout << "8) Сортировка Хоара\n";
		cout << "9) Сортировка слиянием\n";
		cout << "10) Вывод исходного массива\n";
		cout << "11) Завершение программы\n\n";
		cout << "\tВыберите нужную функцию --> ";	 cin >> choice;		cout << '\n' << '\n';


		switch (choice) {
		case static_cast<int>(MENU::BUBBLE_SORT):		bubble_sort(arr_original, arr_sorted, conditions, actions);				break;
		case static_cast<int>(MENU::SHAKER_SORT):		shaker_sort(arr_original, arr_sorted, conditions, actions);				break;
		case static_cast<int>(MENU::DWARVES_SORT):		dwarves_sort(arr_original, arr_sorted, conditions, actions);			break;
		case static_cast<int>(MENU::INSERTS_SORT):		inserts_sort(arr_original, arr_sorted, conditions, actions);			break;
		case static_cast<int>(MENU::SELECTION_SORT):	selection_sort(arr_original, arr_sorted, conditions, actions);			break;
		case static_cast<int>(MENU::SHELL_SORT):		shell_sort(arr_original, arr_sorted, conditions, actions);				break;
		case static_cast<int>(MENU::RECURSIVE_SORT):	recursive_sort_combo(arr_original, arr_sorted, conditions, actions);	break;
		case static_cast<int>(MENU::HOARA_SORT):		hoara_sort_combo(arr_original, arr_sorted, conditions, actions);		break;
		case static_cast<int>(MENU::MERGING_SORT):		merging_sort(arr_original, arr_sorted, conditions, actions);			break;
		case static_cast<int>(MENU::OUTPUT):			output_original(arr_original, arr_sorted, conditions);					break;
		case static_cast<int>(MENU::EXIT):				exit(flag);		system("pause");										break;

		default:	error();	break;
		}
	} while (flag);


	return 0;
}