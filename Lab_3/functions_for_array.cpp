#include "functions_for_array.h"


void input_size_of_arr(vector <int> &arr, int &SIZE) {
	cout << "������� ������ ������� (�� ����� 100) --> ";	cin >> SIZE;	cout << '\n';
}


void fill_arr(vector <int> &arr, int SIZE) {
    const int range = 300;  //������������ ��������� �����
    int seed = time(NULL);

    srand(seed);            // ������������� ���������� ��������� �����

    for (int i = 0; i < SIZE; i++) {
        arr.push_back(rand() % (range + 1)); // ������������� ������� ���������� ���������� �� 0 �� range
    }

    cout << "\t������ ������� ������������������ ���������� ����������!\n\n";
}


void input_searched_value(int &target) {
    cout << "\t������� ������� �������� --> ";    cin >> target;    cout << '\n';
    cout << "\t������� �������� ���������!\n\n";
}


void output(vector <int> arr, int SIZE) {
    cout << "\t��� ������ :\n";
    
    /*�������� ����� ������� (���������)*/
    cout << "[ ";
    for (int i = 0; i < (SIZE - 1); i++) {  
        if (((i % 10) == 0) && (i != 0)){       //�� ������ �������, ���������, ��������� � �.�. �������� � ����� ������
            cout << '\n' << arr.at(i) << ", ";
        }
        else {
            cout << arr.at(i) << ", ";
        }
    }
    cout << arr.at(SIZE - 1) << " ]\n\n";
}