#include "Lab_9.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    int choice = 0;
    bool flag = true;
    string message = "���������� ������...";


    do {
        cout << "\n\t�������� ������ �������: :)\n";
        cout << "1) ������� 1\n";
        cout << "2) ������� 2\n";
        cout << "3) ������� 3\n";
        cout << "4) ������� 4\n";
        cout << "5) ������� 5\n";
        cout << "6) ������� 6\n";
        cout << "7) �����\n";
        cout << "\t��� ����� --> ";     cin >> choice;     cout << '\n' << '\n';

        switch (static_cast<MAIN_MENU>(choice)) {
        case MAIN_MENU::TASK1: task1(); break;
        case MAIN_MENU::TASK2: task2(); break;
        case MAIN_MENU::TASK3: task3(); break;
        case MAIN_MENU::TASK4: task4(); break;
        case MAIN_MENU::TASK5: task5(); break;
        case MAIN_MENU::TASK6: task6(); break;
        case MAIN_MENU::EXIT: exit(flag); break;

        default:                    error();
        }
    } while (flag);


    return 0;
}