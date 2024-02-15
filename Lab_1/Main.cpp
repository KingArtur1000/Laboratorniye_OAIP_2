#include <iostream>
#include <string>
#include <cmath>	//��� �������� �� ��������������� ( floor() )
#include "lab_1.h"	//���������� ����������� ������������ ����


int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");


	int choice = 0;
	bool flag = true;
	const int SIZE = 2;
	Parents parents[SIZE];


	do {
		cout << "\t*���� ���������*\n";
		cout << "1) ���������� ���������\n";
		cout << "2) �������� ���������\n";
		cout << "3) ����� ����� ���������\n";
		cout << "4) ����� ������� ��������\n";
		cout << "5) ���������� � ����\n";
		cout << "6) ������ �� �����\n";
		cout << "7) ���������� ���������\n\n";
		cout << "\t�������� ������ ������� --> ";	 cin >> choice;		cout << '\n';
		

		switch (choice) {
		case ADDING:		input(parents, SIZE);		break;
		case REMOVING:		remove(parents, SIZE);		break;
		case OUTPUT:		output(parents, SIZE);		break;
		case OUTPUT_ARR:	output_arr(parents, SIZE);	break;
		case SAVING:		saving(parents, SIZE);		break;
		case READING:		reading(parents, SIZE);		break;
		case EXIT:			flag = false;				break;
		}

	} while (flag);


	return 0;
}