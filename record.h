#pragma once
#include <string>

//RECORD CLASS

using namespace std;

class Record {

public:
	Record();
	void SetRecordID(int ID);
	void SetDescription(string dscrpt);
	void SetAmount(float cant);
	void SetNextRecord(Record* ptrToRecord);
	int GetRecordID();
	string GetDescription();
	float GetAmount();
	Record* GetNextRecordPtr();

private:
	int recordID;
	string description;
	float amount;
	Record* nextRecord;

};

//CONSTRUCTOR
Record::Record() {

	recordID = 0;
	description = "";
	amount = 0;
	nextRecord = NULL;

}

//CLASS METHODS DEFINITIONS
void Record::SetRecordID(int ID) {

	recordID = ID;

}

void Record::SetDescription(string dscrpt) {

	if (dscrpt.length() > 40) { //IF THE DESCRIPTION IS LONGER THAN 40 CHARACTERS
		dscrpt.resize(40);
	}

	description = dscrpt;

}

void Record::SetAmount(float cant) {

	if (cant <= 99999) { //TO AVOID PROBLEMS, cant CANNOT BE GREATER THAN 99999
		amount = cant;
	}

}

void Record::SetNextRecord(Record* ptrToRecord) {

	nextRecord = ptrToRecord;

}

int Record::GetRecordID() {
	
	return recordID;

}

string Record::GetDescription() {

	return description;

}

float Record::GetAmount() {

	return amount;

}

Record* Record::GetNextRecordPtr() {

	return nextRecord;

}