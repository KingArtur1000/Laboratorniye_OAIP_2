#pragma once

#include <iostream>
#include <string>
#include <codecvt>

#include "enums.h"
#include "functions_extra.h"
#include "Сryptography.h"


using std::cout;
using std::cin;
using std::string;


class Symbol {

    char symbol_original = '\0';
    char symbol_encrypted = '\0';


    void input(char& symbol) {
        cout << "\tВведите символ для шифрования (первая буква фамилии на английском) --> ";     cin >> symbol;      cout << '\n' << '\n';
    }


    void encode() {
        cout << "\n\t\t\t********** Процесс зашифрования символа **********\n\n";

        input(symbol_original);

        bit_8_t ciphertext = encrypt_char(symbol_original);

        symbol_encrypted = static_cast<char>(ciphertext.to_ulong());

        cout << "\n\t\tЗашифрованный символ: " << symbol_encrypted << '\n' << '\n';
    }


    void decode() {
        cout << "\n\t\t\t********** Процесс расшифрования символа **********\n\n";

        bit_8_t plaintext = decrypt_char(symbol_encrypted);

        cout << "\n\t\tРасшифрованный символ: " << static_cast<char>(plaintext.to_ulong()) << '\n' << '\n';
    }


public:

	void symbol_menu() {
        int choice = 0;
        bool flag = true;
        string message = "Возвращаемся в основное меню...\n";

        do {
            cout << "\n\t\t**** СИМВОЛ ****\n";
            cout << "1) Зашифровать символ\n";
            cout << "2) Расшифровать символ\n";
            cout << "3) Вернуться\n";
            cout << "\tВаш выбор --> ";       cin >> choice;      cout << '\n';


            switch (static_cast<SYMBOL_MENU>(choice)) {
            case SYMBOL_MENU::ENCODE:       encode();               break;
            case SYMBOL_MENU::DECODE:       decode();               break;
            case SYMBOL_MENU::EXIT:         exit(flag, message);    break;
            default:                        error();
            }
        } while (flag);
	}

};

