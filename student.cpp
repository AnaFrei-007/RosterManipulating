#include "student.h"
#include <iostream>
#include <string>
using namespace std;



/*parameterless constructor*/
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < courseDaysArraySize; i++) {
		this->courseDays[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SOFTWARE;

}

/*constructor with parameters*/
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < courseDaysArraySize; i++) {
		this->courseDays[i] = courseDays[i];
	}
	this->degreeProgram = degreeProgram;
}


Student::~Student() {} /*destructor*/


/*getters*/
string Student::getStudentID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int* Student::getCourseDays() {
	return this->courseDays;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}


/*setters*/
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setCourseDays(int courseDays[]) {
	for (int i = 0; i < courseDaysArraySize; i++) {
		this->courseDays[i] = courseDays[i];
	}
}

void Student::setDegreeProgram(DegreeProgram dp) {
	this->degreeProgram = dp;
}

void Student::print() {
	cout << this->getStudentID() << '\t';
	cout << /*"First Name: " <<*/ this->getFirstName() << '\t';
	cout << /*"Last Name: " <<*/ this->getLastName() << '\t';
	cout << /*"Age: " <<*/ this->getAge() << '\t';
	cout << /*"daysInCourse: */"{" << this->getCourseDays()[0] << ',';
	cout << this->getCourseDays()[1] << ',';
	cout << this->getCourseDays()[2] << "} ";
	cout << /*"Degree Program: " <<*/ degreeProgramStrings[this->getDegreeProgram()] << endl;
}