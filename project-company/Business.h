#pragma once

#ifndef __BUSINESS_H__

#include "Business.h"
#include "Employee.h"
#include "FullName.h"
#include "Position.h"
#include "PersonalIdentification.h"
#include "EntryIntoEmployment.h"

#include<fstream>

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

#define __BUSINESS_H__

#define SIZE_NAME_OF_BUSINESS 101
#define SIZE_LOCATION 101

class Business
{
protected:

	FullName boss;

	char nameBusiness[SIZE_NAME_OF_BUSINESS];
	char location[SIZE_LOCATION];

	Employee **employers;
	size_t number;

public:

	Business();
	Business(size_t newNumber);
	Business(const FullName newBoss, const char* newNameBusiness, const char* newLocation, const size_t number);
	Business(const Business& other);
	~Business();

	void setBoss(const FullName newBoss);
	void setNameBusiness(const char* newNameBusiness);
	void setLocation(const char* newLocation);
	void setEmployee(Employee** other);
	void setNumber(const size_t newNumber);

	FullName getBoss() const;
	const char* getNameBusiness() const;
	const char* getLocation() const;
	Employee** getEmployers();
	Employee* getEmployers(size_t position) const;
	size_t getNumber() const;

	bool operator == (const Business& other);
	Business& operator = (const Business& other);
	Employee*& operator [] (size_t position);

	virtual void insertInformationAboutTheBusiness();
	virtual void printInfromationAboutTheBusiness() const;
	virtual void insertEmployers(size_t number);
	virtual void printEmployers() const;
	virtual void addEmpoyer();
	virtual void searchEmployer();
	virtual void fireEmployer();
	virtual void serchPosition();
	virtual void changeEmployer();
};

#endif 
