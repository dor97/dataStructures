#pragma once

#include"StackNode.h"

class StackList {

	StackNode head;

public:
	StackList() {}
	~StackList();
	void DeleteList();
	void MakeEmpty();
	bool IsEmpty();
	StackNode* First();
	int Last();
	int Find(int x);
	void Insert(StackNode* x);
	StackNode* DeleteNode();
	void Print();

};
