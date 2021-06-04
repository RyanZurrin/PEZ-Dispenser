#pragma once

#ifndef STACK_H
#define STACK_H
#include "Node.h"

class Stack
{
public:
	Stack();
	Stack(int);
	~Stack();
	bool push(int);
	bool pop(int&);
	bool peek(int&)const;
	bool isEmpty()const;
	bool isFull()const;
	bool makeEmpty();
	int getQty()const;

private:
	Node* topPtr;
	int qty;
	int max;
};

#endif