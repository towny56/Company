#pragma once

#ifndef __FULLNAME_H__

#define __FULLNAME_H__

#include<fstream>

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

#define SIZE_OF_NAMES 51

struct FullName
{
private:

	char firstName[SIZE_OF_NAMES];
	char secondName[SIZE_OF_NAMES];
	char thirdName[SIZE_OF_NAMES];

public:

	FullName();
	FullName(const char* newFirstName, const char* newSecondName, const char* newThirdName);
	FullName(const FullName &other);
	//~FullName();

	const char* getFirstName() const;
	const char* getSecondName() const;
	const char* getThirdName() const;

	void setFirstName(const char *newFirstName = "\0");
	void setSecondName(const char *newSecondName = "\0");
	void setThirdName(const char *newThirdName = "\0");

	bool operator == (const FullName &other);
	FullName& operator = (const FullName &other);

	void insertFullName();
	void insertFullNameFromFile(istream &in);
	void printFullName() const;
	void printFullNameOnFile(ostream &out) const;

};

#endif 
