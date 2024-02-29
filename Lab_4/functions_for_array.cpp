#include "functions_for_array.h"


void input_size_of_arr(vector <int>& arr, int& size) {
    cout << "������� ������ ������� (�� ����� 100) --> ";	cin >> size;	cout << '\n';
}


void fill_arr(vector <int>& arr, int size) {
    const int range = 300;  //������������ ��������� �����
    int seed = time(NULL);

    srand(seed);            // ������������� ���������� ��������� �����

    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % (range + 1)); // ������������� ������� ���������� ���������� �� 0 �� range
    }

    cout << "\t������ ������� ������������������ ���������� ����������!\n\n";
}


void output(vector <int> arr, int size) {
    cout << "\t��� ������ :\n";

    /*�������� ����� ������� (���������)*/
    cout << "[ ";
    for (int i = 0; i < (size - 1); i++) {
        if (((i % 10) == 0) && (i != 0)) {       //�� ������ �������, ���������, ��������� � �.�. �������� � ����� ������
            cout << '\n' << arr.at(i) << "\t";
        }
        else {
            cout << arr.at(i) << "\t";
        }
    }
    cout << arr.at(size - 1) << " ]\n\n";
}