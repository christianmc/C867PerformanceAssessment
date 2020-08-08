#include <iostream>;
#include <iomanip>;
#include <string>;
using std::string;
using std::cout;
using std::left;
using std::setw;
using std::cerr;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysLeft;
	DegreeProgram degree;

public:
	const static int daysArraySize = 3;
	Student();
	Student(string ID, string first, string last, string email, int howOld, int days[], DegreeProgram deg);

	string getID();
	string getFirst();
	string getLast();
	string getEmail();
	int getAge();
	int* getDaysLeft();
	DegreeProgram getDegreeProgram();

	void setID(string ID);
	void setFirst(string first);
	void setLast(string last);
	void setEmail(string email);
	void setAge(int howOld);
	void setDaysLeft(int daysLeft[]);
	void setDegreeProgram(DegreeProgram deg);
	void print();

	~Student();
};