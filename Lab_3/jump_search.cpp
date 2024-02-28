#include "functions_for_search.h"


void jump_search(vector <int> arr, int SIZE, int target) {
    int step = sqrt(SIZE);
    int last_step = 0;
    int operations = 0;

    sort(arr.begin(), arr.end());

    output(arr, SIZE);

    while (arr.at(min(step, SIZE)) < target) {
        operations++;
        last_step = step;
        step += sqrt(SIZE);
        if (last_step >= SIZE) {
            cout << "������� " << target << " �� ������" << '\n';
            cout << "���-�� ���������: " << operations << '\n';
        }
    }

    while (arr.at(last_step) < target) {
        operations++;
        last_step++;
        if (last_step == min(step, SIZE)) {
            cout << "������� " << target << " �� ������" << '\n';
            cout << "���-�� ���������: " << operations << '\n';
        }
    }

    if (arr.at(last_step) == target) {
        cout << "������ ������� " << target << " �� ������� " << last_step << '\n';
        cout << "���-�� ���������: " << operations << '\n' << '\n';
    }
}