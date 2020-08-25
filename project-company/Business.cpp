#include"stdafx.h"
#include"Business.h"
#include"Employee.h"
#include"FullName.h"
#include"Position.h"
#include"PersonalIdentification.h"
#include"EntryIntoEmployment.h"

#include<iostream>
#include<string.h>
#include<assert.h>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

Business::Business()
{
	this->boss.setFirstName();
	this->boss.setSecondName();
	this->boss.setThirdName();
	this->nameBusiness[0] = '\0';
	this->location[0] = '\0';
	this->employers = nullptr;
	this->number = 0;
}

Business::Business(size_t newNumber) : Business()
{
	assert(newNumber >= 0 && newNumber <= 1000);

	this->employers = new Employee* [newNumber];
	this->number = newNumber;
}

Business::Business(const FullName newBoss, const char* newNameBusiness, const char* newLocation, const size_t newNumber)
{
	this->boss = newBoss;
	strcpy_s(this->nameBusiness, newNameBusiness);
	strcpy_s(this->location, newLocation);
	assert(newNumber >= 0 && newNumber <= 1000);
	this->employers = new Employee* [newNumber];
	this->number = newNumber;
}

Business::Business(const Business& other)
{
	this->boss = other.boss;
	strcpy_s(this->nameBusiness, other.nameBusiness);
	strcpy_s(this->location, other.location);
	assert(other.number >= 0 && other.number <= 1000);
	this->employers = new Employee* [other.number];
	for (int counter = 0; counter < other.number; counter++)
	{
		this->employers[counter] = other.employers[counter];
	}
	this->number = other.number;
}

Business::~Business()
{
	for (int counter = 0; counter < this->number; counter++)
	{
		delete[] employers[counter];
	}

	delete[] employers;
}

void Business::setBoss(const FullName newBoss)
{
	this->boss = newBoss;
}

void Business::setNameBusiness(const char* newNameBusiness)
{
	strcpy_s(this->nameBusiness, newNameBusiness);
}

void Business::setLocation(const char* newLocation)
{
	strcpy_s(this->location, newLocation);
}

void Business::setEmployee(Employee** other)
{
	this->employers = other;
}

void Business::setNumber(const size_t newNumber)
{
	assert(newNumber >= 0 && newNumber <= 1000);
	this->number = newNumber;
}

FullName Business::getBoss() const
{
	return this->boss;
}

const char* Business::getNameBusiness() const
{
	return this->nameBusiness;
}

const char* Business::getLocation() const
{
	return this->location;
}

Employee** Business::getEmployers()
{
	return this->employers;
}

Employee* Business::getEmployers(size_t position) const
{
	return this->employers[position];
}

size_t Business::getNumber() const
{
	return this->number;
}

bool Business::operator == (const Business& other)
{
	if (this->number != other.number)
	{
		return false;
	}

	size_t current = 0;

	for (int counter = 0; counter < this->number; counter++)
	{
		if (this->employers[counter] == other.employers[counter])
		{
			current++;
		}
	}

	return (current == this->number &&
		    this->boss == other.boss &&
		    strcmp(this->nameBusiness, other.nameBusiness) &&
		    strcmp(this->location, other.location));
}

Business& Business::operator = (const Business& other)
{
	if (this != &other)
	{
		delete[] employers;

		this->boss = other.boss;
		strcpy_s(this->nameBusiness, other.nameBusiness);
		strcpy_s(this->location, other.location);
		assert(number >= 0 && number <= 1000);
		this->number = other.number;

		this->employers = new Employee* [number];

		for (size_t counter = 0; counter < this->number; counter++)
		{
			this->employers[counter] = other.employers[counter];
		}
	}

	return *this;
}

Employee*& Business::operator [] (size_t position)
{
	assert(position >= 0 && position <= this->number);
	return this->employers[position];
}

void Business::insertInformationAboutTheBusiness() 
{

}

void Business::printInfromationAboutTheBusiness() const 
{

}

void Business::insertEmployers(size_t number) 
{

}

void Business::printEmployers() const 
{

}

void Business::addEmpoyer() 
{

}

void Business::searchEmployer() 
{

}

void Business::fireEmployer()
{

}

void Business::serchPosition() 
{

}

void Business::changeEmployer() 
{

}