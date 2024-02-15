#include <iostream>
#include "functions_for_array.h"


using namespace std;


void input(Parents* parents, const int SIZE) {
	int choice = 0;

	cout << "\tКакую структуру вы хотите добавить?\n";
	cout << "1) Mum\n";
	cout << "2) Dad\n\n";
	cout << "Ваш выбор --> ";	cin >> choice;	cout << '\n' << '\n';

	if (choice == 1) {
		for (int i = 0; i < SIZE; i++) {
			cout << "\tВведите данные для мамы №" << i + 1 << ":\n";
			cout << "Введите возраст: "; cin >> parents[i].mum.age;
			cout << "Введите ФИО: ";	 cin >> parents[i].mum.name;	cout << '\n';
			parents[i].mum.sex = 'Ж';
		}
	}		
	else if (choice == 2) {
		for (int i = 0; i < SIZE; i++) {
			cout << "\tВведите данные для папы №" << i + 1 << ":\n";
			cout << "Введите возраст: "; cin >> parents[i].dad.age;
			cout << "Введите ФИО: ";	 cin >> parents[i].dad.name;	cout << '\n';
			parents[i].dad.sex = 'М';
		}
	}
}


void remove(Parents* parents, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		parents[i].mum.age = 0;
		parents[i].mum.name = "\0";
		parents[i].dad.age = 0;
		parents[i].dad.name = "\0";
	}

	cout << "\tДанные массива успешно удалены!\n\n";
}


void output(Parents* parents, const int SIZE) {
	int numb = 0;

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


void output_arr(Parents* parents, const int SIZE) {
	bool is_struct_empty = false;
	
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