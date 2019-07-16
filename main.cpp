#include <iostream>
#include <string>
#include "record.h"
#include "list.h"
#include "index.h"

using namespace std;

//FUNCTION PROTOTYPES
void ShowViewMenu();
void ShowManageMenu();
void EditList(Index* index);
void EditListName(List* list);
void AddRecord(List* list);
void EditRecord(List* list);
void EditRecordDescrp(Record* record);
void EditRecordAmount(Record* record);
void DeleteRecord(List* list);
void AddList(Index* index);
void DeleteList(Index* index);

typedef Index* INDEX_PTR;

INDEX_PTR mainIndex = new Index();	//mainIndex IS CREATED

void main() {

	mainIndex->ListPush("Incomes");		//"INCOMES" AND...
	mainIndex->ListPush("Expenses");	//... "EXPENSES" DEFAULT LISTS ARE CREATED AND ADDED

	char option;

	do {

		//MAIN MENU

		option = '0';

		system("cls");

		cout << "Income and Expenses Manager" << endl << endl
			<< "Select and option" << endl
			<< "1) View lists" << endl
			<< "2) Lists Management" << endl
			<< "3) Exit" << endl
			<< "?.-";
		cin >> option;

		switch (option) {
		case '1':
			ShowViewMenu();
			break;
		case '2':
			ShowManageMenu();
			break;
		case '3':
			exit(0);
			break;
		default:
			cout << "Error. Invalid option." << endl;
			system("pause");
		}

	} while (option != '3');

}

//FUNCTION DEFINITIONS

void ShowViewMenu() {

	char id;
	int ID;
	List* listAuxPtr = NULL;

	do {

		id = '0';

		system("cls");

		cout << "View Menu" << endl << endl
			<< "What list you want to open?" << endl;
		mainIndex->PrintIndex();

		if (mainIndex != NULL) { //IF mainIndex IS NOT EMPTY
			cout << "?- ";
			cin >> id; //USER CHOICE IS ENTERED
			ID = id - '0'; //CONVERSION TO INTEGER

			listAuxPtr = mainIndex->GetListByID(ID);

			if (listAuxPtr != NULL) {
				listAuxPtr->PrintList();
			}
			else {
				cout << "Error. Invalid option." << endl;
			}
		}

		system("pause");

	} while (listAuxPtr == NULL); //WHILE INVALID OPTION

}

void ShowManageMenu() {

	char option;

	do {

		option = '0';

		system("cls");

		cout << "Lists Management Menu" << endl << endl
			<< "1) Add a list" << endl
			<< "2) Edit a list" << endl
			<< "3) Delete a list" << endl
			<< "4) Go back" << endl
			<< "?- ";
		cin >> option;

		switch (option) {
		case '1':
			AddList(mainIndex);
			break;
		case '2':
			EditList(mainIndex);
			break;
		case '3':
			DeleteList(mainIndex);
			break;
		case '4':
			break;
		default:
			cout << "Error. Invalid option." << endl;
			system("pause");
		}

	} while (option != '4');

}

void EditList(Index* index) {

	char id, option;
	int ID;
	List* listAuxPtr = NULL;

	do {

		id = option = '0';

		system("cls");

		cout << "Edit Menu" << endl << endl
			<< "What list you want to edit?" << endl;
		index->PrintIndex();

		if (index != NULL) { //IF index IS NOT EMPTY
			cout << "?- ";
			cin >> id; //USER CHOICE IS ENTERED
			ID = id - '0'; //CONVERSION TO INTEGER

			listAuxPtr = index->GetListByID(ID);

			if (listAuxPtr != NULL) {
				
				system("cls");

				cout << "What do you want to edit?" << endl
					<< "1) Add a record" << endl
					<< "2) Delete a record" << endl
					<< "3) Edit a record" << endl
					<< "4) Edit list name" << endl
					<< "5) Cancel" << endl
					<< "?- ";
				cin >> option;

				switch (option) {
				case '1':
					AddRecord(listAuxPtr);
					break;
				case '2':
					DeleteRecord(listAuxPtr);
					break;
				case '3':
					EditRecord(listAuxPtr);
					break;
				case '4':
					EditListName(listAuxPtr);
					break;
				case '5':
					break;
				default:
					cout << "Error. Invalid option." << endl;
				}

			}
			else {
				cout << "Error. Invalid option." << endl;
			}
		}

	} while (listAuxPtr == NULL); //WHILE INVALID OPTION

}

void AddRecord(List* list) {

	cin.ignore(); //clear buffer

	system("cls");

	string auxDescription;
	float auxAmount;

	cout << "Enter the record description:" << endl
		<< "?- ";
	getline(cin, auxDescription);
	
	cout << "Enter the record amount" << endl
		<< "?- ";
	cin >> auxAmount;

	list->AddNewRecord(auxDescription, auxAmount);
	system("pause");

}

void EditRecord(List* list) {

	if (list->GetSize() > 0) { //IF LIST IS NOT EMPTY

		char id, option;
		int ID;
		Record* recordAuxPtr;

		do {

			id = option = '0';

			system("cls");

			list->PrintList();

			cout << "What record do you want to edit?" << endl
				<< "?- ";
			cin >> id;
			ID = id - '0'; //CONVERSION TO INTEGER

			recordAuxPtr = list->GetRecordByID(ID);

			if (recordAuxPtr != NULL) { //IF THE RECORD EXITS

				do {

					system("cls");

					cout << "What do you want to edit?" << endl
						<< "1) Description" << endl
						<< "2) Amount" << endl
						<< "3) Cancel" << endl
						<< "?- ";
					cin >> option;

					switch (option) {
					case '1':
						EditRecordDescrp(recordAuxPtr);
						break;
					case '2':
						EditRecordAmount(recordAuxPtr);
						break;
					case '3':
						break;
					default:
						cout << "Error. Invalid Option." << endl;
					}

				} while (option != '3');

			}
			else {
				cout << "Error. Invalid option." << endl;
			}

		} while (recordAuxPtr == NULL); //WHILE INVALID OPTION

	}
	else {
		cout << "The list is empty." << endl;
		system("pause");
	}

}

void EditRecordDescrp(Record* record) {

	cin.ignore();

	system("cls");

	cout << "Enter the new record description" << endl
		<< "?.-";
	string description;
	getline(cin, description);

	record->SetDescription(description);

	cout << "Description updated successfully" << endl;
	system("pause");

}

void EditRecordAmount(Record* record) {

	cin.ignore();

	system("cls");

	cout << "Enter the new amount" << endl
		<< "?.-";
	float amount;
	cin >> amount;

	record->SetAmount(amount);

	cout << "Amount updated successfully" << endl;
	system("pause");

}

void DeleteRecord(List* list) {

	if (list->GetSize() > 0) { //IF LIST IS NOT EMPTY

		char id;
		int ID;
		Record* recordAuxPtr;

		do {

			id = '0';

			system("cls");

			list->PrintList();

			cout << "What record do you want to delete?" << endl
				<< "?- ";
			cin >> id;
			ID = id - '0'; //CONVERSION TO INTEGER

			recordAuxPtr = list->GetRecordByID(ID);

			list->DeleteRecord(ID);

		} while (recordAuxPtr == NULL); //WHILE THE RECORD DOES NOT EXIST

	}
	else {
		cout << "The list is empty." << endl;
	}

	system("pause");

}

void AddList(Index* index) {

	cin.ignore(); //clear buffer

	system("cls");

	string nameAux;

	cout << "What is the name of the new list?" << endl
		<< "?- ";
	getline(cin, nameAux);

	index->ListPush(nameAux);

	cout << "The list " << nameAux << " has been created" << endl;
	system("pause");

}

void DeleteList(Index* index){

	char id;
	int ID;
	List* listAuxPtr = NULL;

	do {
		
		id = '0';

		system("cls");

		cout << "Select the list to be deleted:" << endl << endl;
		index->PrintIndex();
		
		if (index->GetIndexTop() != NULL) { //IF mainIndex IS NOT EMPTY
			cout << "?- ";
			cin >> id;
			ID = id - '0'; //CONVERSION TO INTEGER

			listAuxPtr = index->GetListByID(ID);

			index->ListDelete(ID);
			system("pause");
		}
		else {
			system("pause");
			break; //BREAK THE DO WHILE IF INDEX IS EMPTY
		}

	} while (listAuxPtr == NULL); //WHILE INVALID OPTION / LIST DOES NOT EXIST

}

void EditListName(List* list) {

	cin.ignore();

	system("cls");

	cout << "Enter the new name" << endl
		<< "?.-";
	string name;
	getline(cin, name);

	list->SetListName(name);

	cout << "Name updated successfully" << endl;
	system("pause");

}