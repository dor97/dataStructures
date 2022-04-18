
#include"List.h"
#include <iostream>
#include"Stack.h"
#include"staticList.h"



using namespace std;
List* setCountryStracture(float& cities);
void getToTown(List* countryStructure, int currComp, int* colores, staticList& accessible);
void creatAccessibleList(List* countryStructure, int cities, int currComp, staticList& accessibleRec, staticList& accessible);
void getToTownNoRec(List* countryStructure, int currComp, int* colores, staticList& accessible);

void main()
{
	try{
		float cities;
		List* countryStructure = setCountryStracture(cities);
		float currComp;

		cout << "please insert computer number: ";
		cin >> currComp;
		if (currComp <= 0 || currComp > cities || (currComp - int(currComp)) != 0)
		{
			delete[] countryStructure;
			throw("invalid input");
		}
		staticList accessibleRec(cities);
		staticList accessible(cities);
		creatAccessibleList(countryStructure, cities, currComp - 1, accessibleRec, accessible);
		cout << "Cities accessible from source city" << currComp << "(recursive algorithm): ";
		accessibleRec.print();
		cout << endl << "Cities accessible from source city" << currComp << "(iterative algorithm): ";
		accessible.print();
		delete[] countryStructure;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

void creatAccessibleList(List* countryStructure, int cities, int currComp , staticList & accessibleRec, staticList& accessible)
{
	//staticList accessible(cities);
	int* coloresRec = new int[cities];	// 0 - white   1 - black
	int* colores = new int[cities];

	for (int i = 0; i < cities; ++i)
	{
		coloresRec[i] = 0;
		colores[i] = 0;
	}
	getToTown(countryStructure, currComp, coloresRec, accessibleRec);
	getToTownNoRec(countryStructure, currComp, colores, accessible);

	delete coloresRec;
	delete colores;
}

void getToTown(List* countryStructure, int currComp, int* colores, staticList& accessibleRec)
{
	colores[currComp] = 1;
	//accessible.Insert(currComp + 1);
	Node* curr = countryStructure[currComp].First();

	while (curr != nullptr)
	{
		if (colores[curr->getData() - 1] == 0)
			getToTown(countryStructure, curr->getData() - 1, colores, accessibleRec);
		curr = curr->getNext();
	}
	accessibleRec.Insert(currComp + 1);
}

void getToTownNoRec(List* countryStructure, int currComp, int* colores, staticList& accessible)
{
	Stack S;
	int returnFromRecursion = 0;
	ItemType curr(currComp, countryStructure[currComp].First(), line::start);

	do {
		if (returnFromRecursion)
			curr = S.pop();
		if (curr.getLine() == line::start)
		{
			if (curr.getNode() == nullptr)
			{
				colores[curr.getCurrComp()] = 1;
				curr.setNode(countryStructure[curr.getCurrComp()].First());
				accessible.Insert(curr.getCurrComp() + 1);
				returnFromRecursion = 1;
			}
			else if (colores[(curr.getNode()->getData()) - 1] == 1)
			{
				curr.setNode(curr.getNode()->getNext());
				curr.setLine(line::start());
			}
			else
			{
				curr.setLine(line::after_first);
				S.push(curr);
				colores[curr.getCurrComp()] = 1;
				curr.setCurrcomp((curr.getNode()->getData()) - 1);
				curr.setNode(countryStructure[curr.getCurrComp()].First());
				returnFromRecursion = 0;
				curr.setLine(line::start());
			}
		}
		else if (curr.getLine() == line::after_first)
		{
			curr.setLine(line::after_second);
			S.push(curr);
			//curr.setCurrcomp((curr.getNode()->getData()) - 1);
			curr.setNode(curr.getNode()->getNext());
			returnFromRecursion = 0;
			curr.setLine(line::start);
		}
		else if (curr.getLine() == line::after_second)
		{
			returnFromRecursion = 1;
			//accessible.Insert(curr.getCurrComp() + 1);
		}

	} while (!S.IsEmpty());

}

List* setCountryStracture(float& cities)
{
	float roads;
	int first, second;
	List* cs;

	cout << "please insert number of cities, and roads: " << endl;
	cin >> cities >> roads;

	if (cities <= 0 || cities - int(cities) != 0 || roads < 0 || roads - int(roads) != 0 || roads > cities * (cities - 1))
		throw("invalid input");

	cs = new List[cities];
	//delete cs;
	

	cout << "Please insert" << roads << " connections";

	for (int i = 0; i < roads; i++)
	{
		cin >> first >> second;
		if (first <= 0 || first > cities || second <= 0 || second > cities || cs[first - 1].Find(second))
		{
			delete[] cs;
			throw("invalid input");
		}
		Node* toInsert = new Node(second);
		cs[first - 1].InsertAfter(toInsert);   
	}
	if (getchar() != '\n')
	{
		delete[] cs;
		throw("invalid input");
	}

	return cs;
}