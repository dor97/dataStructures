#include "staticList.h"
#include<iostream>

using namespace std;

staticList::~staticList()
{
	for (int i = 0; i < 2; i++)
		delete arr[i];
	delete arr;
}
staticList::staticList(int size):headList(0), headFree(1)
{
	this->arr = new int*[2];
	for (int i = 0; i < 2; i++)
		arr[i] = new int[size+1];

	arr[1][0] = -1; // dummy head list
	for (int i = 1; i < size; i++)
	{
		arr[1][i] = i + 1;
	}
	arr[1][size] = -1; // initiating freeList


}
bool staticList::IsEmpty()
{
	return (this->headList == 0);
}
int staticList::First()
{
	return this->arr[0][headList];
}
void staticList::InsertAfter(int newData, int insertAfter)
{
	if (headFree == -1)
	{
		throw "Array is Full";
	}

	int newLoc = this->headFree;
	headFree = arr[1][headFree];
	arr[0][newLoc] = newData;
	arr[1][newLoc] = arr[1][insertAfter];
	arr[1][insertAfter] = newLoc;
}

void staticList::DeleteNode(int deletAfter)
{
	int newLoc = arr[1][deletAfter];
	arr[1][deletAfter] = arr[1][newLoc];
	arr[1][newLoc] = headFree;
	headFree = newLoc;
}

void staticList::Insert(int newData)
{
	InsertAfter(newData, 0);
}

void staticList::print()
{
	int i = arr[1][headList];
	while (i != -1)
	{
		cout << arr[0][i] << " ";
		i = arr[1][i];
	}
}