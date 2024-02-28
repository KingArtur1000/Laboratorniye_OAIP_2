#include "functions_for_search.h"


void binary_search(vector <int> arr, int SIZE, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int middle = 0;
    int operations = 0;
    bool flag = false;


    sort(arr.begin(), arr.end());

    output(arr, SIZE);

    while ((left <= right) && (flag != true)) {
        middle = (left + right) / 2;        // ��������� ���������� ������ �������
        operations++;

        if (arr[middle] == target) flag = true;         //��������� ���� (������� ��������) �� ���������� ���������
        if (arr[middle] > target) right = middle - 1;       // ���������, ����� ����� ����� ���������
        else left = middle + 1;
    }

    if (flag) {
        cout << "������ ������� " << target << " ��� �������� " << middle << '\n';
        cout << "���-�� ���������: " << operations << '\n' << '\n';
    } 
    else cout << "������� " << target <<  " �� ��� ������!\n\n";
}