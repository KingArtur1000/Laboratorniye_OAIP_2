#pragma once

#include <iostream>
#include <string>

#include "Nodes.h"


using std::cin;
using std::cout;
using std::string;


class Stack {
	Stack_Node* top;
	int size = 0;
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	void push(int info);
	void pop();
	void clear();
	int peek() const;
	void print();
};


enum class Stack_operation {
	ADD_VALUE = 1,
	REMOVE_VALUE,
	CLEAR_STACK,
	PRINT_STACK,
	EXIT
};