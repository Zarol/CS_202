#include "Project13Classes.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;


bool readIn(string, ListN&);
bool SelectionSort(ListN&);
int BinarySearch(ListA, int, int, int);

int main()
{
	ListN nodeList = ListN(-1);
	readIn("numbers", nodeList);
	cout << "Unsorted:" << endl;
	cout << nodeList << endl;
	SelectionSort(nodeList);

	ListA arrList = ListA(100);
	nodeList.gotoBeginning();
	for(int i = 0; i < 100; i++)
	{
		int temp = 0;
		nodeList.getCursor(temp);
		arrList.insertAfter(temp);
		nodeList.gotoNext();
	}
	cout << "Sorted:" << endl;
	cout << arrList << endl;

	int userSearch = 0;
	do
	{
		cout << "Enter the number to search for from 0 to 999 (-1 to exit): ";
		cin >> userSearch;
		cout << "Index at: " << BinarySearch(arrList, userSearch, 0, 100) << endl;
		cout << endl;
	} while(userSearch != -1);
	return 1;
}

bool readIn(string fileName, ListN& list)
{
	ifstream ifs;
	ifs.open(fileName.c_str());
	if(ifs.is_open())
	{
		while(ifs.good())
		{
			int temp;
			ifs >> temp;
			list.insertAfter(temp);
		}
		return true;
	}
	else
		return false;
}

bool SelectionSort(ListN& source)
{
	for(Node *i = source.head; i->next != NULL; i = i->next)
		for(Node *select = i->next; select != NULL; select = select->next)
			if(i->data > select->data)
			{
				int temp = i->data;
				i->data = select->data;
				select->data = temp;
			}
}

int BinarySearch(ListA list, int key, int left, int right)
{
	int index;
	if(left > right)
		index = -1;
	else
	{
		int midpoint = (left + right) / 2;
		list.gotoBeginning();
		for(int i = 0; i < midpoint; i++)
			list.gotoNext();
		int compare;
		list.getCursor(compare);
		if (key == compare)
			index = midpoint;
		else
			if(key < compare)
				index = BinarySearch(list, key, left, midpoint - 1);
			else
				index = BinarySearch(list, key, midpoint + 1, right);
	}
	return index;
}
