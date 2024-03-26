#pragma once

#include <iostream>
#include "Nodes.h"


using std::cin;
using std::cout;


enum class Queue_operation {
    ADD_VALUE = 1,
    REMOVE_VALUE,
    CLEAR_QUEUE,
    PRINT_QUEUE,
    EXIT
};


class Queue {
    Queue_Node* front;
    Queue_Node* back;
    int size = 0;

public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    void enqueue(int info);
    void dequeue();
    void clear();
    void print();
};