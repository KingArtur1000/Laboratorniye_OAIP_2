#include "functions_for_sort.h"


void shaker_sort(vector<int> arr, int size, bool is_sorted) {
    bool is_swapped = true;
    int start = 0;
    int end = size - 1;

    while (is_swapped) {
        is_swapped = false;

        // ������ ����� �������
        for (int i = start; i < end; ++i) {
            if (arr.at(i) > arr.at(i + 1)) {
                swap(arr.at(i), arr.at(i + 1));
                is_swapped = true;
            }
        }

        if (!is_swapped) // ���� �� ���� ������������, �� ������ ��� ������������
            break;

        is_swapped = false;

        // ��������� ������ �������
        --end;

        // ������ ������ ������
        for (int i = end - 1; i >= start; --i) {
            if (arr.at(i) > arr.at(i + 1)) {
                swap(arr.at(i), arr.at(i + 1));
                is_swapped = true;
            }
        }

        // ����������� ����� �������
        ++start;
    }

    is_sorted = true;

    output(arr, size, is_sorted);
}