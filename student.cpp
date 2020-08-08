#include <iostream>;
#include <iomanip>;
#include <string>;
#include "student.h";
using std::string;
using std::cout;
using std::left;
using std::setw;
using std::cerr;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysLeft = new int[daysArraySize];
	for (int i = 0; i < daysArraySize; i++) this->daysLeft[i] = 0;
	this->degree = SOFTWARE;
}

Student::Student(string ID, string first, string last, string email, int howOld, int days[], DegreeProgram deg)
{
	this->studentID = ID;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = email;
	this->daysLeft = new int[daysArraySize];
	for (int i = 0; i < daysArraySize; i++) this->daysLeft[i] = days[i];
	this->degree = deg;
}
string Student::getID()
{
	return studentID;
}

string Student::getFirst()
{
	return firstName;
}

string Student::getLast()
{
	return lastName;
}

string Student::getEmail()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDaysLeft()
{
	return daysLeft;
}

DegreeProgram Student::getDegreeProgram()
{
	return degree;
}

void Student::setID(string ID)
{
	studentID = ID;
}

void Student::setFirstName(string first)
{
	this->firstName = first;
}

void Student::setLastName(string last)
{
	this->lastName = last;
}

void Student::setEmail(string email)
{
	this->emailAddress = email;
}

void Student::setAge(int howOld)
{
	this->age = howOld;
}

void Student::setDaysLeft(int daysLeft[])
{
	this->daysLeft = new int[daysArraySize];
	for (int i = 0; i < 3; i++)
		this->daysLeft[i] = daysLeft[i];
}

void Student::setDegreeProgram(DegreeProgram deg) {
	this->degree = deg;
}


void Book::print()
{
	cout << left << setw(5) << studentID;
	cout << left << setw(45) << firstName;
	cout << left << setw(45) << lastName;
	cout << left << setw(45) << emailAddress;
	cout << left << setw(10) << age
	cout << left << setw(10) << daysLeft[0];
	cout << left << setw(10) << daysLeft[1];
	cout << left << setw(10) << daysLeft[2];
	cout << left << setw(20) << DegreeProgramStrings[getDegreeProgram()];
}

Student::~Student()
{
	if (daysLeft != nullptr) {
		delete[] daysLeft;
		daysLeft = nullptr;
	}
}