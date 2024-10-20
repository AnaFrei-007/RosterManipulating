#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;


void Roster::parse(string studentData) {
	DegreeProgram dp = SOFTWARE;

	/*Student ID*/
	int rhs = studentData.find(",");
	string studentIDTemporary = studentData.substr(0, rhs); //ID

	/*First Name*/
	int lhs = rhs + 1; //moves past the comma
	rhs = studentData.find(",", lhs);
	string firstNameTemporary = studentData.substr(lhs, rhs - lhs); //first name

	/*Last Name*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastNameTemporary = studentData.substr(lhs, rhs - lhs); //last name

	/*Email Address*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddressTemporary = studentData.substr(lhs, rhs - lhs); //email address

	/*Age*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int ageTemporary = std::stoi(studentData.substr(lhs, rhs - lhs)); //age, string converted to int

	/*Days in Course 1*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d1 = std::stoi(studentData.substr(lhs, rhs - lhs)); //daysInCourse1, string converted to int

	/*Days in Course 2*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d2 = std::stoi(studentData.substr(lhs, rhs - lhs)); //daysInCourse2, string converted to int

	/*Days in Course 3*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d3 = std::stoi(studentData.substr(lhs, rhs - lhs)); //daysInCourse3, string converted to int

	/*Degree Program*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string degreeProgramTemporary = studentData.substr(lhs, rhs - lhs); //degree program

	/*if-else statement for degree program*/
	if (degreeProgramTemporary == "SECURITY") {
		dp = SECURITY;
	}
	else if (degreeProgramTemporary == "NETWORK") {
		dp = NETWORK;
	}

	/*Add Method*/
	add(studentIDTemporary, firstNameTemporary, lastNameTemporary, emailAddressTemporary, ageTemporary, d1, d2, d3, dp);
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int courseDaysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseDaysArray, degreeProgram);
}


void Roster::printAll() {

	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray)[i]->print();
	}
}


/*degree program*/
void Roster::printByDegreeProgram(DegreeProgram dp) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}


/*invalid emails*/
void Roster::printInvalidEmails() {
	bool invalid = false;
	for (int i = 0; i < Roster::lastIndex; i++) {
		string emailAddressTemporary = (classRosterArray[i]->getEmailAddress());
		if ((emailAddressTemporary.find('@') == string::npos) || (emailAddressTemporary.find('.') == string::npos) || (emailAddressTemporary.find(' ') != string::npos)) {
			invalid = true;
			cout << emailAddressTemporary << " - is invalid." << endl;
		}
	}
	if (!invalid) {
		cout << "All emails are valid." << endl;
	}
}


/*average days in course*/
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << "Student ID: " << classRosterArray[i]->getStudentID();
		cout << ", average days in course is: ";
		cout << (classRosterArray[i]->getCourseDays()[0]
			+ classRosterArray[i]->getCourseDays()[1]
			+ classRosterArray[i]->getCourseDays()[2]) / 3 << std::endl;
	}
	cout << endl;
}


/*remove student*/
void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			for (int j = i; j < Roster::lastIndex; ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			Roster::lastIndex--;
		}
	}
	if (found == true) {
		cout << studentID << " removed." << endl << endl;
		this->printAll();
	}
	else {
		cout << studentID << " not found." << endl;
	}
}


/*release allocated memory*/
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete this->classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

