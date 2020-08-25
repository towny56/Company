#pragma once

#ifndef __TEAM_H__

#include "FullName.h"
#include "Employee.h"

#include<fstream>

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

#define __TEAM_H__

#define SIZE_OF_PROJECT 31

class Team
{
private:

	FullName leader;
	char nameProject[SIZE_OF_PROJECT];

	Employee **participants;
	size_t workers;

public:

	Team();
	Team(const FullName newLeader, char* newNameProject);
	Team(const Team& other);
	//~Team();

	void setLeader(const FullName newLeader);
	void setNameProject(const char* newNameProject);
	void setParticipants(Employee** other);
	void setWorkers(size_t newWorkers);

	FullName getLeader() const;
	const char* getNameProject() const;
	Employee** getParticipants();
	Employee* getParticipants(size_t position) const;
	size_t getWorkers() const; 

	bool operator == (const Team& other);
	Team& operator = (const Team& other);
	Employee*& operator [] (size_t position);

	void insertTeam();
	void printTeam() const;
	void printTeamOnFile(ostream &out) const;
	void addParticipants(Employee* participantToAdd);
	void deleteParticipants(Employee* participantToDelete);
};

#endif

