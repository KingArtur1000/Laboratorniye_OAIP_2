#include "Queue.h"


Queue::Queue() : front(nullptr), back(nullptr), size(0) {}


Queue::~Queue() {
    clear();
}


bool Queue::isEmpty() const {
    return front == nullptr;
}


void Queue::enqueue(int info) {
    Queue_Node* newQueue = new Queue_Node;

    cout << "\tВведите значение для добавления --> ";  cin >> info; cout << '\n';

    newQueue->info = info;
    newQueue->next = nullptr;

    if (isEmpty()) {
        front = back = newQueue;
    }
    else {
        back->next = newQueue;
        back = newQueue;
    }

    size++;
}


void Queue::dequeue() {
    if (!isEmpty()) {
        if (!isEmpty()) {
            Queue_Node* temp = front;
            front = front->next;
            delete temp;
            size--;

            if (front == nullptr) {
                back = nullptr;
            }
        }
    }
    else { cout << "\n\tОчередь пуста!" << '\n'; }
    
}


void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}


void Queue::print() {
    if (!isEmpty()) {
        if (isEmpty()) {
            cout << "\n\tОчередь пуста!." << '\n';
        }
        else {
            cout << "\n\tОчередь: ";
            for (Queue_Node* current = front; current != nullptr; current = current->next) {
                cout << current->info << " ";
                if (current->next != nullptr)
                    cout << "<--- ";
            }
            cout << '\n';
        }
    }
    else { cout << "\n\tОчередь пуста!" << '\n'; }
}