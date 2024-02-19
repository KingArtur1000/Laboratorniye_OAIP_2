#include "functions_for_array.h"


void input(Parents* parents, const int SIZE) {
	int choice = 0;
	fstream file_1("D:\\Programming\\C++\\Laboratorniye_OAIP_2\\Lab_1_1\\mums_data.txt");
	fstream file_2("D:\\Programming\\C++\\Laboratorniye_OAIP_2\\Lab_1_1\\dads_data.txt");
	string str = "";

	cout << "\tКакую структуру вы хотите добавить?\n";
	cout << "1) Mum\n";
	cout << "2) Dad\n";
	cout << "3) Я случайно сюда забрел... Выпустите меня (^-^)\n\n";
	cout << "Ваш выбор --> ";	cin >> choice;	cout << '\n' << '\n';

	if (choice == 1) {
		cout << "\tКак заполняем данные?\n";
		cout << "1) Вручную\n";
		cout << "2) По умолчанию из файла\n";
		cout << "\n\tВаш выбор --> ";	cin >> choice;	cout << '\n' << '\n';

		if (choice == 1) {
			for (int i = 0; i < SIZE; i++) {
				cout << "\tВведите данные для мамы №" << i + 1 << ":\n";
				cout << "Введите возраст: "; cin >> parents[i].mum.age;		cin.clear(); cin.ignore();
				cout << "Введите ФИО: ";	 cin.getline(parents[i].mum.name, sizeof(parents[i].mum.name));	cout << '\n';
				parents[i].mum.sex = 'Ж';
			}
		}
		else if (choice == 2) {
			cout << "\t\tСодержимое данного файла:\n\n";
			if (file_1.is_open()) {
				for (int i = 0; i < SIZE; i++) {
					getline(file_1, str);		
					parents[i].mum.age = atoi(str.c_str());

					getline(file_1, str);
					strcpy_s(parents[i].mum.name, sizeof(parents[i].mum.name), str.c_str());

					parents[i].mum.sex = 'Ж';
				}
				cout << "\tДанные успещно внесены!\n";
			}
			else { cout << "\tНе удалось открыть файл!\n\n"; }
		}
	}
	else if (choice == 2) {
		cout << "\tКак заполняем данные?\n";
		cout << "1) Вручную\n";
		cout << "2) По умолчанию из файла\n";
		cout << "\n\tВаш выбор --> ";	cin >> choice;	cout << '\n' << '\n';

		if (choice == 1) {
			for (int i = 0; i < SIZE; i++) {
				cout << "\tВведите данные для папы №" << i + 1 << ":\n";
				cout << "Введите возраст: "; cin >> parents[i].dad.age;		cin.clear(); cin.ignore();
				cout << "Введите ФИО: ";	 cin.getline(parents[i].dad.name, sizeof(parents[i].dad.name));	cout << '\n';
				parents[i].dad.sex = 'М';
			}
		}
		else if (choice == 2) {
			if (file_2.is_open()) {
				for (int i = 0; i < SIZE; i++) {
					getline(file_2, str);
					parents[i].dad.age = atoi(str.c_str());

					getline(file_2, str);
					strcpy_s(parents[i].dad.name, sizeof(parents[i].dad.name), str.c_str());

					parents[i].dad.sex = 'М';
				}
				cout << "\tДанные успещно внесены!\n\n";
			}
			else { cout << "\tНе удалось открыть файл!\n"; }
		}
	}
	else if (choice == 3) cout << "Выпускаю :)\n\n";
	else error();
}


void remove(Parents* parents, const int SIZE) {
	int choice = 0;

	cout << "\tВы уверены, что хотите что-то удалить?\n";
	cout << "1) ДА, я уверен, что хочу удалить кое-какие данные!\n";
	cout << "2) НЕТ, я вообще случайно сюда забрел... Выпустите меня (^-^)\n\n";
	cout << "\tВаш выбор --> ";		cin >> choice;	cout << '\n' << '\n';

	if (choice == 1) {
		cout << "\tХорошо, что будем удалять?\n";
		cout << "1) Удалить данные одной некоторой структуры\n";
		cout << "2) Удалить данные всего массива\n";
		cout << "3) Промазал с кнопкой, выпусти пожалуйста отсюда...\n\n";
		cout << "\tВаш выбор --> ";		cin >> choice;	cout << '\n' << '\n';

		if (choice == 1) {
			int i = choice - 1;

			cout << "\tВведите номер структуры (от 1 до 5)\n";
			cout << "Ваш выбор --> ";	cin >> choice;	 cout << '\n' << '\n';

			parents[i].mum.age = 0;
			strcpy_s(parents[i].mum.name, sizeof(parents[i].mum.name), "");

			parents[i].dad.age = 0;
			strcpy_s(parents[i].dad.name, sizeof(parents[i].dad.name), "");

			cout << "\tСтруктура #" << choice << " успешно удалена!\n\n";
		}
		else if (choice == 2) {
			for (int i = 0; i < SIZE; i++) {
				parents[i].mum.age = 0;
				strcpy_s(parents[i].mum.name, sizeof(parents[i].mum.name), "");

				parents[i].dad.age = 0;
				strcpy_s(parents[i].dad.name, sizeof(parents[i].dad.name), "");
			}
			cout << "\tДанные массива успешно удалены!\n\n";
		}
		else if (choice == 3) cout << "Выпускаю :)\n\n";
		else error();
	}
	else if (choice == 2) cout << "Выпускаю :)\n\n";
	else error();
}


void output(Parents* parents, const int SIZE) {
	int choice = 0;
	int numb = 0;


	cout << "\tВы уверены, что хотите вывести данные одной структуры?\n";
	cout << "1) ДА, я уверен, что хочу вывести данные одной структуры!\n";
	cout << "2) НЕТ, я вообще случайно сюда забрел... Выпустите меня (^-^)\n\n";
	cout << "\tВаш выбор --> ";		cin >> choice;	cout << '\n' << '\n';


	if (choice == 1) {
		cout << "Выберите какую структуру вы хотите вывести (номер структуры) --> ";	cin >> numb;	cout << '\n';

		if ((parents[numb - 1].dad.age != 0) && (parents[numb - 1].dad.sex == 'М')) {
			cout << "\tCтруктура №" << numb << ":\n";
			cout << "Возраст папы: " << parents[numb - 1].dad.age << '\n';
			cout << "ФИО папы: " << parents[numb - 1].dad.name << '\n';
			cout << "Пол: " << parents[numb - 1].dad.sex << '\n' << '\n';
		}
		else if ((parents[numb - 1].mum.age != 0) && (parents[numb - 1].mum.sex == 'Ж')) {
			cout << "\tCтруктура №" << numb << ":\n";
			cout << "Возраст мамы: " << parents[numb - 1].mum.age << '\n';
			cout << "ФИО мамы: " << parents[numb - 1].mum.name << '\n';
			cout << "Пол: " << parents[numb - 1].mum.sex << '\n' << '\n';
		}
		else {
			cout << "Выбранная структура не заполнена!\n\n";
		}
	}
	else if (choice == 2) cout << "Выпускаю :)\n\n";
	else error();
}


void output_arr(Parents* parents, const int SIZE) {
	int choice = 0;
	bool is_struct_empty = false;
	

	cout << "\tВы уверены, что хотите вывести данные массива?\n";
	cout << "1) ДА, я уверен, что хочу вывести данные массива!\n";
	cout << "2) НЕТ, я вообще случайно сюда забрел... Выпустите меня (^-^)\n\n";
	cout << "\tВаш выбор --> ";		cin >> choice;	cout << '\n' << '\n';


	if (choice == 1) {
		cout << "\t\tМассив структур:\n";

		for (int i = 0; i < SIZE; i++) {
			int numb = i + 1;

			if ((parents[numb - 1].dad.age != 0) && (parents[numb - 1].dad.sex == 'М')) {
				cout << "Возраст папы: " << parents[i].dad.age << '\n';
				cout << "ФИО папы: " << parents[i].dad.name << '\n';
				cout << "Пол: " << parents[i].dad.sex << '\n' << '\n';
			}
			else if ((parents[numb - 1].mum.age != 0) && (parents[numb - 1].mum.sex == 'Ж')) {
				cout << "\tCтруктура №" << numb << ":\n";
				cout << "Возраст мамы: " << parents[i].mum.age << '\n';
				cout << "ФИО мамы: " << parents[i].mum.name << '\n';
				cout << "Пол: " << parents[i].mum.sex << '\n' << '\n';
			}
			else {
				is_struct_empty = true;
			}
		}

		if (is_struct_empty)	cout << "Ни одна структура не заполнена!\n\n";
	}
	else if (choice == 2) cout << "Выпускаю :)\n\n";
	else error();
}