#include "stdafx.h"
#include "Team.h"

#include <string.h>
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

Team::Team()
{
	this->leader.setFirstName();
	this->leader.setSecondName();
	this->leader.setThirdName();
	this->nameProject[0] = '\0';
	this->participants = nullptr;
	this->workers = 0;
}

Team::Team(const FullName newLeader, char* newNameProject):Team()
{
	this->leader = newLeader;
	strcpy_s(this->nameProject, newNameProject);
}

Team::Team(const Team& other)
{
	this->leader = other.leader;
	strcpy_s(this->nameProject, other.nameProject);

	this->participants = new Employee* [other.workers];

	for (int counter = 0; counter < other.workers; counter++)
	{
		this->participants[counter] = other.participants[counter];
	}

	this->workers = other.workers;
}

/*
Team::~Team()
{
	for (int counter = 0; counter < this->workers; counter++)
	{
		delete[] participants[counter];
	}

	delete participants;
}
*/

void Team::setLeader(const FullName newLeader)
{
	this->leader = newLeader;
}

void Team::setNameProject(const char* newNameProject)
{
	strcpy_s(this->nameProject, newNameProject);
}

void Team::setParticipants(Employee** other)
{
	this->participants = other;
}

void Team::setWorkers(size_t newWorkers)
{
	this->workers = newWorkers;
}

FullName Team::getLeader() const
{
	return this->leader;
}

const char* Team::getNameProject() const
{
	return this->nameProject;
}

Employee** Team::getParticipants()
{
	return this->participants;
}

Employee* Team::getParticipants(size_t position) const
{
	return this->participants[position];
}

size_t Team::getWorkers() const
{
	return this->workers;
}

bool Team::operator == (const Team& other)
{
	if (this->workers != other.workers)
	{
		return false;
	}

	size_t current = 0;

	for (size_t counter = 0; counter < this->workers; counter++)
	{
		if (this->participants[counter] == other.participants[counter])
		{
			counter++;
		}
	}

	return (current == this->workers &&
		    this->leader == other.leader &&
		    strcmp(this->nameProject, other.nameProject) == 0);
}

Team& Team::operator = (const Team& other)
{
	if (this != &other)
	{
		delete[] participants;

		this->leader = other.leader;
		strcpy_s(this->nameProject, other.nameProject);

		this->participants = new Employee*[other.workers];

		this->workers = other.workers;

		for (size_t counter = 0; counter < this->workers; counter++)
		{
			this->participants[counter] = other.participants[counter];
		}

	}

	return *this;
}

Employee*& Team::operator [] (size_t position)
{
	assert(position >= 0 && position <= this->workers);
	return this->participants[position];
}

void Team::insertTeam()
{
	this->leader.insertFullName();

	char current[SIZE_OF_PROJECT];

	cout << "(project)" << endl;
	cin.getline(current, SIZE_OF_PROJECT - 1);

	this->setNameProject(current);

}

void Team::printTeam() const
{
	this->leader.printFullName();
	cout << this->getNameProject() << endl;

	for (int counter = 0; counter < this->workers; counter++)
	{
		this->participants[counter]->getPersonalIdentification().getFullName().printFullName();
	}

	cout << this->getWorkers() << endl;
}

void Team::printTeamOnFile(ostream &out) const
{
	out << this->getNameProject() << endl;
}

void Team::addParticipants(Employee* participantToAdd)
{
	this->setWorkers(this->getWorkers() + 1);

	Employee** newParticioants = new Employee*[this->workers];

	for (int counter = 0; counter < this->workers - 1; counter++)
	{
		newParticioants[counter] = this->participants[counter];
	}

	newParticioants[this->workers - 1] = participantToAdd;

	if (strcmp(participantToAdd->getPositionTeam(), "leader") == 0)
	{
		this->leader.setFirstName(participantToAdd->getPersonalIdentification().getFullName().getFirstName());
		this->leader.setSecondName(participantToAdd->getPersonalIdentification().getFullName().getSecondName());
		this->leader.setThirdName(participantToAdd->getPersonalIdentification().getFullName().getThirdName());
	}

	delete this->participants;

	this->participants = newParticioants;
}

void Team::deleteParticipants(Employee* participantToDelete)
{
	if (strcmp(participantToDelete->getPositionTeam(), "leader") == 0)
	{
		this->leader.setFirstName();
		this->leader.setSecondName();
		this->leader.setThirdName();
	}

	if (this->getWorkers() > 0)
	{
		this->setWorkers(this->getWorkers() - 1);
	}

	Employee** newParticipants = new Employee*[this->workers];

	int index = 0;
	int counter = 0;

	while (counter < this->workers + 1)
	{
		if (!(participantToDelete == this->participants[counter]))
		{
			newParticipants[index] = this->participants[counter];
			index++;
		}

		counter++;

	}

	delete[] this->participants;

	this->participants = newParticipants;
}