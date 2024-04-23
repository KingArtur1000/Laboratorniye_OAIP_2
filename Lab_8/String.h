#pragma once

#include <iostream>
#include <string>

#include "enums.h"
#include "functions_extra.h"
#include "Сryptography.h"


using std::cout;
using std::cin;
using std::string;


class String {

    string str_original = "";
    string str_encrypted = "";

    void encode() {
        cout << "\n\t\t\t********** Процесс зашифрования строки **********\n\n";

        string str_original = "";

        cout << "\tВведите строку для шифрования --> ";
        cin.clear(); cin.ignore();
        std::getline(cin, str_original);   cout << '\n' << '\n';

        str_encrypted = encrypt_string(str_original);
    }


    void decode() {
        cout << "\n\t\t\t********** Процесс расшифрования строки **********\n\n";

        str_original = decrypt_string(str_encrypted);

        cout << "Расшифрованная строка: " << str_original << '\n' << '\n';
    }


public:

    void string_menu() {
        int choice = 0;
        bool flag = true;
        string message = "Возвращаемся в основное меню...\n";

        do {
            cout << "\n\t\t**** СТРОКА ****\n";
            cout << "1) Зашифровать строку\n";
            cout << "2) Расшифровать строку\n";
            cout << "3) Вернуться\n";
            cout << "\tВаш выбор --> ";       cin >> choice;      cout << '\n';


            switch (static_cast<STRING_MENU>(choice)) {
            case STRING_MENU::ENCODE:       encode();               break;
            case STRING_MENU::DECODE:       decode();               break;
            case STRING_MENU::EXIT:         exit(flag, message);    break;
            default:                        error();
            }
        } while (flag);
    }
};