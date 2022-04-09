#pragma once

#include"ItemType.h"
#include"StackList.h"

class Stack {

	StackList list;

public:
	Stack(){}
	~Stack() { makeEmpty(); }
	ItemType Top();
	bool IsEmpty();
	void push(ItemType& data);
	ItemType pop();
	void makeEmpty();

};
