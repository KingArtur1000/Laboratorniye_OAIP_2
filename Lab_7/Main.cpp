#include "Lab_7.h"	//���������� ����������� ������������ ����


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    int choice = 0;
    int value = 0;
    bool flag = true;
    string message = "��������� ������...";

    BinarySearchTree binary_search_tree = {};


    do {
        cout << "\n\t� ��� ��������? :)\n";
        cout << "1) �������� ������ ������\n";
        cout << "2) AVL-������\n";
        cout << "3) �����\n";
        cout << "\t��� ����� --> ";     cin >> choice;     cout << '\n' << '\n';

        switch (static_cast<MAIN_MENU>(choice)) {
        case MAIN_MENU::BINARY_TREE_MENU:         BinaryTree_Menu();      break;
        case MAIN_MENU::AVL_TREE_MENU:      //AVLTree_Menu();         break;
        case MAIN_MENU::EXIT:           exit(flag, message);    break;
        default:     error();
        }
    } while (flag);


    return 0;
}