#include <iostream>
#include "functions_for_array.h"


using namespace std;


void input(Parents* parents, const int SIZE) {
	int choice = 0;

	cout << "\t����� ��������� �� ������ ��������?\n";
	cout << "1) Mum\n";
	cout << "2) Dad\n\n";
	cout << "��� ����� --> ";	cin >> choice;	cout << '\n' << '\n';

	if (choice == 1) {
		for (int i = 0; i < SIZE; i++) {
			cout << "\t������� ������ ��� ���� �" << i + 1 << ":\n";
			cout << "������� �������: "; cin >> parents[i].mum.age;
			cout << "������� ���: ";	 cin >> parents[i].mum.name;	cout << '\n';
			parents[i].mum.sex = '�';
		}
	}		
	else if (choice == 2) {
		for (int i = 0; i < SIZE; i++) {
			cout << "\t������� ������ ��� ���� �" << i + 1 << ":\n";
			cout << "������� �������: "; cin >> parents[i].dad.age;
			cout << "������� ���: ";	 cin >> parents[i].dad.name;	cout << '\n';
			parents[i].dad.sex = '�';
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

	cout << "\t������ ������� ������� �������!\n\n";
}


void output(Parents* parents, const int SIZE) {
	int numb = 0;

	cout << "�������� ����� ��������� �� ������ ������� (����� ���������) --> ";	cin >> numb;	cout << '\n';

	if ((parents[numb - 1].dad.age != 0) && (parents[numb - 1].dad.sex == '�')) {
		cout << "\tC�������� �" << numb << ":\n";
		cout << "������� ����: " << parents[numb - 1].dad.age << '\n';
		cout << "��� ����: " << parents[numb - 1].dad.name << '\n';
		cout << "���: " << parents[numb - 1].dad.sex << '\n' << '\n';
	}
	else if ((parents[numb - 1].mum.age != 0) && (parents[numb - 1].mum.sex == '�')) {
		cout << "\tC�������� �" << numb << ":\n";
		cout << "������� ����: " << parents[numb - 1].mum.age << '\n';
		cout << "��� ����: " << parents[numb - 1].mum.name << '\n';
		cout << "���: " << parents[numb - 1].mum.sex << '\n' << '\n';
	}
	else {
		cout << "��������� ��������� �� ���������!\n\n";
	}
	
}


void output_arr(Parents* parents, const int SIZE) {
	bool is_struct_empty = false;
	
	cout << "\t\t������ ��������:\n";

	for (int i = 0; i < SIZE; i++) {
		int numb = i + 1;

		if ((parents[numb - 1].dad.age != 0) && (parents[numb - 1].dad.sex == '�')) {
			cout << "������� ����: " << parents[i].dad.age << '\n';
			cout << "��� ����: " << parents[i].dad.name << '\n';
			cout << "���: " << parents[i].dad.sex << '\n' << '\n';
		}
		else if ((parents[numb - 1].mum.age != 0) && (parents[numb - 1].mum.sex == '�')) {
			cout << "\tC�������� �" << numb << ":\n";
			cout << "������� ����: " << parents[i].mum.age << '\n';
			cout << "��� ����: " << parents[i].mum.name << '\n';
			cout << "���: " << parents[i].mum.sex << '\n' << '\n';
		}
		else {
			is_struct_empty = true;
		}
	}

	if (is_struct_empty)	cout << "�� ���� ��������� �� ���������!\n\n";
}