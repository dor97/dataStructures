#pragma once

class Node {
	int data;
	Node* next;

public:
	Node():next(nullptr), data(-1){}
	Node(int x, Node* ptr = nullptr): data(x), next(ptr){}
	~Node() { }
	void InsertAfter(Node* newnode);
	Node* DeleteAfter();
	Node* getNext();
	int getData();

};
