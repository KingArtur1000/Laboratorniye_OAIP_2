#include "functions_for_sort.h"


int find_min_index(vector<int> arr, int begin, int end)
{
    int min_index = begin; // ������������, ��� ����������� ������� - ��� arr[i]

    // ���� �� ���������� ��������� � ��������� min_index, ���� ������� ������� ������ �������� ������������
    for (int k = begin + 1; k < end; k++) {
        if (arr[k] < arr[min_index]) {
            min_index = k;
        }
    }

    return min_index;
}


void recursive_sort(vector<int> arr, int size, bool is_sorted, int index) {
    int min_index = 0;

    // ������� ������, ����� index � size ����� �����������
    if (index == size) {
        is_sorted = true;
        output(arr, size, is_sorted);
        return;
    }

    // ����� ������� min_index ��� ��������� ������������ �������
    min_index = find_min_index(arr, index, size);

    // ������ �������, ����� ������ � ����������� ������ �� ���������
    if (min_index != index)     swap(arr[min_index], arr[index]);

    // ����������� ����� ������� ����������
    recursive_sort(arr, size, is_sorted, index + 1);
}