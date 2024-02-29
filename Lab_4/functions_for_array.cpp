#include "functions_for_array.h"


void input_size_of_arr(vector <int>& arr, int& size) {
    cout << "Введите размер массива (не менее 100) --> ";	cin >> size;	cout << '\n';
}


void fill_arr(vector <int>& arr, int size) {
    const int range = 300;  //Максимальное рандомное число
    int seed = time(NULL);

    srand(seed);            // инициализация генератора случайных чисел

    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % (range + 1)); // инициализация массива случайными значениями от 0 до range
    }

    cout << "\tМассив успешно проинициализирован случайными значениями!\n\n";
}


void output(vector <int> arr, int size, bool is_sorted) {
    if (is_sorted)      cout << "\tВаш отcортированный массив:\n";
    else                cout << "\tВаш массив :\n";

    /*Красивый вывод массива (квадратом)*/
    cout << "[ ";
    for (int i = 0; i < (size - 1); i++) {
        if (((i % 10) == 0) && (i != 0)) {       //На каждом десятом, двадцатом, тридцатом и т.д. элементе с новой строки
            cout << '\n' << arr.at(i) << "\t";
        }
        else {
            cout << arr.at(i) << "\t";
        }
    }
    cout << arr.at(size - 1) << " ]\n\n";
}