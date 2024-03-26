#pragma once


struct Dack_Node {
    int info = 0;
    Dack_Node* next = nullptr;
    Dack_Node* prev = nullptr;
};

struct Queue_Node {
    int info = 0;
    Queue_Node* next = nullptr;
};

struct Stack_Node {
    int info = 0;
    Stack_Node* next = nullptr;
};