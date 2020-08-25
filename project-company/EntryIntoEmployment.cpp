#include "stdafx.h"
#include"EntryIntoEmployment.h"

#include<iostream>
#include<assert.h>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

EntryIntoEmployment::EntryIntoEmployment()
{
	day = DAY;
	month = MONTH;
	year = YEAR;
}

EntryIntoEmployment::EntryIntoEmployment(unsigned int newDay, unsigned int newMonth, unsigned int newYear)
{
	assert(newDay >= 1 && newDay <= 31);
	this->day = newDay;
	assert(newMonth >= 1 && newMonth <= 12);
	this->month = newMonth;
	assert(newYear >= 1900);
	this->year = newYear;
}

EntryIntoEmployment::EntryIntoEmployment(const EntryIntoEmployment& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

unsigned int EntryIntoEmployment::getDay() const
{
	return this->day;
}

unsigned int EntryIntoEmployment::getMonth() const
{
	return this->month;
}

unsigned int EntryIntoEmployment::getYear() const
{
	return this->year;
}

void EntryIntoEmployment::setDay(const unsigned int newDay)
{
	assert(newDay >= 1 && newDay <= 31);
	this->day = newDay;
}

void EntryIntoEmployment::setMonth(const unsigned int newMonth)
{
	assert(newMonth >= 1 && newMonth <= 12);
	this->month = newMonth;
}

void EntryIntoEmployment::setYear(const unsigned int newYear)
{
	assert(newYear >= 1900);
	this->year = newYear;
}

bool EntryIntoEmployment::operator == (const EntryIntoEmployment &other)
{
	return (this->day == other.day && 
		    this->month == other.month && 
		    this->year == other.year);
}

EntryIntoEmployment& EntryIntoEmployment::operator = (const EntryIntoEmployment& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;

	return *this;
}

void EntryIntoEmployment::insertEntryIntoEmployment()
{
	unsigned int current;

	cout << "(day)" << endl;
	cin >> current;
	assert(current >= 1 && current <= 31);
	this->setDay(current);

	cout << "(month)" << endl;
	cin >> current;
	assert(current >= 1 && current <= 12);
	this->setMonth(current);

	cout << "(year)" << endl;
	cin >> current;
	assert(current >= 1900);
	this->setYear(current);
}

void EntryIntoEmployment::insertEntryIntoEmploymentFromFile(istream &in)
{
	unsigned int current;

	in >> current;
	assert(current >= 1 && current <= 31);
	this->setDay(current);

	in >> current;
	assert(current >= 1 && current <= 12);
	this->setMonth(current);

	in >> current;
	assert(current >= 1900);
	this->setYear(current);
}

void EntryIntoEmployment::printEntryIntoEmployment() const
{
	cout << this->getDay() << "." << this->getMonth() << "." << this->getYear() << endl;
}

void EntryIntoEmployment::printEntryIntoEmploymentOnFile(ostream &out) const
{
	out << this->getDay() << " " << this->getMonth() << " " << this->getYear() << endl;
}
