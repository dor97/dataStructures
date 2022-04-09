
#include"StackList.h"

StackList::~StackList()
{
	MakeEmpty();
}

void StackList::DeleteList()
{
	StackNode* temp = head.DeleteAfter();

	while (temp != nullptr)
	{
		delete temp;
		StackNode* temp = head.DeleteAfter();
	}
}

void StackList::MakeEmpty()
{
	StackNode* temp = head.DeleteAfter();

	while (temp != nullptr)
	{
		delete temp;
		StackNode* temp = head.DeleteAfter();
	}
}

bool StackList::IsEmpty()
{
	return head.getNext() == nullptr;
}

StackNode* StackList::First()
{
	return head.getNext();
}

void StackList::Insert(StackNode* x)
{
	head.InsertAfter(x);
}

StackNode* StackList::DeleteNode()
{	
	return head.DeleteAfter();
}