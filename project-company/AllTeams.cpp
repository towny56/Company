#include "stdafx.h"
#include "AllTeams.h"
#include "FullName.h"
#include "Team.h"

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

AllTeams::AllTeams(): Business()
{
	this->teams = nullptr;
	this->numberOfTeams = 0;
}

AllTeams::AllTeams(size_t newNumberOfTeams)
{
	assert(newNumberOfTeams > 0);

	this->teams = new Team* [newNumberOfTeams];
	this->numberOfTeams = newNumberOfTeams;
}

AllTeams::AllTeams(const AllTeams& other)
{
	this->teams = new Team* [other.numberOfTeams];
	
	for (int counter = 0; counter < other.numberOfTeams; counter++)
	{
		this->teams[counter] = other.teams[counter];
	}

	this->numberOfTeams = other.numberOfTeams;
}

AllTeams::~AllTeams()
{
	for (int counter = 0; counter < this->numberOfTeams; counter++)
	{
		delete[] teams[counter];
	}

	delete[] teams;

}

Team** AllTeams::getTeams()
{
	return this->teams;
}

Team* AllTeams::getTeams(size_t position) const
{
	return this->teams[position];
}

size_t AllTeams::getNumberOfTeams() const
{
	return this->numberOfTeams;
}

void AllTeams::setTeams(Team** other)
{
	this->teams = other;
}

void AllTeams::setNumberOfTeams(size_t newNumberOfTeams)
{
	this->numberOfTeams = newNumberOfTeams;
}

void AllTeams::insertInformationAboutTheBusiness()
{
	Business::boss.insertFullName();

	char currentOther[SIZE_NAME_OF_BUSINESS];

	cout << "(name of the business)" << endl;
	cin.getline(currentOther, SIZE_NAME_OF_BUSINESS - 1);
	this->setNameBusiness(currentOther);

	cout << "(location of the business)" << endl;
	cin.getline(currentOther, SIZE_LOCATION - 1);
	this->setLocation(currentOther);
}

void AllTeams::insertInformationAboutTheBusinessFromFile(istream &in)
{
	Business::boss.insertFullNameFromFile(in);

	char currentOther[SIZE_NAME_OF_BUSINESS];

	in.getline(currentOther, SIZE_NAME_OF_BUSINESS - 1);

	this->setNameBusiness(currentOther);

	in.getline(currentOther, SIZE_LOCATION - 1);

	this->setLocation(currentOther);
}

void AllTeams::printInfromationAboutTheBusiness() const
{
	Business::boss.printFullName();

	cout << this->getNameBusiness() << endl;
	cout << this->getLocation() << endl;
	cout << this->getNumber() << endl;
	cout << this->getNumberOfTeams() << endl;
}

void AllTeams::printInfromationAboutTheBusinessOnFile(ostream &out) const
{
	Business::boss.printFullNameOnFile(out);

	out << this->getNameBusiness() << endl;
	out << this->getLocation() << endl;
	out << this->getNumber() << endl;
	out << this->getNumberOfTeams() << endl;
}

void AllTeams::insertEmployers(size_t number)
{
	this->setNumber(number);

	delete Business::employers;

	this->Business::employers = new Employee* [number];

	for (size_t counter = 0; counter < number; counter++)
	{
		this->Business::employers[counter] = new Employee;
	    this->Business::employers[counter]->insertEmployee();
		this->searchInTeam(employers[counter]);
	}

}

void AllTeams::insertEmployersFromFile(istream &in)
{
	size_t numberOfEmployers;

	in >> numberOfEmployers;

	this->setNumber(numberOfEmployers);

	this->Business::employers = new Employee* [numberOfEmployers];

	for (size_t counter = 0; counter < numberOfEmployers; counter++)
	{
		this->Business::employers[counter] = new Employee;
		in.ignore();
		this->Business::employers[counter]->insertEmployeeFromFile(in);
		this->searchInTeam(employers[counter]);
	}
}


void AllTeams::printEmployers() const
{
	size_t number;

	number = this->getNumber();

	for (size_t counter = 0; counter < number; counter++)
	{
		this->Business::employers[counter]->printEmployee();
		cout << endl;
	}
}

void AllTeams::printEmployersOnFile(ostream &out) const
{
	size_t number;

	number = this->getNumber();

	out << number << endl;

	for (size_t counter = 0; counter < number; counter++)
	{
		this->Business::employers[counter]->printEmployeeOnFile(out);
		out << endl;
	}
}

void AllTeams::addEmpoyer()
{
		Employee* employeeToAdd = new Employee;
	
		employeeToAdd->insertEmployee();
	
		this->setNumber(this->getNumber() + 1);
	
		Employee** newEmployeers = new Employee* [this->number];
	
		for (int counter = 0; counter < this->number - 1; counter++)
		{
			newEmployeers[counter] = this->employers[counter];
		}
	
		newEmployeers[this->number - 1] = employeeToAdd;
	
		delete[] this->employers;
	
		this->employers = newEmployeers;

		this->searchInTeam(employers[this->number - 1]);
}

void AllTeams::searchEmployer()
{
	FullName employeeToPrint;

	employeeToPrint.insertFullName();

	cout << endl;

	for (int counter = 0; counter < this->number; counter++)
	{
		if (employeeToPrint == employers[counter]->getPersonalIdentification().getFullName())
		{
			employers[counter]->printEmployee();
			return;
		}
	}

	cout << "there is no found employer with these parametars ... " << endl;
}

void AllTeams::fireEmployer()
{
	FullName employeeToFire;

	Employee *changeInTeam = new Employee;

	employeeToFire.insertFullName();

	bool exist = true;

	for (int counter = 0; counter < this->number; counter++)
	{
		if (employeeToFire == employers[counter]->getPersonalIdentification().getFullName())
		{
			exist = false;
		}
	}

	if (exist)
	{
		cout << "there is no found employer with these parametars ... " << endl;
		return;
	}

	if (this->getNumber() > 0)
	{
		this->Business::setNumber(this->getNumber() - 1);
	}

	Employee** newEmployeers = new Employee* [this->number];

	int index = 0;
	int counter = 0;

	while (counter < this->number + 1)
	{
		if (!(employeeToFire == employers[counter]->getPersonalIdentification().getFullName()))
		{
			newEmployeers[index] = this->employers[counter];
			index++;
		}
		else
		{
			changeInTeam = employers[counter];
		}

		counter++;
	}
	
	int indexToChange = 0;

	for (int counterTeams = 0; counterTeams < this->numberOfTeams; counterTeams++)
	{
		for (int counterWorkers = 0; counterWorkers < this->teams[counterTeams]->getWorkers(); counterWorkers++)
		{
			if (employeeToFire == this->teams[counterTeams]->getParticipants(counterWorkers)->getPersonalIdentification().getFullName())
			{
				indexToChange = counterTeams;
			}

		}
	}

	this->teams[indexToChange]->deleteParticipants(changeInTeam);

	delete[] this->employers;

	this->employers = newEmployeers;
}

void AllTeams::serchPosition()
{
	char positionToSerch[SIZE_OF_POSITION];

	int flag = 0;

	cout << "insert position of employers: ";
	cin.ignore();
	cin.getline(positionToSerch, SIZE_OF_POSITION - 1);

	for (int counter = 0; counter < this->number; counter++)
	{
		if (strcmp(positionToSerch, employers[counter]->getPosition().getNamePosition()) == 0)
		{
			flag++;
			employers[counter]->printEmployee();
			cout << endl;
		}
	}

	if (flag == 0)
	{
		cout << "there is no found employer on these position ... " << endl;
	}
}

void AllTeams::changeEmployer()
{
	FullName employeeToChange;

	employeeToChange.insertFullName();
	cout << endl;

	for (int counter = 0; counter < this->number; counter++)
	{
		if (employeeToChange == employers[counter]->getPersonalIdentification().getFullName())
		{
			char currentNameTeam[SIZE_NAME_OF_TEAM];
			char currentPositionTeam[SIZE_POSITION_OF_TEAM];

			strcpy_s(currentNameTeam, employers[counter]->getNameTeam());
			strcpy_s(currentPositionTeam, employers[counter]->getPositionTeam());

			employers[counter]->insertEmployee();

			employers[counter]->setNameTeam(currentNameTeam);
			employers[counter]->setPositionTeam(currentPositionTeam);
		}
	}

	cout << "there is no found employer with these parametars ... " << endl;
}

void AllTeams::addTeam()
{
	Team *teamToAdd = new Team;

	char nameProjectToAdd[SIZE_OF_PROJECT];

	cout << "(project)" << endl;
	cin.getline(nameProjectToAdd, SIZE_OF_PROJECT - 1);

	teamToAdd->setNameProject(nameProjectToAdd);

	this->setNumberOfTeams(this->getNumberOfTeams() + 1);

	Team** newTeams = new Team* [this->numberOfTeams];

	for (int counter = 0; counter < this->numberOfTeams - 1; counter++)
	{
		newTeams[counter] = this->teams[counter];
	}

	newTeams[this->numberOfTeams - 1] = teamToAdd;

	delete[] this->teams;

	this->teams = newTeams;
}

void AllTeams::addTeam(Employee* employerToAdd)
{
	this->setNumberOfTeams(this->getNumberOfTeams() + 1);

	Team** newTeams = new Team* [this->numberOfTeams];

	for (int counter = 0; counter < this->numberOfTeams - 1; counter++)
	{
		newTeams[counter] = this->teams[counter];
	}

	delete this->teams;

	this->teams = newTeams;

	teams[this->numberOfTeams - 1] = new Team;

	this->teams[this->numberOfTeams - 1]->setNameProject(employerToAdd->getNameTeam());

	this->teams[this->numberOfTeams - 1]->addParticipants(employerToAdd);

	if (strcmp(employerToAdd->getPositionTeam(), "leader") == 0)
	{
		this->teams[this->numberOfTeams - 1]->setLeader(employerToAdd->getPersonalIdentification().getFullName());
	}
}

void AllTeams::insertTeamsFromFile(istream &in)
{
	int counterTeams;

	in >> counterTeams;

	if (counterTeams == 0)
	{
		return;
	}

	in.ignore();

	Team** newTeams = new Team*[this->numberOfTeams + counterTeams];

	for (int counter = 0; counter < this->numberOfTeams; counter++)
	{
		newTeams[counter] = this->teams[counter];
	}

	delete[] this->teams;

	this->teams = newTeams;

	for (int counter = this->numberOfTeams; counter < this->numberOfTeams + counterTeams; counter++)
	{
		this->teams[counter] = new Team;

		char nameProjectToAdd[SIZE_OF_PROJECT];

		in.getline(nameProjectToAdd, SIZE_OF_PROJECT - 1);

		this->teams[counter]->setNameProject(nameProjectToAdd);
	}

	this->setNumberOfTeams(this->getNumberOfTeams() + counterTeams);
}

void AllTeams::printTeams()
{
	for (int counter = 0; counter < this->numberOfTeams; counter++)
	{
		this->teams[counter]->printTeam();
		cout << endl;
	}
}

void AllTeams::printTeamsOnFile(ostream &out) const
{
	int counterTeams = 0;

	for (int counter = 0; counter < this->numberOfTeams; counter++)
	{
		if (teams[counter]->getWorkers() == 0)
		{
			counterTeams++;
		}
	}

	out << counterTeams << endl;

	for (int counter = 0; counter < this->numberOfTeams; counter++)
	{
		if (teams[counter]->getWorkers() == 0)
		{
			this->teams[counter]->printTeamOnFile(out);
		}
	}

}

void AllTeams::searchInTeam(Employee* employerToAdd)
{
	bool exist = true;

	for (int counter = 0; counter < this->numberOfTeams; counter++)
	{
		if (strcmp(employerToAdd->getNameTeam(), this->teams[counter]->getNameProject()) == 0)
		{
			this->teams[counter]->addParticipants(employerToAdd);

			if (strcmp(employerToAdd->getPositionTeam(), "leader") == 0)
			{
				this->teams[counter]->setLeader(employerToAdd->getPersonalIdentification().getFullName());
			}

			exist = false;
		}
	}

	if (exist)
	{
		this->addTeam(employerToAdd);
	}
}

void AllTeams::deleteTeam()
{
	char teamToDelete[SIZE_OF_PROJECT];

	cout << "(project to delete)" << endl;
	cin.getline(teamToDelete, SIZE_OF_PROJECT - 1);

	int flag = 0;

	for (int counter = 0; counter < this->numberOfTeams; counter++)
	{
		if (strcmp(teamToDelete, teams[counter]->getNameProject()) == 0)
		{
			flag++;

			if (teams[counter]->getWorkers() != 0)
			{
				cout << "there are workers in the project ... " << endl;
				return;
			}
		}
	}

	if (flag == 0)
	{
		cout << "there is no found team with these parametars ... " << endl;
		return;
	}

	assert(flag > 0);

	if (this->numberOfTeams > 0)
	{
		this->setNumberOfTeams(this->getNumberOfTeams() - 1);
	}

	Team** newTeams = new Team* [this->numberOfTeams];

	int index = 0;
	int counter = 0;

	while (counter < this->numberOfTeams + 1)
	{
		if (!(strcmp(teamToDelete, teams[counter]->getNameProject()) == 0))
		{
			newTeams[index] = this->teams[counter];
			index++;
		}

		counter++;
	}

	delete[] this->teams;

	this->teams = newTeams;
}

void AllTeams::transferEmployer()
{
	FullName employerToTransfer;

	employerToTransfer.insertFullName();

	char teamToTransfer[SIZE_OF_PROJECT];

	cout << "(team to transfer)" << endl;
	cin.getline(teamToTransfer, SIZE_OF_PROJECT - 1);

	int flagEmployer = 0;
	int flagTeam = 0;
	int indexToTransfer = 0;
	int indexToDelete = 0;

	Employee *employerToTransferPointer = new Employee;

	for (int counterTeams = 0; counterTeams < this->numberOfTeams; counterTeams++)
	{
		for (int counterWorkers = 0; counterWorkers < this->teams[counterTeams]->getWorkers(); counterWorkers++)
		{
			if (employerToTransfer == this->teams[counterTeams]->getParticipants(counterWorkers)->getPersonalIdentification().getFullName())
			{
				employerToTransferPointer = teams[counterTeams]->getParticipants(counterWorkers);
				indexToDelete = counterTeams;
				flagEmployer++;
			}
		}
	}

	for (int counter = 0; counter < this->numberOfTeams; counter++)
	{
		if (strcmp(this->teams[counter]->getNameProject(), teamToTransfer) == 0)
		{
			indexToTransfer = counter;
			flagTeam++;
		}
	}

	if (flagEmployer == 0)
	{
		cout << endl << "there is no found employer with these parametars ... " << endl;
		return;
	}

	if (flagTeam == 0)
	{
		cout << endl << "there is no found team with these parametars ... " << endl;
		return;
	}

	this->teams[indexToDelete]->deleteParticipants(employerToTransferPointer);

	this->teams[indexToTransfer]->addParticipants(employerToTransferPointer);

	employerToTransferPointer->setNameTeam(teamToTransfer);
}
