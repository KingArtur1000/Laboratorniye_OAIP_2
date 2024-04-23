#pragma once

#include <iostream>
#include <string>

#include "enums.h"
#include "functions_extra.h"
#include "�ryptography.h"


using std::cout;
using std::cin;
using std::string;


class String {


    string input(string& str) {
        cout << "\t������� ������ ��� ���������� (������ ����� ������� �� ����������) --> ";

        cin.clear(); cin.ignore();
        std::getline(cin, str);   cout << '\n' << '\n';

        return str;
    }


    void encode() {
        cout << "\t������� ������������ ������:\n\n";

        string str_original = "";

        cout << "\t������� ������ ��� ���������� (������ ����� ������� �� ����������) --> ";
        cin.clear(); cin.ignore();
        std::getline(cin, str_original);   cout << '\n' << '\n';

        encrypt_string(str_original);
    }


    void encode_2() {
        cout << "\t������� ������������ ������ (� ������� ������������� ��������):\n\n";


    }


    void decode() {
        cout << "\t������� ������������� ������:\n\n";


    }


    void decode_2() {
        cout << "\t������� ������������� ������ (� ������� ������������� ��������):\n\n";


    }


public:

    void string_menu() {
        int choice = 0;
        bool flag = true;
        string message = "������������ � �������� ����...\n";

        do {
            cout << "\n\t\t**** ������ ****\n";
            cout << "1) ����������� ������\n";
            cout << "2) ����������� ������ (� ������� ������������� ��������)\n";
            cout << "3) ������������ ������\n";
            cout << "4) ������������ ������ (� ������� ������������� ��������)\n";
            cout << "5) ���������\n";
            cout << "\t��� ����� --> ";       cin >> choice;      cout << '\n';


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