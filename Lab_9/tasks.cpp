#include "tasks.h"


template<typename T> void input(const char* msg, T &var) {
	cout << msg; cin >> var; cout << '\n';
	cout << "���� ����������: " << var << '\n' << '\n';
}


string input(const char* msg, string &str) {
	cin.clear(); cin.ignore();
	cout << msg; getline(cin, str); cout << '\n';
	cout << "���� ������: " << str << '\n' << '\n';
	return str;
}


vector<int> input(const char* msg, vector<int> &arr) {
	try {
		string str = "";

		cin.clear(); cin.ignore();

		for (int i = 0; i < arr.size(); i++) {

			cout << msg; getline(cin, str); cout << '\n';

			// ��������� ������ ������ ������ �� ���������������
			for (int j = 0; j < str.size(); j++) {
				if ( !isdigit(str.at(j)) ) {
					throw str;
				}
			}

			arr.at(i) = atoi(str.c_str());
		}

		cout << '\n';
	}
	catch (int el) {
		cout << el << " - ��� �� ������������� ��������!\n\n";
	}
	catch (char symbol) {
		cout << symbol << " - ��� �� ������������� ��������!\n\n";
	}
	catch (string str) {
		cout << str << " - ��� �� ������������� ��������!\n\n";
	}

	return arr;
}


double divide(double a, double b) {
	try {
		if (b == 0) {
			throw "������� �� ���� ����������!\n";
		}
	}
	catch (const char *msg) {
		cout << msg << '\n';
	}

	return (a / b);
}


void task1() {
	int numb = 0;
	string str = "";

	try {
		int choice = 0;

		cout << "\t��� �� ������ �������?\n\n";
		cout << "1) ������ ������ ������\n";
		cout << "2) ������ ������ � �����\n";
		cout << "��� ����� --> "; cin >> choice; cout << '\n';
		cin.clear(); cin.ignore();

		switch (choice) {
		case 1: throw 1; break;
		case 2: throw 2; break;
		default: error(); break;
		}
	}
	catch (int choice) {
		switch (choice) {
		case 1:
			str = input("������� ������ --> ", str);
			break;
		case 2:	
			str = input("������� ������ --> ", str);
			input("������� ����� --> ", numb);
			break;
		default: error(); break;
		}
	}
}


void task2() {
	int numb = 0;

	try {
		input("������� �����(�� 0 �� 7 ������������)-- > ", numb);

		if (numb >= 0 && numb <= 7) {
			cout << numb << " - ������ ����� �� ���������!\n\n";
		}
		else {
			throw numb;
		}
	}
	catch (int numb) {
		cout << numb << " - ��� �� ����� �� ���������!\n\n";
	}

}


void task3() {
	vector<int> arr{};
	arr.resize(5);
	
	arr = input("������� ������� ������� (������������� �����) --> ", arr);

	cout << "��� ������ �� ����� �����: { ";
	for (int i = 0; i < arr.size() - 1; i++) {
		cout << arr.at(i) << ", ";
	}
	cout << arr.at(arr.size() - 1) << " }";
}


void task4() {
	double a = 0;
	double b = 0;
	double ans = 0;

	cout << "������� �������� ������� ����� --> "; cin >> a; cout << '\n';
	cout << "������� �������� ������� ����� --> "; cin >> b; cout << '\n';

	ans = divide(a, b);

	cout << a << " / " << b << " = " << ans << '\n' << '\n';
}


void task5() {
	double numb = 0;
	double ans = 0;

	try {
		input("������� ����� --> ", numb);

		if ( numb >= 0 ) {
			ans = sqrt(numb);
			cout << "������ �� " << numb << " = " << ans << '\n' << '\n';
		}
		else {
			throw "����� �� �������������� ����� �� ����������!\n";
		}
	}
	catch (const char* msg) {
		cout << msg << '\n';
	}
}


void task6() {
	string str = "";
	
	input("������� ������ --> ", str);

	try {
		// ��������� ������ ������ ������ �� ���������������
		for (int i = 0; i < str.size(); i++) {
			if (!isdigit(str.at(i))) {
				throw str + " - �� �������� ������������� ���������";
			}
		}

		cout << str << " - ������������� ��������!\n\n";
	}
	catch (string msg) {
		cout << msg << '\n';
	}
	
}
