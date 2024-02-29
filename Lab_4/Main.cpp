#include "lab_4.h"	//���������� ����������� ������������ ����


int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");


	int choice = 0;
	int SIZE = 0;
	int flag = 0;
	vector <int> arr;	//��-�� �������-�� ���������� vector :)


	input_size_of_arr(arr, SIZE);
	fill_arr(arr, SIZE);
	output(arr, SIZE);


	do {
		cout << "\n\t*���� ���������*\n";
		cout << "1) ����������� ����������\n";
		cout << "2) ��������� (���������) ����������\n";
		cout << "3) ������ ����������\n";
		cout << "4) ���������� ����������\n";
		cout << "5) ���������� ����������\n";
		cout << "6) C��������� ��������\n";
		cout << "7) ����������� ����������\n";
		cout << "8) ���� �����\n";
		cout << "9) ���������� ��������\n";
		cout << "10) ����� �������\n\n";
		cout << "11) ���������� ���������\n\n";
		cout << "\t�������� ������ ������� --> ";	 cin >> choice;		cout << '\n' << '\n';


		switch (choice) {
		case static_cast<int>(MENU::BUBBLE_SORT):		bubble_sort(arr, SIZE);				break;
		case static_cast<int>(MENU::SHAKER_SORT):		shaker_sort(arr, SIZE);				break;
		case static_cast<int>(MENU::DWARVES_SORT):		dwarves_sort(arr, SIZE);			break;
		case static_cast<int>(MENU::INSERTS_SORT):		inserts_sort(arr, SIZE);			break;
		case static_cast<int>(MENU::SELECTION_SORT):	selection_sort(arr, SIZE);			break;
		case static_cast<int>(MENU::SHELL_SORT):		shell_sort(arr, SIZE);				break;
		case static_cast<int>(MENU::RECURSIVE_SORT):	recursive_sort(arr, SIZE);			break;
		case static_cast<int>(MENU::HOARA_SORT):		hoara_sort(arr, SIZE);				break;
		case static_cast<int>(MENU::MERGING_SORT):		merging_sort(arr, SIZE);			break;
		case static_cast<int>(MENU::OUTPUT):			output(arr, SIZE);					break;
		case static_cast<int>(MENU::EXIT):				exit(flag);		system("pause");	break;

		default:	error();	break;
		}
	} while (flag);


	return 0;
}