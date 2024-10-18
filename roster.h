#pragma once
#include "student.h"
#include <iostream>
#include <string>


class Roster
{
private:
	int lastIndex = -1; //last student in Roster
	const static int numStudents = 5;

public:
	Student* classRosterArray[numStudents];
	void parse(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void remove(string StudentID);
	void printAll();
	void printAverageDaysInCourse(string StudentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	/*destructor*/
	~Roster();
};