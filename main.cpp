#include <iostream>;
#include <iomanip>;
#include <string>;
#include "student.h";
#include "roster.h";
using std::string;
using std::cout;
using std::left;
using std::setw;
using std::cerr;

const int numStudents = 5;


const string studentData[] =

{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Christian,McCorkle,cmcc287@wgu.egu,23,7,12,32,SOFTWARE" };

int main()
{
	Roster* ros = new Roster(numStudents);
	cout << "Parsing data and adding students:\t";
	for (int i = 0; i < numStudents; i++)
	{
		ros->parseAdd(studentData[i]);
	}
	cout << "DONE.\n";
	cout << "Displaying all students:\n";
	ros->print_All();

	cout << "Removing F4:\n";
	if (ros->remove("F4")) ros->print_All();
	else cout << "Student not found!\n";

	cout << "Removing F4:\n";
	if (ros->remove("F4")) ros->print_All();
	else cout << "Student not found!\n";

	ros->printAverageDaysLeft("F3");

	ros->printInvalidEmailAddresses();


	ros->printByDegreeProgram(SOFTWARE);
	ros->printByDegreeProgram(SECURITY);

	system("pause");
	return 0;
}