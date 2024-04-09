#include "Lab_7.h"	//Подключили собственный заголовочный файл


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    int choice = 0;
    int value = 0;
    bool flag = true;
    string message = "Завершение работы...";


    do {
        cout << "\n\tС чем работаем? :)\n";
        cout << "1) Бинарное дерево поиска\n";
        cout << "2) AVL-дерево\n";
        cout << "3) Выход\n";
        cout << "\tВаш выбор --> ";     cin >> choice;     cout << '\n' << '\n';

        switch (static_cast<MAIN_MENU>(choice)) {
        case MAIN_MENU::BINARY_TREE_MENU:         BinaryTree_Menu();     break;
        case MAIN_MENU::AVL_TREE_MENU:            AVLTree_Menu();        break;
        case MAIN_MENU::EXIT:                     exit(flag, message);   break;
        default:     error();
        }
    } while (flag);


    return 0;
}