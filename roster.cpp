#include <iostream>;
#include <iomanip>;
#include <string>;
#include "roster.h";
using std::string;
using std::cout;
using std::left;
using std::setw;
using std::cerr;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->students = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->students = new Student * [capacity];
}

void Roster::parseAdd(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		double parray[Student::daysArraySize];


		int rhs = studentData[lastIndex].find(",");

		students[lastIndex]->setID(studentData[lastIndex].substr(0, rhs));


		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);

		students[lastIndex]->setFirst(studentData[lastIndex].substr(lhs, rhs - lhs));


		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);

		students[lastIndex]->setLast(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);

		students[lastIndex]->setEmail(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);

		students[lastIndex]->setAge(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);

		parray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);

		parray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);

		parray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		students[lastIndex]->setDaysLeft(parray);

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);

		if (studentData[lastIndex].substr(lhs, rhs - lhs) == "SOFTWARE") {
			students[lastIndex]->setDegreeProgram(SOFTWARE);
		}
		else if (studentData[lastIndex].substr(lhs, rhs - lhs) == "SECURITY") {
			students[lastIndex]->setDegreeProgram(SECURITY);
		}
		else if (studentData[lastIndex].substr(lhs, rhs - lhs) == "NETWORK") {
			students[lastIndex]->setDegreeProgram(NETWORK);
		}
	}
	else
	{
		cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY!\n EXITING NOW!";
		exit(-1);
	}
}

void Roster::print_All()
{

	for (int i = 0; i <= this->lastIndex; i++) (this->students)[i]->print();
}

bool Roster::remove(string ID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getID() == ID)
		{
			found = true;

			delete this->students[i];


			this->students[i] = this->students[lastIndex];
		}
	}
	return found;
}


void Roster::printAverageDaysLeft(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getID() == studentID)
		{
			found = true;
			int* p = students[i]->getDaysLeft();
			cout << "Average days left for student " << studentID << " is " << (p[0] + p[1] + p[2]) / 3;
		}
	}
	if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmailAddresses()
{
	cout << "Displaying invalid emails:" << '\n';
	cout << endl;
	for (int i = 0; i < 5; i++) {
		bool foundCharAt = false;
		bool foundCharPeriod = false;
		bool foundCharSpace = false;
		string email = "";
		email = (*classRosterArray[i]).getEmailAddress();
		for (char& c : email) {
			if (c == '@') {
				foundCharAt = true;
			}
			if (c == '.') {
				foundCharPeriod = true;
			}
			if (c == ' ') {
				foundCharSpace = true;
			}
		}
		if (foundCharAt == false || foundCharPeriod == false || foundCharSpace == true) {
			cout << (*classRosterArray[i]).getEmailAddress() << '\n';
		}
	}
	cout << '\n';
}

void Roster::printByDegreeProgram(DegreeProgram deg)
{
	cout << "Printing students studying " << DegreeProgramStrings[deg] << "/n";
	for (int i = 0; i < numStudents; i++) {
		if (this->students[i]->getDegreeProgram() == deg) this->students[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete this->students[i];
	}
	delete this;
}
