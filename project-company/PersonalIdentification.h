#pragma once

#ifndef __PERSONALIDENTIFICATION_H__

#include"FullName.h"

#include<fstream>

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

#define __PERSONALIDENTIFICATION_H__

#define SIZE_OF_ADRESS 101

class PersonalIdentification
{
private:

	FullName name;
	char adress[SIZE_OF_ADRESS];
	unsigned int egn[10];

public:

	PersonalIdentification();
	PersonalIdentification(const FullName newName, const char* newAdress, const unsigned int *newEgn);
	PersonalIdentification(const PersonalIdentification& other);
	//~PersonalIdentification();

	FullName getFullName() const;
	const char* getAdress() const;
	const unsigned int* getEgn() const;

	void setFullName(const FullName newName);
	void setAdress(char* newAdress = "\0");
	void setEgn(unsigned int* newEgn);

	bool operator == (const PersonalIdentification& other);
	PersonalIdentification& operator = (const PersonalIdentification& other);

	void insertPersonalIdentification();
	void insertPersonalIdentificationFromFile(istream &in);
	void printPersonalIdentification() const;
	void printPersonalIdentificationOnFile(ostream &out) const;
};

#endif
