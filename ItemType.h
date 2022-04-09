#pragma once

#include"Node.h"
#include"line.h"

class ItemType {

	int currcomp;
	Node* curr;
	line l;

public:
	ItemType(){}
	ItemType(int currcomp, Node* curr, line l): currcomp(currcomp), curr(curr), l(l){}
	~ItemType() { }
	int getCurrComp() { return currcomp; }
	Node* getNode() { return curr; }
	line getLine() { return l; }
	void setCurrcomp(int x) { currcomp = x; }
	void setNode(Node* next) { curr = next; }
	void setLine(line newLine) { l = newLine; }
};
