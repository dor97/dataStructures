#pragma once

#include "Node.h"

class List {

	Node* head = new Node();

public:
	List(){}
	~List();
	void DeleteList();
	void MakeEmpty();
	bool IsEmpty();
	Node* First();
	int Last();
	bool Find(int x);
	void InsertAfter(Node* x);
	void DeleteNode();
	void Print();

};