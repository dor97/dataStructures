
#include"List.h"

List::~List()
{
	MakeEmpty();
}

void List::DeleteList()
{
	Node* temp = head.DeleteAfter();

	while (temp != nullptr)
	{
		delete temp;
		Node* temp = head.DeleteAfter();
	}
}

void List::MakeEmpty()
{
	Node* temp = head.DeleteAfter();

	while (temp != nullptr)
	{
		delete temp;
		Node* temp = head.DeleteAfter();
	}
}

bool List::IsEmpty()
{
	return head.getNext() == nullptr;
}

Node* List::First()
{
	return head.getNext();
}

void List::InsertAfter(Node* x)
{
	head.InsertAfter(x);
}