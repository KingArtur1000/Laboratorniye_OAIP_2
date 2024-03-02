#include "functions_for_sort.h"

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
void hoara_sort(vector<int> arr, int size, bool is_sorted, int begin, int end) {
    int pivot = arr[begin];
    int l_hold = begin;
    int r_hold = end;

    cout << begin << " " << end << '\n';

    if (begin >= end) {
        is_sorted = true;
        output(arr, size, is_sorted);
        return; // Базовый случай: если подмассив состоит из одного элемента или пуст
    }

    while (begin < end) {
        while ((arr[end] >= pivot) && (begin < end))
            end--;

        if (begin != end) {
            arr[begin] = arr[end];
            begin++;
        }

        while ((arr[begin] <= pivot) && (begin < end))
            begin++;

        if (begin != end) {
            arr[end] = arr[begin];
            end--;
        }
    }

    arr[begin] = pivot;
    pivot = begin;
    begin = l_hold;
    end = r_hold;

    if (begin < pivot)
        hoara_sort(arr, size, is_sorted, begin, pivot - 1);

    if (end > pivot)
        hoara_sort(arr, size, is_sorted, pivot + 1, end);
}