#include "Lab_8.h"	//���������� ����������� ������������ ����


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    int choice = 0;
    int value = 0;
    bool flag = true;
    string message = "���������� ������...";

    Symbol symbol = {};
    String string = {};


    do {
        cout << "\n\t� ��� ����� ��������? :)\n";
        cout << "1) ������ '@'\n";
        cout << "2) ������ \"������\"\n";
        cout << "3) �����\n";
        cout << "\t��� ����� --> ";     cin >> choice;     cout << '\n' << '\n';

        switch (static_cast<MAIN_MENU>(choice)) {
        case MAIN_MENU::SYMBOL:     symbol.symbol_menu();   break;
        case MAIN_MENU::STRING:     string.string_menu();   break;
        case MAIN_MENU::EXIT:       exit(flag, message);    break;
        default:                    error();
        }
    } while (flag);


    return 0;
}