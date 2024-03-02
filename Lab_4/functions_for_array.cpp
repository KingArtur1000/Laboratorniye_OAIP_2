#include "functions_for_array.h"


void input_size_of_arr(int& size) {
    cout << "Введите размер массива (не менее 100) --> ";	cin >> size;	cout << '\n';
}


void fill_arr(vector <int>& arr_original, vector <int>& arr_sort, int size) {
    const int range = 300;  //Максимальное рандомное число
    int seed = time(0);

    srand(seed);            // инициализация генератора случайных чисел

    for (int i = 0; i < size; i++) {
        arr_original.push_back(rand() % (range + 1)); // инициализация массива случайными значениями от 0 до range
        arr_sort = arr_original;
    }


    cout << "\tМассив успешно проинициализирован случайными значениями!\n\n";
}


void output(vector <int>& arr_original, vector <int>& arr_sorted, Conditions& conditions) {

    if (conditions.is_sorted) {
        cout << "\tВаш отcортированный массив:\n";

        /*Красивый вывод массива (квадратом)*/
        cout << "[ ";
        for (int i = 0; i < (arr_sorted.size() - 1); i++) {
            if (((i % 10) == 0) && (i != 0)) {       //На каждом десятом, двадцатом, тридцатом и т.д. элементе с новой строки
                cout << '\n' << arr_sorted.at(i) << "\t";
            }
            else {
                cout << arr_sorted.at(i) << "\t";
            }
        }
        cout << arr_sorted.at(arr_sorted.size() - 1) << " ]\n\n";
    }      
    else {
        cout << "\tВаш исходный массив :\n";

        /*Красивый вывод массива (квадратом)*/
        cout << "[ ";
        for (int i = 0; i < (arr_sorted.size() - 1); i++) {
            if (((i % 10) == 0) && (i != 0)) {       //На каждом десятом, двадцатом, тридцатом и т.д. элементе с новой строки
                cout << '\n' << arr_original.at(i) << "\t";
            }
            else {
                cout << arr_original.at(i) << "\t";
            }
        }
        cout << arr_original.at(arr_sorted.size() - 1) << " ]\n\n";
    }             
}


void output_original(vector <int>& arr_original, vector <int>& arr_sorted, Conditions& conditions) {
    cout << "\tВаш исходный массив :\n";

    /*Красивый вывод массива (квадратом)*/
    cout << "[ ";
    for (int i = 0; i < (arr_sorted.size() - 1); i++) {
        if (((i % 10) == 0) && (i != 0)) {       //На каждом десятом, двадцатом, тридцатом и т.д. элементе с новой строки
            cout << '\n' << arr_original.at(i) << "\t";
        }
        else {
            cout << arr_original.at(i) << "\t";
        }
    }
    cout << arr_original.at(arr_sorted.size() - 1) << " ]\n\n";
}