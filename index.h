#pragma once
#include "list.h"
#include <iostream>
#include <string>

//INDEX CLASS

using namespace std;

class Index {

public:
	Index();
	void ListPush(string name);
	void ListDelete(int ID);
	void PrintIndex();
	List* GetIndexTop();
	List* GetListByID(int ID);
	int GetSize();

private:
	List* indexTop;
	int size;
	void SetListsID();

};

//CONSTRUCTOR
Index::Index() {

	indexTop = NULL;
	size = 0;

}

//CLASS METHODS DEFINITIONS
void Index::ListPush(string name) {

	List* newList = new List();

	if (newList != NULL) {

		newList->SetListName(name);

		if (indexTop == NULL) { //IF THE PILE IS EMPTY
			indexTop = newList;
		}
		else {
			newList->SetNextList(indexTop);
			indexTop = newList;
		}

		SetListsID(); //ARRANGE BY ID
		size++;
	}
	else {
		cout << "Error. Not enough memory" << endl;
	}

}

void Index::ListDelete(int ID) {

	List* tempList;
	List* prevNode;
	List* currentNode;

	if (indexTop != NULL) { //IF INDEX IS NOT EMPTY
		if (indexTop->GetListID() == ID) { //IF IS THE FIRST IN THE LIST
			tempList = indexTop;
			indexTop = indexTop->GetNextListPtr();
			cout << tempList->GetListName() << " has been deleted." << endl;
			delete tempList;
			SetListsID(); //REARRANGE
			size--;
		}
		else {
			prevNode = indexTop;
			currentNode = indexTop->GetNextListPtr();

			while (currentNode != NULL && currentNode->GetListID() != ID) {
				prevNode = currentNode;							//MOVE TO...
				currentNode = currentNode->GetNextListPtr();	//...THE NEXT NODE
			}

			if (currentNode != NULL) {
				tempList = currentNode;
				prevNode->SetNextList(currentNode->GetNextListPtr());
				cout << tempList->GetListName() << " has been deleted." << endl;
				delete tempList;
				SetListsID(); //REARRANGE
				size--;
			}
			else {
				cout << "The list with the specified ID does not exit." << endl;
			}
		}
	}
	else {
		cout << "The index is empty." << endl;
	}

}

void Index::SetListsID() {

	int idCounter = 1;
	List* currentList = indexTop;

	while (currentList != NULL) {
		currentList->SetListID(idCounter++);
		currentList = currentList->GetNextListPtr();
	}

}

void Index::PrintIndex() {

	List* currentList;
	int id;
	string name;

	if (indexTop != NULL) { //IF THE INDEX IS NOT EMPTY
		currentList = indexTop;
		
		while (currentList != NULL) {
			id = currentList->GetListID();
			name = currentList->GetListName();

			cout << id << ") " << name << endl;

			currentList = currentList->GetNextListPtr();
		}
	}
	else {
		cout << "There is not any list." << endl;
	}

}

List* Index::GetIndexTop() {

	return indexTop;

}

List* Index::GetListByID(int ID) {

	List* currentIndexElement = indexTop;
	List* list;

	while (currentIndexElement != NULL && currentIndexElement->GetListID() != ID) {
		currentIndexElement = currentIndexElement->GetNextListPtr();
	}

	list = currentIndexElement;

	return list; //THE FUNCTION RETURNS NULL IF THE LIST WITH THE DETERMINED ID DOES NOT EXIST

}

int Index::GetSize() {

	return size;

}
