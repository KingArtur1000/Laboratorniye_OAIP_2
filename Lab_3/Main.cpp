#include "lab_3.h"	//���������� ����������� ������������ ����


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
	vector <int> arr;	//��-�� �������-�� ���������� vector :)


	input_size_of_arr(arr, SIZE);
	fill_arr(arr, SIZE);
	output(arr, SIZE);
	input_searched_value(target);

	const int left = 0;
	const int right = arr.size() - 1;

	do {
		cout << "\n\t*���� ���������*\n";
		cout << "1) �������� �������� ��� ������\n";
		cout << "2) ���������������� �����\n";
		cout << "3) ����� ��������\n";
		cout << "4) ��������-���������������� �����\n";
		cout << "5) �������� ����� (����������� ���������)\n";
		cout << "6) �������� ����� (��������)\n";
		cout << "7) ����� �������\n";
		cout << "8) ���������� ���������\n\n";
		cout << "\t�������� ������ ������� --> ";	 cin >> choice;		cout << '\n' << '\n';


		switch (choice) {
		case static_cast<int>(MENU::INPUT):						input_searched_value(target);													break;
		case static_cast<int>(MENU::INCREMENTAL_SEARCH):		incremental_search(arr, SIZE, target);											break;
		case static_cast<int>(MENU::JUMP_SEARCH):				jump_search(arr, SIZE, target);													break;
		case static_cast<int>(MENU::INDEX_SEQUENTIAL_SEARCH):	index_sequential_search(arr, SIZE, target);										break;
		case static_cast<int>(MENU::BINARY_SEARCH):				binary_search(arr, SIZE, target);												break;
		case static_cast<int>(MENU::BINARY_SEARCH_RECURSIVE):	binary_search_recursive(arr, SIZE, target, left, right, operations, flag_2);	break;
		case static_cast<int>(MENU::OUTPUT):					output(arr, SIZE);																break;
		case static_cast<int>(MENU::EXIT):						exit(flag);		system("pause");												break;

		default:	error();	break;
		}
	} while (flag);


	return 0;
}