// project-company.cpp : Defines the entry point for the console application.
//

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

int main()
{
	AllTeams allTeams;

	projectOptions(allTeams);

    return 0;
}

