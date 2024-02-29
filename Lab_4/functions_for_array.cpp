#include "functions_for_array.h"


void input_size_of_arr(vector <int>& arr, int& size) {
    cout << "¬ведите размер массива (не менее 100) --> ";	cin >> size;	cout << '\n';
}


void fill_arr(vector <int>& arr, int size) {
    const int range = 300;  //ћаксимальное рандомное число
    int seed = time(NULL);

    srand(seed);            // инициализаци€ генератора случайных чисел

    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % (range + 1)); // инициализаци€ массива случайными значени€ми от 0 до range
    }

    cout << "\tћассив успешно проинициализирован случайными значени€ми!\n\n";
}


void output(vector <int> arr, int size) {
    cout << "\t¬аш массив :\n";

    /* расивый вывод массива (квадратом)*/
    cout << "[ ";
    for (int i = 0; i < (size - 1); i++) {
        if (((i % 10) == 0) && (i != 0)) {       //Ќа каждом дес€том, двадцатом, тридцатом и т.д. элементе с новой строки
            cout << '\n' << arr.at(i) << "\t";
        }
        else {
            cout << arr.at(i) << "\t";
        }
    }
    cout << arr.at(size - 1) << " ]\n\n";
}