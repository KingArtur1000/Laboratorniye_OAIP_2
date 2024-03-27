#include "Lists.h"


void Dack_Menu(int value, int position) {   //Dack - ������������ ������� (���������� ���� �� �������� Dequeue) (�� Dack -������� ����� :) )
    Dack dack = {};
    int choice = 0;
    bool flag = true;
    string message = "������������ � �������� ����...";


    do {
        cout << "\n\t\t**** ���� �������������� � -�����- ****\n";
        cout << "------------------------------------------------------\n";
        cout << "\t����������:\n";
        cout << "1) � ������ ������\n";
        cout << "2) � ����� ������\n";
        cout << "3) � ������������ �����\n";
        cout << "\t��������:\n";
        cout << "4) �� ������ ������\n";
        cout << "5) �� ����� ������\n";
        cout << "6) �� ������������� ����� ������\n";
        cout << "\t������:\n";
        cout << "7) ������� ������\n";
        cout << "8) ����� ������\n";
        cout << "9) ��������� � �������� ����\n";
        cout << "\t��� ����� --> ";       cin >> choice;      cout << '\n';


        switch (static_cast<Dack_operation>(choice)) {
        case Dack_operation::PUSH_FRONT:    dack.pushFront(value);          break;
        case Dack_operation::PUSH_BACK:     dack.pushBack(value);           break;
        case Dack_operation::INSERT:        dack.insert(value, position);   break;
        case Dack_operation::POP_FRONT:     dack.popFront();                break;
        case Dack_operation::POP_BACK:      dack.popBack();                 break;
        case Dack_operation::ERASE:         dack.erase(position);           break;
        case Dack_operation::CLEAR_Dack:    dack.clear();                   break;
        case Dack_operation::PRINT_Dack:    dack.print();                   break;
        case Dack_operation::EXIT:          exit(flag, message);            break;
        default:                            error();
        }
    } while (flag);
}


void Queue_Menu(int value, int position) {  //�������
    Queue queue = {};
    int choice = 0;
    bool flag = true;
    string message = "������������ � �������� ����...";


    do {
        cout << "\n\t\t**** ���� �������������� � -��������- ****\n";
        cout << "------------------------------------------------------\n";
        cout << "1) ���������� �������� � ����� �������\n";
        cout << "2) �������� �������� �� ������ �������\n";
        cout << "3) �������� ���� ������ � �������\n";
        cout << "4) ����� ���� �������\n";
        cout << "5) ��������� � �������� ����\n";
        cout << "\t��� ����� --> ";       cin >> choice;      cout << '\n';


        switch (static_cast<Queue_operation>(choice)) {
        case Queue_operation::ADD_VALUE:    queue.enqueue(value);   break;
        case Queue_operation::REMOVE_VALUE: queue.dequeue();        break;
        case Queue_operation::CLEAR_QUEUE:  queue.clear();          break;
        case Queue_operation::PRINT_QUEUE:  queue.print();          break;
        case Queue_operation::EXIT:         exit(flag, message);    break;
        default:                            error();
        }
    } while (flag);
}


void Stack_Menu(int value, int position) {  //����
    Stack stack = {};
    int choice = 0;
    bool flag = true;
    string message = "������������ � �������� ����...";


    do {
        cout << "\n\t\t**** ���� �������������� �� -������- ****\n";
        cout << "------------------------------------------------------\n";
        cout << "1) ���������� �������� � �������\n";
        cout << "2) �������� �������� �� �������\n";
        cout << "3) �������� ���� ������\n";
        cout << "4) ����� ����� �����\n";
        cout << "5) ��������� � �������� ����\n";
        cout << "\t��� ����� --> ";   cin >> choice;      cout << '\n';


        switch (static_cast<Stack_operation>(choice)) {
        case Stack_operation::ADD_VALUE:    stack.push(value);      break;
        case Stack_operation::REMOVE_VALUE: stack.pop();            break;
        case Stack_operation::CLEAR_STACK:  stack.clear();          break;
        case Stack_operation::PRINT_STACK:  stack.print();          break;
        case Stack_operation::EXIT:         exit(flag, message);    break;
        default:                            error();
        }
    } while (flag);
}