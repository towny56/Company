#include "stdafx.h"
#include"FullName.h"

#include<iostream>
#include<string.h>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

FullName::FullName()
{
	firstName[0] = '\0';
	secondName[0] = '\0';
	thirdName[0] = '\0';
}

FullName::FullName(const char* newFirstName, const char* newSecondName, const char* newThirdName)
{
	strcpy_s(this->firstName, strlen(newFirstName) + 1, newFirstName);
	strcpy_s(this->secondName, strlen(newSecondName) + 1, newSecondName);
	strcpy_s(this->thirdName, strlen(newThirdName) + 1, newThirdName);
}

FullName::FullName(const FullName &other)
{
	strcpy_s(this->firstName, other.firstName);
	strcpy_s(this->secondName, other.secondName);
	strcpy_s(this->thirdName, other.thirdName);
}

const char* FullName::getFirstName() const
{
	return this->firstName;
}

const char* FullName::getSecondName() const
{
	return this->secondName;
}

const char* FullName::getThirdName() const 
{
	return this->thirdName;
}

void FullName::setFirstName(const char *newFirstName)
{
	strcpy_s(this->firstName, newFirstName);
}

void FullName::setSecondName(const char *newSecondName)
{
	strcpy_s(this->secondName, newSecondName);
}

void FullName::setThirdName(const char *newThirdName)
{
	strcpy_s(this->thirdName, newThirdName);
}

bool FullName::operator == (const FullName &other)
{
	return (strcmp(this->firstName, other.firstName) == 0 &&
		    strcmp(this->secondName, other.secondName) == 0 &&
		    strcmp(this->thirdName, other.thirdName) == 0);
}

FullName& FullName::operator = (const FullName &other)
{
	strcpy_s(this->firstName, other.firstName);
	strcpy_s(this->secondName, other.secondName);
	strcpy_s(this->thirdName, other.thirdName);

	return *this;
}

void FullName::insertFullName()
{
	char current[SIZE_OF_NAMES];

	cout << "(first name)" << endl;
	cin.getline(current, SIZE_OF_NAMES - 1);
	this->setFirstName(current);

	cout << "(second name)" << endl;
	cin.getline(current, SIZE_OF_NAMES - 1);
	this->setSecondName(current);

	cout << "(third name)" << endl;
	cin.getline(current, SIZE_OF_NAMES - 1);
	this->setThirdName(current);
}

void FullName::insertFullNameFromFile(istream &in)
{
	char current[SIZE_OF_NAMES];

	in.getline(current, SIZE_OF_NAMES - 1, ' ');
	this->setFirstName(current);

	in.getline(current, SIZE_OF_NAMES - 1, ' ' );
	this->setSecondName(current);

	in.getline(current, SIZE_OF_NAMES - 1);
	this->setThirdName(current);
}

void FullName::printFullName() const
{
	cout << this->getFirstName() << " " << this->getSecondName() << " " << this->getThirdName() << endl;
}

void FullName::printFullNameOnFile(ostream &out) const
{
	out << this->getFirstName() << " " << this->getSecondName() << " " << this->getThirdName() << endl;
}
