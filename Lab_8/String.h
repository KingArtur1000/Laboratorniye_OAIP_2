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


    string input(string& str) {
        cout << "\tВведите символ для шифрования (первая буква фамилии на английском) --> ";

        cin.clear(); cin.ignore();
        std::getline(cin, str);   cout << '\n' << '\n';

        return str;
    }


    void encode() {
        cout << "\tПроцесс зашифрования строки:\n\n";

        string str_original = "";

        cout << "\tВведите символ для шифрования (первая буква фамилии на английском) --> ";
        cin.clear(); cin.ignore();
        std::getline(cin, str_original);   cout << '\n' << '\n';

        encrypt_string(str_original);
    }


    void encode_2() {
        cout << "\tПроцесс зашифрования строки (с выводом промежуточных значений):\n\n";


    }


    void decode() {
        cout << "\tПроцесс расшифрования строки:\n\n";


    }


    void decode_2() {
        cout << "\tПроцесс расшифрования строки (с выводом промежуточных значений):\n\n";


    }


public:

    void string_menu() {
        int choice = 0;
        bool flag = true;
        string message = "Возвращаемся в основное меню...\n";

        do {
            cout << "\n\t\t**** СТРОКА ****\n";
            cout << "1) Зашифровать строку\n";
            cout << "2) Зашифровать строку (с выводом промежуточных значений)\n";
            cout << "3) Расшифровать строку\n";
            cout << "4) Расшифровать строку (с выводом промежуточных значений)\n";
            cout << "5) Вернуться\n";
            cout << "\tВаш выбор --> ";       cin >> choice;      cout << '\n';


            switch (static_cast<STRING_MENU>(choice)) {
            case STRING_MENU::ENCODE:       encode();               break;
            case STRING_MENU::ENCODE_2:     encode_2();             break;
            case STRING_MENU::DECODE:       decode();               break;
            case STRING_MENU::DECODE_2:     decode_2();             break;
            case STRING_MENU::EXIT:         exit(flag, message);    break;
            default:                        error();
            }
        } while (flag);
    }
};