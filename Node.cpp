
#include "Node.h"

void Node::InsertAfter(Node* newnode)
{
	newnode->next = next;
	next = newnode;
}

Node* Node::DeleteAfter()
{
	Node* toDelete = next;

	if (toDelete == nullptr)
		return nullptr;
	next = toDelete->next;
	return toDelete;
}

Node* Node::getNext()
{
	return next;
}

int Node::getData()
{
	return data;
}