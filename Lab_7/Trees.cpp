#include "Trees.h"


void BinaryTree_Menu() {   //binary_search_tree - ������������ ������� (���������� ���� �� �������� Dequeue) (�� binary_search_tree -������� ����� :) )
    BinarySearchTree binary_search_tree = {};
    int choice = 0;
    int value = 0;
    bool flag = true;
    string message = "������������ � �������� ����...";


    do {
        cout << "\n\t\t**** �������� ������ ������ ****\n";
        cout << "1) ���������� ����\n";
        cout << "2) ����� ����\n";
        cout << "3) �������� ����\n";
        cout << "4) �������� ����� ������\n";
        cout << "5) ����� ����� ������\n";
        cout << "6) ���������\n";
        cout << "\t��� ����� --> ";       cin >> choice;      cout << '\n';


        switch (static_cast<BinaryTreeMenu>(choice)) {
        case BinaryTreeMenu::ADDING:        binary_search_tree.input_value(value);    binary_search_tree.add(value);   binary_search_tree.showSymmetricalOrder();       break;
        case BinaryTreeMenu::SEARCHING:     binary_search_tree.input_value(value);    binary_search_tree.search(value);       break;
        case BinaryTreeMenu::REMOVING:      binary_search_tree.input_value(value);    binary_search_tree.erase(value);  binary_search_tree.showSymmetricalOrder();   break;
        case BinaryTreeMenu::REMOVING_ALL:  binary_search_tree.remove_all();                break;
        case BinaryTreeMenu::PRINTING:      binary_search_tree.showSymmetricalOrder();                 break;
        case BinaryTreeMenu::RETURNING:     exit(flag, message);            break;
        default:                            error();
        }
    } while (flag);
}


//void AVLTree_Menu(int value, int position) {  //�������
//    Queue queue = {};
//    int choice = 0;
//    bool flag = true;
//    string message = "������������ � �������� ����...";
//
//
//    do {
//        cout << "\n\t\t**** ���� �������������� � -��������- ****\n";
//        cout << "------------------------------------------------------\n";
//        cout << "1) ���������� �������� � ����� �������\n";
//        cout << "2) �������� �������� �� ������ �������\n";
//        cout << "3) �������� ���� ������ � �������\n";
//        cout << "4) ����� ���� �������\n";
//        cout << "5) ��������� � �������� ����\n";
//        cout << "\t��� ����� --> ";       cin >> choice;      cout << '\n';
//
//
//        switch (static_cast<Queue_operation>(choice)) {
//        case Queue_operation::ADD_VALUE:    queue.enqueue(value);   break;
//        case Queue_operation::REMOVE_VALUE: queue.dequeue();        break;
//        case Queue_operation::CLEAR_QUEUE:  queue.clear();          break;
//        case Queue_operation::PRINT_QUEUE:  queue.print();          break;
//        case Queue_operation::EXIT:         exit(flag, message);    break;
//        default:                            error();
//        }
//    } while (flag);
//}
//
//
//void Stack_Menu(int value, int position) {  //����
//    Stack stack = {};
//    int choice = 0;
//    bool flag = true;
//    string message = "������������ � �������� ����...";
//
//
//    do {
//        cout << "\n\t\t**** ���� �������������� �� -������- ****\n";
//        cout << "------------------------------------------------------\n";
//        cout << "1) ���������� �������� � �������\n";
//        cout << "2) �������� �������� �� �������\n";
//        cout << "3) �������� ���� ������\n";
//        cout << "4) ����� ����� �����\n";
//        cout << "5) ��������� � �������� ����\n";
//        cout << "\t��� ����� --> ";   cin >> choice;      cout << '\n';
//
//
//        switch (static_cast<Stack_operation>(choice)) {
//        case Stack_operation::ADD_VALUE:    stack.push(value);      break;
//        case Stack_operation::REMOVE_VALUE: stack.pop();            break;
//        case Stack_operation::CLEAR_STACK:  stack.clear();          break;
//        case Stack_operation::PRINT_STACK:  stack.print();          break;
//        case Stack_operation::EXIT:         exit(flag, message);    break;
//        default:                            error();
//        }
//    } while (flag);
//}