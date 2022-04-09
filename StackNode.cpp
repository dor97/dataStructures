
#include"StackNode.h"

void StackNode::InsertAfter(StackNode* newnode)
{
	newnode->next = next;
	next = newnode;
}

StackNode* StackNode::DeleteAfter()
{
	StackNode* toDelete = next;

	if (toDelete == nullptr)
		return nullptr;
	next = toDelete->next;
	return toDelete;
}

StackNode* StackNode::getNext()
{
	return next;
}

ItemType StackNode::getData()
{
	return data;
}