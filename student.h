#pragma once
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;




/*D1*/
class Student
{
public:
	const static int courseDaysArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[courseDaysArraySize];
	DegreeProgram degreeProgram;

public:
	Student(); /*parameterless constructor*/
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[], DegreeProgram degreeProgram); /*constructor with parameters*/
	~Student(); /*destructor*/

/*D2*/
	/*getters*/
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getCourseDays();
	DegreeProgram getDegreeProgram();

	/*setters*/
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCourseDays(int courseDays[]);
	void setDegreeProgram(DegreeProgram dp);

	void print();
};