#pragma once

#include"ItemType.h"

class StackNode {
	ItemType data;
	StackNode* next = nullptr;

public:
	StackNode() :next(nullptr), data(-1, nullptr, line::start) {}
	StackNode(ItemType x, StackNode* ptr = nullptr) : data(x), next(ptr) {}
	~StackNode() {}
	void InsertAfter(StackNode* newnode);
	StackNode* DeleteAfter();
	StackNode* getNext();
	ItemType getData();

};