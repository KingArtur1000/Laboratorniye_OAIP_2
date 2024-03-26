#pragma once

#include <iostream>
#include "Nodes.h"


using std::cin;
using std::cout;


enum class Dack_operation {
    PUSH_FRONT = 1,
    PUSH_BACK,
    INSERT,
    POP_FRONT,
    POP_BACK,
    ERASE,
    CLEAR_Dack,
    PRINT_Dack,
    EXIT
};


class Dack {
    Dack_Node* front;
    Dack_Node* back;
    int size = 0;

public:
    Dack();
    ~Dack();
    bool isEmpty() const;
    void pushFront(int info);
    void pushBack(int info);
    void insert(int info, int position);
    void popFront();
    void popBack();
    void erase(int position);
    void clear();
    void print();
};