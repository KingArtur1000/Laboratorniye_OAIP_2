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

    char symbol = '\0';


    void input(char& symbol) {
        cout << "\tВведите символ для шифрования (первая буква фамилии на английском) --> ";     cin >> symbol;      cout << '\n' << '\n';
    }


    void encode() {
        cout << "\n\t\t***** Процесс зашифрования символа *****\n\n";

        input(symbol);

        bit_8_t ciphertext = encrypt_char(symbol);

        cout << "Зашифрованный символ: " << static_cast<char>(ciphertext.to_ulong()) << '\n' << '\n';

    }


    void encode_2() {
        cout << "\n\t\tПроцесс зашифрования символа (с выводом промежуточных значений):\n\n";


    }


    void decode() {
        cout << "\tПроцесс расшифрования символа:\n\n";

        //int plaintext = decrypt_char(symbol);

        //cout << "Расшифрованный символ: " << static_cast<char>(plaintext) << '\n';
    }


    void decode_2(){
        cout << "\tПроцесс расшифрования символа (с выводом промежуточных значений):\n\n";


    }


public:

	void symbol_menu() {
        int choice = 0;
        bool flag = true;
        string message = "Возвращаемся в основное меню...\n";

        do {
            cout << "\n\t\t**** СИМВОЛ ****\n";
            cout << "1) Зашифровать символ\n";
            cout << "2) Зашифровать символ (с выводом промежуточных значений)\n";
            cout << "3) Расшифровать символ\n";
            cout << "4) Расшифровать символ (с выводом промежуточных значений)\n";
            cout << "5) Вернуться\n";
            cout << "\tВаш выбор --> ";       cin >> choice;      cout << '\n';


            switch (static_cast<SYMBOL_MENU>(choice)) {
            case SYMBOL_MENU::ENCODE:       encode();               break;
            case SYMBOL_MENU::ENCODE_2:     encode_2();             break;
            case SYMBOL_MENU::DECODE:       decode();               break;
            case SYMBOL_MENU::DECODE_2:     decode_2();             break;
            case SYMBOL_MENU::EXIT:         exit(flag, message);    break;
            default:                        error();
            }
        } while (flag);
	}

};

