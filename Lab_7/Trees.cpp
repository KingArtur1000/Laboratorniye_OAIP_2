#include "Trees.h"


void BinaryTree_Menu() {   //avl_tree - двусторонняя очередь (правильнее было бы записать Dequeue) (Но avl_tree -пишется проще :) )
    BinarySearchTree binary_search_tree = {};
    int choice = 0;
    int value = 0;
    bool flag = true;
    string message = "Возвращаемся в основное меню...";


    do {
        cout << "\n\t\t**** Бинарное дерево поиска ****\n";
        cout << "1) Добавление узла\n";
        cout << "2) Поиск узла\n";
        cout << "3) Удаление узла\n";
        cout << "4) Удаление всего дерева\n";
        cout << "5) Вывод всего дерева\n";
        cout << "6) Вернуться\n";
        cout << "\tВаш выбор --> ";       cin >> choice;      cout << '\n';


        switch (static_cast<BinaryTreeMenu>(choice)) {
        case BinaryTreeMenu::ADDING:        binary_search_tree.input_value(value);    binary_search_tree.add(value);                binary_search_tree.showSymmetricalOrder();  break;
        case BinaryTreeMenu::SEARCHING:     binary_search_tree.input_value(value);    binary_search_tree.showSymmetricalOrder();    binary_search_tree.search(value);           break;
        case BinaryTreeMenu::REMOVING:      binary_search_tree.input_value(value);    binary_search_tree.erase(value);              binary_search_tree.showSymmetricalOrder();  break;
        case BinaryTreeMenu::REMOVING_ALL:  binary_search_tree.remove_all();                                                        binary_search_tree.showSymmetricalOrder();  break;
        case BinaryTreeMenu::PRINTING:      binary_search_tree.showSymmetricalOrder();                                                                                          break;
        case BinaryTreeMenu::RETURNING:     exit(flag, message);                                                                                                                break;
        default:                            error();
        }
    } while (flag);
}


void AVLTree_Menu() {   //avl_tree - двусторонняя очередь (правильнее было бы записать Dequeue) (Но avl_tree -пишется проще :) )
    AVLTree avl_tree = {};
    int choice = 0;
    int value = 0;
    bool flag = true;
    string message = "Возвращаемся в основное меню...";


    do {
        cout << "\n\t\t**** AVL-дерево ****\n";
        cout << "1) Добавление узлов по умолчанию (согласно варианту)\n";
        cout << "2) Вывод всего дерева\n";
        cout << "3) Вернуться\n";
        cout << "\tВаш выбор --> ";       cin >> choice;      cout << '\n';


        switch (static_cast<AVLTreeMenu>(choice)) {
        case AVLTreeMenu::ADDING:        avl_tree.insert();                  break;
        case AVLTreeMenu::PRINTING:      avl_tree.showSymmetricalOrder();    break;
        case AVLTreeMenu::RETURNING:     exit(flag, message);                break;
        default:                         error();
        }
    } while (flag);
}

