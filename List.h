#pragma once

#include "Node.h"

class List {

	Node head;

public:
	List(){}
	~List();
	void DeleteList();
	void MakeEmpty();
	bool IsEmpty();
	Node* First();
	int Last();
	int Find(int x);
	void InsertAfter(Node* x);
	void DeleteNode();
	void Print();

};