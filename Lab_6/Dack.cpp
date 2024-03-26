#include "Dack.h"


Dack::Dack() : front(nullptr), back(nullptr), size(0) {}


Dack::~Dack() {
    clear();
}


bool Dack::isEmpty() const {
    return front == nullptr;
}


void Dack::pushFront(int info) {
    Dack_Node* newDack_Node = new Dack_Node;

    cout << "\tВведите значение --> ";     cin >> info;     cout << '\n';

    newDack_Node->info = info;
    newDack_Node->next = front;
    newDack_Node->prev = nullptr;

    if (isEmpty()) {
        back = newDack_Node;
    }
    else {
        front->prev = newDack_Node;
    }

    front = newDack_Node;
    size++;
}


void Dack::pushBack(int info) {
    Dack_Node* newDack_Node = new Dack_Node;

    cout << "\tВведите значение --> ";     cin >> info;     cout << '\n';

    newDack_Node->info = info;
    newDack_Node->next = nullptr;
    newDack_Node->prev = back;

    if (isEmpty()) {
        front = newDack_Node;
    }
    else {
        back->next = newDack_Node;
    }

    back = newDack_Node;
    size++;
}


void Dack::insert(int info, int position) {
    cout << "\tВведите значение --> ";        cin >> info;         cout << '\n';
    cout << "\tВведите позицию --> ";         cin >> position;     cout << '\n';

    if (position < 0 || position > size) {
        cout << "\n\tНеверный индекс!" << '\n';
        return;
    }

    if (position == 0) {
        pushFront(info);
    }
    else if (position == size) {
        pushBack(info);
    }
    else {
        Dack_Node* newDack_Node = new Dack_Node;
        newDack_Node->info = info;

        Dack_Node* current = front;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }

        newDack_Node->next = current->next;
        newDack_Node->prev = current;
        current->next->prev = newDack_Node;
        current->next = newDack_Node;
        size++;
    }
}


void Dack::popFront() {
    if (!isEmpty()) {
        Dack_Node* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        }
        else {
            back = nullptr;
        }
        delete temp;
        size--;
    }
}


void Dack::popBack() {
    if (!isEmpty()) {
        Dack_Node* temp = back;
        back = back->prev;
        if (back != nullptr) {
            back->next = nullptr;
        }
        else {
            front = nullptr;
        }
        delete temp;
        size--;
    }
}


void Dack::erase(int position) {
    cout << "\tВведите позицию --> ";      cin >> position;    cout << '\n';

    if (isEmpty() || position < 0 || position >= size) {
        cout << "\n\tНеверный индекс!" << '\n';
        return;
    }

    if (position == 0) {
        popFront();
    }
    else if (position == size - 1) {
        popBack();
    }
    else {
        Dack_Node* current = front;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
}


void Dack::clear() {
    while (!isEmpty()) {
        popFront();
    }
}


void Dack::print() {
    if (isEmpty()) {
        cout << "\n\tДек пуст!" << '\n';
    }
    else {
        cout << "\n\tДек: ";
        for (Dack_Node* current = front; current != nullptr; current = current->next) {
            cout << current->info;
            if (current->next != nullptr) {
                cout << " <---> ";
            }
        }
        cout << '\n';
    }
}