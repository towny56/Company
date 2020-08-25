#pragma once

#ifndef __ALLTEAMS_H__

#include "Team.h"
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

#define __ALLTEAMS_H__

class AllTeams: public Business
{
private:

	Team **teams;
	size_t numberOfTeams;

public:

	AllTeams();
	AllTeams(size_t newNumberOfTeams);
	AllTeams(const AllTeams& other);
	~AllTeams();

	Team** getTeams();
	Team* getTeams(size_t position) const;
	size_t getNumberOfTeams() const;

	void setTeams(Team** other);
	void setNumberOfTeams(size_t newNumberOfTeams);

	void insertInformationAboutTheBusiness();
	void insertInformationAboutTheBusinessFromFile(istream &in);
	void printInfromationAboutTheBusiness() const;
	void printInfromationAboutTheBusinessOnFile(ostream &out) const;

	void insertEmployers(size_t number);
	void insertEmployersFromFile(istream &in);
	void printEmployers() const;
	void printEmployersOnFile(ostream &out) const;
	void addEmpoyer();
	void searchEmployer();
	void fireEmployer();
	void serchPosition();
	void changeEmployer();
	void searchInTeam(Employee* employerToAdd);
	void addTeam();
	void addTeam(Employee* employerToAdd);
	void insertTeamsFromFile(istream &in);
	void printTeams();
	void printTeamsOnFile(ostream &out) const;
	void deleteTeam();
	void transferEmployer();

};

#endif 
