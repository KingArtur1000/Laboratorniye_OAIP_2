#include "functions_for_array.h"


void input_size_of_arr(vector <int> &arr, int &SIZE) {
	cout << "Введите размер массива (не менее 100) --> ";	cin >> SIZE;	cout << '\n';
}


void fill_arr(vector <int> &arr, int SIZE) {
    const int RANGE = 300;  //Максимальное рандомное число
    int seed = time(NULL);

    srand(seed);            // инициализация генератора случайных чисел

    for (int i = 0; i < SIZE; i++) {
        arr.push_back(rand() % (RANGE + 1)); // инициализация массива случайными значениями от 0 до range
    }

    cout << "\tМассив успешно проинициализирован случайными значениями!\n\n";
}


void input_searched_value(int &target) {
    cout << "\tВведите искомое значение --> ";    cin >> target;    cout << '\n';
    cout << "\tИскомое значение сохранено!\n\n";
}


void output(vector <int> arr) {
    const int SIZE = arr.size();

    cout << "\tВаш массив :\n";
    
    /*Красивый вывод массива (квадратом)*/
    cout << "[ ";
    for (int i = 0; i < (SIZE - 1); i++) {  
        if (((i % 10) == 0) && (i != 0)){       //На каждом десятом, двадцатом, тридцатом и т.д. элементе с новой строки
            cout << '\n' << arr.at(i) << ", ";
        }
        else {
            cout << arr.at(i) << ", ";
        }
    }
    cout << arr.at(SIZE - 1) << " ]\n\n";
}