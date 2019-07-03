#pragma once
#include "record.h"
#include <string>
#include <iostream>
#include <iomanip>

//LIST CLASS

using namespace std;

class List {

public:
	List();
	void SetListName(string name);
	void SetNextList(List* list);
	void SetListID(int ID);
	List* GetNextListPtr();
	Record* GetRecordByID(int ID);
	int GetListID();
	string GetListName();
	void AddNewRecord(string description,float amount);
	void DeleteRecord(int ID);
	void PrintList();
	int GetSize();

private:
	int size;
	int listID;
	string listName;
	Record* listBegin;
	Record* listEnd;
	List* nextList;
	void SetRecordsID();

};

//CONSTRUCTOR
List::List() {

	listName = "";
	listID = 1;
	size = 0;
	listBegin = NULL;
	listEnd = NULL;
	nextList = NULL;
}

//CLASS METHODS DEFINITIONS
void List::SetListName(string name) {

	if (name.length() > 40) { //IF THE NAME IS LONGER THAN 40 CHARACTERS
		name.resize(40);
	}

	listName = name;

}

void List::SetNextList(List* list) {

	nextList = list;

}

void List::SetListID(int ID) {

	listID = ID;

}

List* List::GetNextListPtr() {

	return nextList;

}

Record* List::GetRecordByID(int ID) {

	Record* currentRecord = listBegin;
	Record* record;

	while (currentRecord != NULL && currentRecord->GetRecordID() != ID) {
		currentRecord = currentRecord->GetNextRecordPtr();
	}

	record = currentRecord;

	return record; //THE FUNCTION RETURNS NULL IF THE RECORD WITH THE DETERMINED ID DOES NOT EXIST

}

int List::GetListID() {

	return listID;

}

string List::GetListName() {

	return listName;

}

int List::GetSize() {

	return size;

}

void List::AddNewRecord(string description, float amount) {

	Record* newRecord = new Record();

	if (newRecord != NULL) { //IF THERE IS ENOUGH MEMORY
		newRecord->SetDescription(description);
		newRecord->SetAmount(amount);

		if (listBegin == NULL) { //IF THE LIST IS EMPTY
			listBegin = newRecord;
			listEnd = newRecord->GetNextRecordPtr();
		}
		else {
			listEnd->SetNextRecord(newRecord);
			listEnd = newRecord->GetNextRecordPtr();
		}

		SetRecordsID(); //ID's ARE GIVEN TO THE RECORDS
		size++;
		cout << "Record has been added" << endl;
	}
	else {
		cout << "Error. Not enough memory." << endl;
	}

}

void List::DeleteRecord(int ID) {

	Record* tempRecord;
	Record* prevRecord;
	Record* currentRecord;

	if (listBegin != NULL) { //LIST IS NOT EMPTY
		if (listBegin->GetRecordID() == ID) { //IF IS THE FIRST RECORD
			tempRecord = listBegin;
			listBegin = listBegin->GetNextRecordPtr();
			cout << "Record with ID " << tempRecord->GetRecordID() << " has been deleted." << endl;
			delete tempRecord;
			SetRecordsID(); //REARRANGE
			size--;
		}
		else {
			prevRecord = listBegin;
			currentRecord = listBegin->GetNextRecordPtr();

			while (currentRecord != NULL && currentRecord->GetRecordID() != ID) {
				prevRecord = currentRecord;							//MOVE TO...
				currentRecord = currentRecord->GetNextRecordPtr();	//... THE NEXT NODE
			}

			if (currentRecord != NULL) {
				tempRecord = currentRecord;
				prevRecord->SetNextRecord(currentRecord->GetNextRecordPtr());
				cout << "Record with ID " << tempRecord->GetRecordID() << " has been deleted." << endl;
				delete tempRecord;
				SetRecordsID(); //REARRANGE
				size--;
			}
			else {
				cout << "The record with the specified ID does not exist" << endl;
			}
		}
	}
	else {
		cout << "The list is empty." << endl;
	}

}

void List::PrintList() {

	cout << setw(6) << left << "ID" << setw(42) << left << "Description"
		<< setw(8) << left << "Amount" << endl;

	Record* recordAux = listBegin;
	float sum = 0;

	while (recordAux != NULL) {
		cout << setw(6) << left << recordAux->GetRecordID() << setw(42) << left << recordAux->GetDescription()
			<< setw(8) << left << recordAux->GetAmount() << endl;

		sum += recordAux->GetAmount();
		recordAux = recordAux->GetNextRecordPtr();
	}

	cout << "Total: " << sum << endl;

}

void List::SetRecordsID() {

	int idCounter = 1;
	Record* currentRecord = listBegin;

	while (currentRecord != NULL) {
		currentRecord->SetRecordID(idCounter++);
		currentRecord = currentRecord->GetNextRecordPtr();
	}

}
