#include "Stack.h"


Stack::Stack() : top(nullptr) {}


Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}


bool Stack::isEmpty() const {
    return top == nullptr;
}


void Stack::push(int info) {
    Stack_Node* newNode = new Stack_Node;

    cout << "\tВведите значение для добавления --> ";      cin >> info;    cout << '\n';

    newNode->info = info;
    newNode->next = top;
    top = newNode;
}


void Stack::pop() {
    if (!isEmpty()) {
        Stack_Node* buffer = top;
        top = top->next;
        delete buffer;
    }
    else { cout << "\n\tСтек пуст!" << '\n'; }
}


void Stack::clear() {
    while (!isEmpty()) {
         Stack_Node* buffer = top;
         top = top->next;
         delete buffer;
    }
}


int Stack::peek() const {
    return (!isEmpty()) ? top->info : -1;
}


void Stack::print() {

    if (!isEmpty()) {
        string str = "";
        string cursor = " ---> ";
        string stdNullptr = "nullptr";

        cout << "\nStack: ";

        for (Stack_Node* buffer = top; buffer != nullptr; buffer = buffer->next) {
            cout << buffer->info << cursor;
        }

        cout << stdNullptr << '\n';
    }
    else { cout << "\n\tСтек пуст!" << '\n'; }

    
}