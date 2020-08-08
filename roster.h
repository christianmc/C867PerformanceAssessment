#include <iostream>;
#include <iomanip>;
#include <string>;
using std::string;
using std::cout;
using std::left;
using std::setw;
using std::cerr;

class Roster {
public:
	int lastIndex;
	int capacity;
	Student** students;
	Roster();
	Roster(int capacity);
	void parseAdd(string datarow);
	void print_All();
	bool remove(string studentID);
	void printAverageDaysLeft(string studentID);
	void printInvalidEmailAddresses();
	void printByDegreePragram(DegreeProgram deg);
	~Roster();
};