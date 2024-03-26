#include "Lists.h"


void Dack_Menu(int value, int position) {   //Dack - ������������ ������� (���������� ���� �� �������� Dequeue) (�� Dack -������� ����� :) )
    Dack dack = {};
    int choice = 0;
    bool flag = true;


    do {
        cout << "\n\t\t**** ���� �������������� � -�����- ****\n";
        cout << "\t---------------------------\n";
        cout << "\t����������:\n";
        cout << "\t1. � ������ ������\n";
        cout << "\t2. � ����� ������\n";
        cout << "\t3. � ������������ �����\n";
        cout << "\t��������:\n";
        cout << "\t4. �� ������ ������\n";
        cout << "\t5. �� ����� ������\n";
        cout << "\t6. �� ������������� ����� ������\n";
        cout << "\t������:\n";
        cout << "\t7. ������� ������\n";
        cout << "\t8. ����� ������\n";
        cout << "\t9. �����\n";
        cout << "\n\t��� ����� --> ";       cin >> choice;      cout << '\n';


        switch (static_cast<Dack_operation>(choice)) {
        case Dack_operation::PUSH_FRONT:    dack.pushFront(value);          break;
        case Dack_operation::PUSH_BACK:     dack.pushBack(value);           break;
        case Dack_operation::INSERT:        dack.insert(value, position);   break;
        case Dack_operation::POP_FRONT:     dack.popFront();                break;
        case Dack_operation::POP_BACK:      dack.popBack();                 break;
        case Dack_operation::ERASE:         dack.erase(position);           break;
        case Dack_operation::CLEAR_Dack:    dack.clear();                   break;
        case Dack_operation::PRINT_Dack:    dack.print();                   break;
        case Dack_operation::EXIT:          exit(flag);                     break;
        default:                            error();
        }
    } while (flag);
}


void Queue_Menu(int value, int position) {  //�������
    Queue queue = {};
    int choice = 0;
    bool flag = true;


    do {
        cout << "\n\t\t**** ���� �������������� � -��������- ****\n";
        cout << "\t1. ���������� �������� � ����� �������\n";
        cout << "\t2. �������� �������� �� ������ �������\n";
        cout << "\t3. �������� ���� ������ � �������\n";
        cout << "\t4. ����� ���� �������\n";
        cout << "\t5. �����\n";
        cout << "\n\t��� ����� --> ";       cin >> choice;      cout << '\n';


        switch (static_cast<Queue_operation>(choice)) {
        case Queue_operation::ADD_VALUE:    queue.enqueue(value);   break;
        case Queue_operation::REMOVE_VALUE: queue.dequeue();        break;
        case Queue_operation::CLEAR_QUEUE:  queue.clear();          break;
        case Queue_operation::PRINT_QUEUE:  queue.print();          break;
        case Queue_operation::EXIT:         exit(flag);             break;
        default:                            error();
        }
    } while (flag);
}


void Stack_Menu(int value, int position) {  //����
    Stack stack = {};
    int choice = 0;
    bool flag = true;


    do {
        cout << "\n\t\t**** ���� �������������� �� -������- ****\n";
        cout << "\t1. ���������� �������� � �������\n";
        cout << "\t2. �������� �������� �� �������\n";
        cout << "\t3. �������� ���� ������\n";
        cout << "\t4. ����� ����� �����\n";
        cout << "\t5. �����\n";
        cout << "\n\t��� ����� --> ";   cin >> choice;      cout << '\n';


        switch (static_cast<Stack_operation>(choice)) {
        case Stack_operation::ADD_VALUE:    stack.push(value);      break;
        case Stack_operation::REMOVE_VALUE: stack.pop();            break;
        case Stack_operation::CLEAR_STACK:  stack.clear();          break;
        case Stack_operation::PRINT_STACK:  stack.print();          break;
        case Stack_operation::EXIT:         exit(flag);             break;
        default:                            error();
        }
    } while (flag);
}