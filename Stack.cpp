
#include"Stack.h"

ItemType Stack::Top()
{
	return list.First()->getData();

}

bool Stack::IsEmpty()
{
	return list.IsEmpty();
}

void Stack::push(ItemType& data)
{
	StackNode* newNode = new StackNode(data);
	list.Insert(newNode);
}


ItemType Stack::pop()
{
	StackNode* toDelete = list.DeleteNode();
	ItemType toReturn = toDelete->getData();
	delete toDelete;
	return toReturn;
}

void Stack::makeEmpty()
{
	list.MakeEmpty();
}