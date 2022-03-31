
#include"List.h"
#include <iostream>
#include"staticList.h"

using namespace std;
List* setCountryStracture(int& cities);
void getToTown(List* countryStructure, int currComp, int* colores, staticList& accessible);
staticList creatAccessibleList(List* countryStructure, int cities, int currComp);

void main()
{
	int cities;
	List* countryStructure = setCountryStracture(cities);
	int currComp;

	cout << "please insert computer number: ";
	cin >> currComp;
	staticList accessible = creatAccessibleList(countryStructure, cities, currComp - 1);
	//accessible.print();
}

staticList creatAccessibleList(List* countryStructure, int cities, int currComp)
{
	staticList accessible(cities);
	int* colores = new int[cities];    // 0 - white   1 - black

	for (int i = 0; i < cities; ++i)
		colores[i] = 0;
	getToTown(countryStructure, currComp, colores, accessible);

	accessible.print();
	delete colores;
	return accessible;
}

void getToTown(List* countryStructure, int currComp, int* colores, staticList& accessible)
{
	colores[currComp] = 1;
	accessible.Insert(currComp + 1);
	Node* curr = countryStructure[currComp].First();

	while (curr != nullptr)
	{
		if (colores[curr->getData() - 1] == 0)
			getToTown(countryStructure, curr->getData() - 1, colores, accessible);
		curr = curr->getNext();
	}
}


List* setCountryStracture(int& cities)
{
	int roads;
	int first, second;
	List* cs;

	cout << "please insert number of cities, and roads: " << endl;
	cin >> cities >> roads;

	//if (cities > 0)
	//{
	cs = new List[cities];
	//}
	

	cout << "Please insert" << roads << " connections";

	for (int i = 0; i < roads; i++)
	{
		cin >> first >> second;
		Node* toInsert = new Node(second);
		cs[first - 1].InsertAfter(toInsert);   // implement!!
	}

	return cs;
}