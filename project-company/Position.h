#pragma once

#ifndef __POSITION_H__

#include<fstream>

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

#define __POSITION_H__

#define SIZE_OF_POSITION 21
#define SIZE_OF_PROJECTS 51
#define SIZE_OF_OPERATION_SYSTEM 51

class Position
{
private:

	char namePosition[SIZE_OF_POSITION];
	char nameProjectWork[SIZE_OF_PROJECTS];
	char nameProjectTest[SIZE_OF_PROJECTS];
	char operationSystem[SIZE_OF_OPERATION_SYSTEM];

public:

	Position();
	Position(const char* newNamePosition);
	Position(const Position& other);
	//~Position();

	const char* getNamePosition() const;
	const char* getNameProjectWork() const;
	const char* getNameProjectTest() const;
	const char* getOperationSystem() const;

	void setNamePosition(const char* newNamePosition = "\0");
	void setNameProjectWork(const char* newNameProjectWork = "\0");
	void setNameProjectTest(const char* newNameProjectTest = "\0");
	void setOperationSystem(const char* newOperationSystem = "\0");

	bool operator == (const Position& other);
	Position& operator = (const Position& other);

	void insertPosition();
	void insertPositionFromFile(istream &in);
	void printPosition() const;
	void printPositionOnFile(ostream &out) const;
};

#endif
