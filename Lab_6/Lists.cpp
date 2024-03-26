#include "Lists.h"


void Dack_Menu(int value, int position) {   //Dack - двусторонняя очередь (правильнее было бы записать Dequeue) (Но Dack -пишется проще :) )
    Dack dack = {};
    int choice = 0;
    bool flag = true;


    do {
        cout << "\n\t\t**** МЕНЮ ВЗАИМОДЕЙСТВИЯ С -ДЕКОМ- ****\n";
        cout << "\t---------------------------\n";
        cout << "\tДобавление:\n";
        cout << "\t1. В начало списка\n";
        cout << "\t2. В конец списка\n";
        cout << "\t3. В произвольное место\n";
        cout << "\tУдаление:\n";
        cout << "\t4. Из начала списка\n";
        cout << "\t5. Из конца списка\n";
        cout << "\t6. Из произвольного места списка\n";
        cout << "\tПрочее:\n";
        cout << "\t7. Очистка списка\n";
        cout << "\t8. Вывод списка\n";
        cout << "\t9. Выход\n";
        cout << "\n\tВаш выбор --> ";       cin >> choice;      cout << '\n';


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


void Queue_Menu(int value, int position) {  //Очередь
    Queue queue = {};
    int choice = 0;
    bool flag = true;


    do {
        cout << "\n\t\t**** МЕНЮ ВЗАИМОДЕЙСТВИЯ С -ОЧЕРЕДЬЮ- ****\n";
        cout << "\t1. Добавление значения в конец очереди\n";
        cout << "\t2. Удаление значения из начала очереди\n";
        cout << "\t3. Удаление всех данных в очереди\n";
        cout << "\t4. Вывод всей очереди\n";
        cout << "\t5. Выход\n";
        cout << "\n\tВаш выбор --> ";       cin >> choice;      cout << '\n';


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


void Stack_Menu(int value, int position) {  //Стек
    Stack stack = {};
    int choice = 0;
    bool flag = true;


    do {
        cout << "\n\t\t**** МЕНЮ ВЗАИМОДЕЙСТВИЯ СО -СТЕКОМ- ****\n";
        cout << "\t1. Добавление значения в вершину\n";
        cout << "\t2. Удаление значения из вершины\n";
        cout << "\t3. Удаление всех данных\n";
        cout << "\t4. Вывод всего стека\n";
        cout << "\t5. Выход\n";
        cout << "\n\tВаш выбор --> ";   cin >> choice;      cout << '\n';


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