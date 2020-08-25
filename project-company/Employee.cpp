#include"stdafx.h"
#include"Employee.h"
#include"PersonalIdentification.h"
#include"EntryIntoEmployment.h"
#include"FullName.h"
#include"Position.h"

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

Employee::Employee()
{
	
}

Employee::Employee(const PersonalIdentification& newPersonalIdentification, const EntryIntoEmployment& newEntryIntoEmployment, const FullName& newSupervisor, const Position& newPosition, const char* newNameTeam, const char* newPositionTeam)
{
	this->personalIdentification = newPersonalIdentification;
	this->entryIntoEmployment = newEntryIntoEmployment;
	this->supervisor = newSupervisor;
	this->position = newPosition;
	strcpy_s(this->nameTeam, newNameTeam);
	strcpy_s(this->positionTeam, newPositionTeam);
}

Employee::Employee(const Employee& other)
{
	this->personalIdentification = other.personalIdentification;
	this->entryIntoEmployment = other.entryIntoEmployment;
	this->supervisor = other.supervisor;
	this->position = other.position;
	strcpy_s(this->nameTeam, other.nameTeam);
	strcpy_s(this->positionTeam, other.positionTeam);
}

void Employee::setPersonalIdentification(const PersonalIdentification &newPersonalIdentification)
{
	this->personalIdentification = newPersonalIdentification;
}

void Employee::setEntryIntoEmployment(const EntryIntoEmployment &newEntryIntoEmployment)
{
	this->entryIntoEmployment = newEntryIntoEmployment;
}

void Employee::setSupervisor(const FullName &newSupervisor)
{
	this->supervisor = newSupervisor;
}

void Employee::setPosition(const Position &newPosition)
{
	this->position = newPosition;
}

void Employee::setNameTeam(const char* newNameTeam)
{
	strcpy_s(this->nameTeam, newNameTeam);
}

void Employee::setPositionTeam(const char* newPositionTeam)
{
	strcpy_s(this->positionTeam, newPositionTeam);
}

PersonalIdentification Employee::getPersonalIdentification() const
{
	return this->personalIdentification;
}

EntryIntoEmployment Employee::getEntryIntoEmployment() const
{
	return this->entryIntoEmployment;
}

FullName Employee::getSupervisor() const
{
	return this->supervisor;
}

Position Employee::getPosition() const
{
	return this->position;
}

const char* Employee::getNameTeam() const
{
	return this->nameTeam;
}

const char* Employee::getPositionTeam() const
{
	return this->positionTeam;
}

bool Employee::operator == (const Employee& other)
{
	return (this->personalIdentification == other.personalIdentification &&
		    this->entryIntoEmployment == other.entryIntoEmployment &&
		    this->supervisor == other.supervisor &&
		    this->position == other.position && 
		    strcmp(this->nameTeam, other.nameTeam) == 0 &&
		    strcmp(this->positionTeam,other.positionTeam) == 0);
}

Employee& Employee::operator = (const Employee& other)
{
	this->personalIdentification = other.personalIdentification;
	this->entryIntoEmployment = other.entryIntoEmployment;
    this->supervisor = other.supervisor;
	this->position = other.position;
	strcpy_s(this->nameTeam, other.nameTeam);
	strcpy_s(this->positionTeam, other.positionTeam);

	return *this;
}

void Employee::insertEmployee()
{
	this->personalIdentification.insertPersonalIdentification();
	this->entryIntoEmployment.insertEntryIntoEmployment();
	cin.ignore();
	this->supervisor.insertFullName();
	this->position.insertPosition();

	char currentTeam[SIZE_NAME_OF_TEAM];

	cout << "(team)" << endl;
	cin.getline(currentTeam, SIZE_NAME_OF_TEAM - 1);
	this->setNameTeam(currentTeam);

	char currentPosition[SIZE_POSITION_OF_TEAM];

	cout << "(position of team)" << endl;
	cin.getline(currentPosition, SIZE_POSITION_OF_TEAM - 1);
	this->setPositionTeam(currentPosition);

}

void Employee::insertEmployeeFromFile(istream &in)
{
	this->personalIdentification.insertPersonalIdentificationFromFile(in);
	this->entryIntoEmployment.insertEntryIntoEmploymentFromFile(in);
	in.ignore();
	this->supervisor.insertFullNameFromFile(in);
	this->position.insertPositionFromFile(in);

	char currentTeam[SIZE_NAME_OF_TEAM];

	in.getline(currentTeam, SIZE_NAME_OF_TEAM - 1);

	this->setNameTeam(currentTeam);

	char currentPosition[SIZE_POSITION_OF_TEAM];

	in.getline(currentPosition, SIZE_POSITION_OF_TEAM - 1);

	this->setPositionTeam(currentPosition);
}

void Employee::printEmployee() const
{
	this->personalIdentification.printPersonalIdentification();
	this->entryIntoEmployment.printEntryIntoEmployment();
	this->supervisor.printFullName();
	this->position.printPosition();
	cout << this->getNameTeam() << " - " << this->getPositionTeam() << endl;
}

void Employee::printEmployeeOnFile(ostream &out) const
{
	this->personalIdentification.printPersonalIdentificationOnFile(out);
	this->entryIntoEmployment.printEntryIntoEmploymentOnFile(out);
	this->supervisor.printFullNameOnFile(out);
	this->position.printPositionOnFile(out);
	out << this->getNameTeam() << endl;
	out << this->getPositionTeam() << endl;
}
