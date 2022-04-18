
#include"List.h"

List::~List()
{
	MakeEmpty();
	delete head;
}

void List::DeleteList()
{
	Node* temp = head->DeleteAfter();

	while (temp != nullptr)
	{
		delete temp;
		temp = head->DeleteAfter();
	}
}

void List::MakeEmpty()
{
	Node* temp = head->DeleteAfter();

	while (temp != nullptr)
	{
			delete temp;
			temp = head->DeleteAfter();
	}
}

bool List::IsEmpty()
{
	return head->getNext() == nullptr;
}

Node* List::First()
{
	return head->getNext();
}

void List::InsertAfter(Node* x)
{
	head->InsertAfter(x);
}

bool List::Find(int x)
{
	Node* curr = head->getNext();
	while (curr)
	{
		if (curr->getData() == x)
			return true;
		curr = curr->getNext();
	}
	return false;
}