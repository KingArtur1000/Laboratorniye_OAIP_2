#include "lab_6.h"	//���������� ����������� ������������ ����


int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");


    int choice = 0;
    int value = 0;
    int position = 0;
    bool flag = true;
    string message = "���������� ���������...";


    do {
        cout << "\n\t � ��� ��������? :)\n";
        cout << "1) ���\n";
        cout << "2) �������\n";
        cout << "3) ����\n";
        cout << "4) �����\n";
        cout << "\t��� ����� --> ";     cin >> choice;     cout << '\n' << '\n';

        switch (static_cast<MAIN_MENU>(choice)) {
        case MAIN_MENU::DACK:     Dack_Menu(value, position);       break;
        case MAIN_MENU::QUEUE:    Queue_Menu(value, position);      break;
        case MAIN_MENU::STACK:    Stack_Menu(value, position);      break;
        case MAIN_MENU::EXIT:     exit(flag, message);                       break;
        default:                  error();
        }
    } while (flag);


	return 0;
}