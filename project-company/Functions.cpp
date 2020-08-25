#include "stdafx.h"
#include "PersonalIdentification.h"
#include "FullName.h"
#include "EntryIntoEmployment.h"
#include "Employee.h"
#include "Business.h"
#include "Functions.h"
#include "Position.h"
#include "Team.h"
#include "AllTeams.h"

#include<iostream>
#include<fstream>
#include<assert.h>

using std::cin;
using std::cout;
using std::endl;

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

void outputMenuOnGonzole()
{
	cout << "1. Insert information about the business." << endl;
	cout << "2. See information about the business." << endl;
	cout << "3. See employers who work in the business." << endl;
	cout << "4. Add employer." << endl;
	cout << "5. Search employer." << endl;
	cout << "6. Fire employer." << endl;
	cout << "7. See all employers on current position." << endl;
	cout << "8. Change parametars of employer." << endl;
	cout << "9. Add team." << endl;
	cout << "10. See all teams." << endl;
	cout << "11. Delete team." << endl;
	cout << "12. Transfer employer from one team to another." << endl;
	cout << "13. Exit." << endl;
}

void projectOptions(AllTeams &allTeams)
{
	int option=0;
	size_t number = 0;

	ifstream inEmployers("myFileEmployersWhoWorkInTheBusiness.txt");
	allTeams.insertEmployersFromFile(inEmployers);
	inEmployers.close();

	ifstream inBusiness("myFileInformationAboutTheBusiness.txt");
	allTeams.insertInformationAboutTheBusinessFromFile(inBusiness);
	inBusiness.close();

	ifstream inTeams("myFileTeamsInTheBusiness.txt");
	allTeams.insertTeamsFromFile(inTeams);
	inTeams.close();

	do
	{
		cout << endl;
		outputMenuOnGonzole();
		cout << endl;
		cout << "CHOOSE OPTION" << endl;
		cin >> option;
		cout << endl;
		
		assert(option >= 1 && option <= 13);

		switch (option)
		{

		case 1:
		{
			cin.ignore();
			allTeams.insertInformationAboutTheBusiness();
			break;
		}

		case 2:
		{
			allTeams.printInfromationAboutTheBusiness();
			break;
		}

		case 3:
		{
			allTeams.printEmployers();
			break;
		}

		case 4:
		{
			cin.ignore();
			allTeams.addEmpoyer();
			break;
		}

		case 5:
		{
			cin.ignore();
			allTeams.searchEmployer();
			break;
		}


		case 6:
		{
			cin.ignore();
			allTeams.fireEmployer();
			break;
		}

		case 7:
		{
			allTeams.serchPosition();
			break;
		}

		case 8:
		{
			cin.ignore();
			allTeams.changeEmployer();
			break;
		}

		case 9:
		{
			cin.ignore();
			allTeams.addTeam();
			break;
		}

		case 10:
		{
			allTeams.printTeams();
			break;
		}

		case 11:
		{
			cin.ignore();
			allTeams.deleteTeam();
			break;
		}

		case 12:
		{
			cin.ignore();
			allTeams.transferEmployer();
			break;
		}

		/*
		case 13:
		{
		cout << "insert number of employers: ";
		cin >> number;
		cout << endl;
		cin.ignore();
		allTeams.insertEmployers(number);
		break;
		}*/

		}
	}while (option >= 1 && option <= 12);

	ofstream outEmployers("myFileEmployersWhoWorkInTheBusiness.txt" /*, std::ios::app */);
	allTeams.printEmployersOnFile(outEmployers);
	outEmployers.close();

	ofstream outBusiness("myFileInformationAboutTheBusiness.txt");
	allTeams.printInfromationAboutTheBusinessOnFile(outBusiness);
	outBusiness.close();

	ofstream outTeams("myFileTeamsInTheBusiness.txt");
	allTeams.printTeamsOnFile(outTeams);
	outTeams.close();

}