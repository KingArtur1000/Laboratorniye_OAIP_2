#include "lab_1.h"	//Подключили собственный заголовочный файл


int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");


	int choice = 0;
	bool flag = true;
	const int SIZE = 5;
	Parents parents[SIZE] = {};


	do {
		cout << "\n\t*МЕНЮ ПРОГРАММЫ*\n";
		cout << "1) Добавление элементов\n";
		cout << "2) Удаление элементов\n";
		cout << "3) Вывод одной структуры\n";
		cout << "4) Вывод массива структур\n";
		cout << "5) Сохранение в файл\n";
		cout << "6) Чтение из файла\n";
		cout << "7) Завершение программы\n\n";
		cout << "\tВыберите нужную функцию --> ";	 cin >> choice;		cout << '\n' << '\n';
		

		switch (choice) {
		case ADDING:		input(parents, SIZE);				break;
		case REMOVING:		remove(parents, SIZE);				break;
		case OUTPUT:		output(parents, SIZE);				break;
		case OUTPUT_ARR:	output_arr(parents, SIZE);			break;
		case SAVING:		saving(parents, SIZE);				break;
		case READING:		reading(parents, SIZE);				break;
		case EXIT:			exit(flag);		system("pause");	break;

		default:			error();	break;
		}
	} while (flag);


	return 0;
}