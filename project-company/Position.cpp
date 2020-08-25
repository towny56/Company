#include "stdafx.h"
#include "Position.h"

#include<string.h>
#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

Position::Position()
{
	this->namePosition[0] = '\0';
	this->nameProjectWork[0] = '\0';
	this->nameProjectTest[0] = '\0';
	this->operationSystem[0] = '\0';
}

Position::Position(const char* newNamePosition):Position()
{
	strcpy_s(this->namePosition, newNamePosition);
}

Position::Position(const Position& other)
{
	strcpy_s(this->namePosition, other.namePosition);
	strcpy_s(this->nameProjectWork, other.nameProjectWork);
	strcpy_s(this->nameProjectTest, other.nameProjectTest);
	strcpy_s(this->operationSystem, other.operationSystem);
}

const char* Position::getNamePosition() const
{
	return this->namePosition;
}

const char* Position::getNameProjectWork() const
{
	return this->nameProjectWork;
}

const char* Position::getNameProjectTest() const
{
	return this->nameProjectTest;
}

const char* Position::getOperationSystem() const
{
	return this->operationSystem;
}

void Position::setNamePosition(const char* newNamePosition)
{
	strcpy_s(this->namePosition, newNamePosition);
}

void Position::setNameProjectWork(const char* newNameProjectWork)
{
	strcpy_s(this->nameProjectWork, newNameProjectWork);
}

void Position::setNameProjectTest(const char* newNameProjectTest)
{
	strcpy_s(this->nameProjectTest, newNameProjectTest);
}

void Position::setOperationSystem(const char* newOperationSystem)
{
	strcpy_s(this->operationSystem, newOperationSystem);
}

bool Position::operator == (const Position& other)
{
	return(strcmp(this->namePosition, other.namePosition) == 0 &&
		   strcmp(this->nameProjectWork, other.nameProjectWork) == 0 &&
		   strcmp(this->nameProjectTest, other.nameProjectTest) == 0 &&
		   strcmp(this->operationSystem, other.operationSystem) == 0);
}

Position& Position::operator = (const Position& other)
{
	strcpy_s(this->namePosition, other.namePosition);
	strcpy_s(this->nameProjectWork, other.nameProjectWork);
	strcpy_s(this->nameProjectTest, other.nameProjectTest);
	strcpy_s(this->operationSystem, other.operationSystem);

	return *this;
}

void Position::insertPosition()
{
	char currentPosition[SIZE_OF_POSITION];
	char currentProject[SIZE_OF_PROJECTS];

	cout << "(position)" << endl;
	cin.getline(currentPosition, SIZE_OF_POSITION - 1);
	this->setNamePosition(currentPosition);

	if (strcmp(currentPosition, "mladshi programer") == 0)
	{
		cout << "(name of project - work)" << endl;
		cin.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setNameProjectWork(currentProject);
	}

	if (strcmp(currentPosition, "mladshi tester") == 0)
	{
		cout << "(name of project - test)" << endl;
		cin.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setNameProjectTest(currentProject);
		cout << "(operation system)" << endl;
		cin.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setOperationSystem(currentProject);
	}

	if (strcmp(currentPosition, "starshi programer") == 0)
	{
		cout << "(name of project - work)" << endl;
		cin.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setNameProjectWork(currentProject);
		cout << "(name of project - test)" << endl;
		cin.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setNameProjectTest(currentProject);
		cout << "(operation system)" << endl;
		cin.getline(currentProject, SIZE_OF_OPERATION_SYSTEM - 1);
		this->setOperationSystem(currentProject);
	}

}

void Position::insertPositionFromFile(istream &in)
{
	char currentPosition[SIZE_OF_POSITION];
	char currentProject[SIZE_OF_PROJECTS];

	in.getline(currentPosition, SIZE_OF_POSITION - 1);
	this->setNamePosition(currentPosition);

	if (strcmp(currentPosition, "mladshi programer") == 0)
	{
		in.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setNameProjectWork(currentProject);
	}

	if (strcmp(currentPosition, "mladshi tester") == 0)
	{
		in.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setNameProjectTest(currentProject);
		in.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setOperationSystem(currentProject);
	}

	if (strcmp(currentPosition, "starshi programer") == 0)
	{
		in.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setNameProjectWork(currentProject);
		in.getline(currentProject, SIZE_OF_PROJECTS - 1);
		this->setNameProjectTest(currentProject);
		in.getline(currentProject, SIZE_OF_OPERATION_SYSTEM - 1);
		this->setOperationSystem(currentProject);
	}

}

void Position::printPosition() const
{
	cout << this->getNamePosition() << " - ";

	if (strcmp(this->getNamePosition(), "mladshi programer") == 0)
	{
		cout << this->getNameProjectWork() << endl;
	}

	if (strcmp(this->getNamePosition(), "mladshi tester") == 0)
	{
		cout << this->getNameProjectTest() << " , " << this->getOperationSystem() << endl;
	}

	if (strcmp(this->getNamePosition(), "starshi programer") == 0)
	{
		cout<< this->getNameProjectWork() << " , " << this->getNameProjectTest() << " , " << this->getOperationSystem() << endl;
	}
}

void Position::printPositionOnFile(ostream &out) const
{
	out << this->getNamePosition() << endl;

	if (strcmp(this->getNamePosition(), "mladshi programer") == 0)
	{
		out << this->getNameProjectWork() << endl;
	}

	if (strcmp(this->getNamePosition(), "mladshi tester") == 0)
	{
		out << this->getNameProjectTest() << endl;
		out << this->getOperationSystem() << endl;
	}

	if (strcmp(this->getNamePosition(), "starshi programer") == 0)
	{
		out << this->getNameProjectWork() << endl;
		out << this->getNameProjectTest() << endl;
		out << this->getOperationSystem() << endl;
	}
}