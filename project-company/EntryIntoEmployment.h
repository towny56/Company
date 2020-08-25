#pragma once

#ifndef __ENTRYINTOEMPLOYMENT_H__

#include<fstream>

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

#define __ENTRYINTOEMPLOYMENT_H__

#define DAY 1
#define MONTH 1
#define YEAR 1900

struct EntryIntoEmployment
{
private:

	unsigned int day;
	unsigned int month;
	unsigned int year;

public:

	EntryIntoEmployment();
	EntryIntoEmployment(unsigned int newDay, unsigned int newMonth, unsigned int newYear);
	EntryIntoEmployment(const EntryIntoEmployment& other);
	//~EntryIntoEmployment();

	void setDay(const unsigned int newDay = DAY);
	void setMonth(const unsigned int newMonth = MONTH);
	void setYear(const unsigned int newYear = YEAR);

	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;

	bool operator == (const EntryIntoEmployment &other);
	EntryIntoEmployment& operator = (const EntryIntoEmployment& other);

	void insertEntryIntoEmployment();
	void insertEntryIntoEmploymentFromFile(istream &in);
	void printEntryIntoEmployment() const;
	void printEntryIntoEmploymentOnFile(ostream &out) const;

};

#endif
