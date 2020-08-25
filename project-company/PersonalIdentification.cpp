#include "stdafx.h"
#include "PersonalIdentification.h"
#include "FullName.h"

#include<string.h>
#include<assert.h>
#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

PersonalIdentification::PersonalIdentification()
{
	this->name.setFirstName();
	this->name.setSecondName();
	this->name.setThirdName();
	this->adress[0] = '\0';

	for (int counter = 0; counter < 10; counter++)
	{
		this->egn[counter] = 0;
	}
}

PersonalIdentification::PersonalIdentification(const FullName newName, const char* newAdress, const unsigned int *newEgn)
{
	this->name = newName;

	strcpy_s(this->adress, newAdress);

	for (int counter = 0; counter < 10; counter++)
	{
		assert(newEgn[counter] >= 0 && newEgn[counter] <= 9);
		this->egn[counter] = newEgn[counter];
	}
}

PersonalIdentification::PersonalIdentification(const PersonalIdentification& other)
{
	this->name = other.name;

	strcpy_s(this->adress, other.adress);

	for (int counter = 0; counter < 10; counter++)
	{
		assert(other.egn[counter] >= 0 && other.egn[counter] <= 9);
		this->egn[counter] = other.egn[counter];
	}
	
}

FullName PersonalIdentification::getFullName() const
{
	return this->name;
}

const char* PersonalIdentification::getAdress() const
{
	return this->adress;
}

const unsigned int* PersonalIdentification::getEgn() const
{
	return this->egn;
}

void PersonalIdentification::setFullName(const FullName newName)
{
	this->name = newName;
}

void PersonalIdentification::setAdress(char* newAdress)
{
	strcpy_s(this->adress, newAdress);
}

void PersonalIdentification::setEgn(unsigned int* newEgn)
{
	for (int counter = 0; counter < 10; counter++)
	{
		assert(newEgn[counter] >= 0 && newEgn[counter] <= 9);
		egn[counter] = newEgn[counter];
	}
}

bool PersonalIdentification::operator == (const PersonalIdentification& other)
{
	for (int counter = 0; counter < 10; counter++)
	{
		assert(other.egn[counter] >= 0 && other.egn[counter] <= 9);
		if (this->egn[counter] != other.egn[counter])
		{
			return false;
		}
	}

	return(this->name == other.name && strcmp(this->adress, other.adress));
}

PersonalIdentification& PersonalIdentification::operator = (const PersonalIdentification& other)
{
	this->name = other.name;

	strcpy_s(this->adress, other.adress);

	for (int counter = 0; counter < 10; counter++)
	{
		assert(other.egn[counter] >= 0 && other.egn[counter] <= 9);
		this->egn[counter] = other.egn[counter];
	}

	return *this;
}

void PersonalIdentification::insertPersonalIdentification()
{
	this->name.insertFullName();
	
	char current[SIZE_OF_ADRESS];

	cout << "(adress)" << endl;
	cin.getline(current, SIZE_OF_ADRESS - 1);
	this->setAdress(current);

	cout << "(egn)" << endl;
	unsigned int arr[10];

	for (int counter = 0; counter < 10; counter++)
	{
		cin >> arr[counter];
		assert(arr[counter] >= 0 && arr[counter] <= 9);
	}

	this->setEgn(arr);
}

void PersonalIdentification::insertPersonalIdentificationFromFile(istream &in)
{
	this->name.insertFullNameFromFile(in);

	char current[SIZE_OF_ADRESS];

	in.getline(current, SIZE_OF_ADRESS - 1);
	this->setAdress(current);

	unsigned int arr[10];

	for (int counter = 0; counter < 10; counter++)
	{
		in >> arr[counter];
		assert(arr[counter] >= 0 && arr[counter] <= 9);
	}

	this->setEgn(arr);
}

void PersonalIdentification::printPersonalIdentification() const
{
	this->name.printFullName();

	cout << this->getAdress() << endl;

	const unsigned int *pointer = this->getEgn();

	for (int counter = 0; counter < 10; counter++)
	{
		cout << pointer[counter];
	}

	cout << endl;
}

void PersonalIdentification::printPersonalIdentificationOnFile(ostream &out) const
{
	this->name.printFullNameOnFile(out);

	out << this->getAdress() << endl;

	const unsigned int *pointer = this->getEgn();

	for (int counter = 0; counter < 9; counter++)
	{
		out << pointer[counter] << " ";
	}

	out << pointer[9] << endl;
}
