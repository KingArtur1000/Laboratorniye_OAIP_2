#include "tasks.h"


template<typename T> void input(const char* msg, T &var) {
	cout << msg; cin >> var; cout << '\n';
	cout << "Ваша переменная: " << var << '\n' << '\n';
}


string input(const char* msg, string &str) {
	cout << msg; getline(cin, str); cout << '\n';
	cout << "Ваша строка: " << str << '\n' << '\n';
	return str;
}


vector<int> input(const char* msg, vector<int> &arr) {
	string numb_str = "";

	cin.clear(); cin.ignore();

	for (int i = 0; i < arr.size(); i++) {
		cout << msg;
		getline(cin, numb_str);

		try {
			double numb = stod(numb_str);
			int result = (int)(numb);

			if (result != numb) {
				cout << "Число " << numb << " было преобразовано в " << result << "\n\n";
			}

			arr.at(i) = numb;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Некорректное значение: строка не может быть преобразована в число" << '\n';
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Число выходит за пределы допустимого диапазона" << '\n';
		}
	}

	return arr;
}


double divide(double a, double b) {
	try {
		if (b == 0) {
			throw "Деление на ноль невозможно!\n";
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

		cout << "\tЧто вы хотите сделать?\n\n";
		cout << "1) Ввести только строку\n";
		cout << "2) Ввести строку и число\n";
		cout << "\tВаш выбор --> "; cin >> choice; cout << '\n';
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
			str = input("Введите строку --> ", str);
			break;
		case 2:	
			str = input("Введите строку --> ", str);
			input("Введите число --> ", numb);
			break;
		default: error(); break;
		}
	}
}


void task2() {
	int numb = 0;

	try {
		input("Введите число(от 0 до 7 включительно)-- > ", numb);

		if (numb >= 0 && numb <= 7) {
			cout << numb << " - верное число из диапазона!\n\n";
		}
		else {
			throw numb;
		}
	}
	catch (int numb) {
		cout << numb << " - это не число из диапазона!\n\n";
	}

}


void task3() {
	vector<int> arr{};
	arr.resize(5);
	
	arr = input("Введите элемент массива (целочисленное число) --> ", arr);

	cout << "\tВаш массив из целых чисел: { ";
	for (int i = 0; i < arr.size() - 1; i++) {
		cout << arr.at(i) << ", ";
	}
	cout << arr.at(arr.size() - 1) << " }\n\n";
}


void task4() {
	double a = 0;
	double b = 0;
	double ans = 0;

	cout << "Введите значение первого числа --> "; cin >> a; cout << '\n';
	cout << "Введите значение второго числа --> "; cin >> b; cout << '\n';

	ans = divide(a, b);

	cout << a << " / " << b << " = " << ans << '\n' << '\n';
}


void task5() {
	double numb = 0;
	double ans = 0;

	try {
		input("Введите число --> ", numb);

		if ( numb >= 0 ) {
			ans = sqrt(numb);
			cout << "Корень из " << numb << " = " << ans << '\n' << '\n';
		}
		else {
			throw "Корня из отрицательного числа не существует!\n";
		}
	}
	catch (const char* msg) {
		cout << msg << '\n';
	}
}


void task6() {
	string str = "";
	
	cin.clear(); cin.ignore();
	input("Введите строку --> ", str);

	try {
		// Проверяем каждый символ строки на целочисленность
		for (int i = 0; i < str.size(); i++) {
			if (!isdigit(str.at(i))) {
				throw str + " - не является целочисленным значением";
			}
		}

		cout << str << " - целочисленное значение!\n\n";
	}
	catch (string msg) {
		cout << msg << '\n';
	}
	
}

