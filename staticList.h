#pragma once

#include "Node.h"

class staticList {

	int** arr;
	int headList;
	int headFree;

public:
	staticList(int size);
	~staticList();
	void DeleteList();
	void MakeEmpty();
	bool IsEmpty();
	int First();
	int Last();
	int Find(int x);
	void InsertAfter(int newData, int insertAfter);
	void DeleteNode(int deletAfter);
	void Insert(int newData);
	void print();

};