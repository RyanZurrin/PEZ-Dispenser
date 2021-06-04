#pragma once

#include <iostream>
#include "StackInterface.h"

inline Stack::Stack()
{
	qty = 0;
	max = 1024;
	topPtr = NULL;
}

inline Stack::Stack(int maxSize)
{
	qty = 0;
	max = maxSize;
	topPtr = NULL;
}

inline Stack::~Stack()
{
	makeEmpty();
}

inline bool Stack::push(int num)
{
	Node* temp;
	if (isFull())
	{
		return false;
	}
	temp = new Node;
	temp->val = num;
	temp->next = topPtr;
	topPtr = temp;
	qty++;
	return true;
}

inline bool Stack::pop(int& num)
{
	Node* temp;
	if (isEmpty())
	{
		num = -1;
		return false;
	}
	temp = topPtr;
	topPtr = topPtr->next;
	num = temp->val;
	delete temp;
	qty--;
	return true;
}

inline bool Stack::peek(int& num)const
{
	if (isEmpty())
	{
		return false;
	}
	num = topPtr->val;
	return true;
}

inline bool Stack::isEmpty()const
{
	if (topPtr == NULL)
	{
		return true;
	}
	return false;
}

inline bool Stack::isFull()const
{
	if (qty >= max)
	{
		return true;
	}
	return false;
}

inline bool Stack::makeEmpty()
{
	Node* temp;
	if (isEmpty())
	{
		return false;
	}
	while (topPtr != NULL)
	{
		temp = topPtr;
		topPtr = topPtr->next;
		delete temp;
	}
	qty = 0;
	return true;
}
inline int Stack::getQty()const
{
	return qty;
}
