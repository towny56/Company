#pragma once

#ifndef __EMPLOYEE_H__

#include"PersonalIdentification.h"
#include"EntryIntoEmployment.h"
#include"FullName.h"
#include"Position.h"

#include<fstream>

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

#define __EMPLOYEE_H__

#define SIZE_NAME_OF_TEAM 31
#define SIZE_POSITION_OF_TEAM 51

class Employee
{
private:

	PersonalIdentification personalIdentification;
	EntryIntoEmployment entryIntoEmployment;
	FullName supervisor;
	Position position;
	char nameTeam[SIZE_NAME_OF_TEAM];
	char positionTeam[SIZE_POSITION_OF_TEAM];

public:

	Employee();
	Employee(const PersonalIdentification& newPersonalIdentification, const EntryIntoEmployment& newEntryIntoEmployment, const FullName& newSupervisor, const Position& newPosition, const char* newNameTeam, const char* newPositionTeam);
	Employee(const Employee& other);
	//~Employee();

	void setPersonalIdentification(const PersonalIdentification &newPersonalIdentification);
	void setEntryIntoEmployment(const EntryIntoEmployment &newEntryIntoEmployment);
	void setSupervisor(const FullName &newSupervisor);
	void setPosition(const Position &newPosition);
	void setNameTeam(const char* newNameTeam);
	void setPositionTeam(const char* newPositionTeam);

	PersonalIdentification getPersonalIdentification() const;
	EntryIntoEmployment getEntryIntoEmployment() const;
	FullName getSupervisor() const;
	Position getPosition() const;
	const char* getNameTeam() const;
	const char* getPositionTeam() const;

	bool operator == (const Employee& other);
	Employee& operator = (const Employee& other);

	void insertEmployee();
	void insertEmployeeFromFile(istream &in);
	void printEmployee() const;
	void printEmployeeOnFile(ostream &out) const;

};

#endif
