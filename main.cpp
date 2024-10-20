#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numStudents = 5;

    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ana,Freitas,aif28@wgu.edu,23,38,15,26,SOFTWARE"
    };
    
    //F1
    cout << "Scripting and Programming: Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 012225342" << endl;
    cout << "Name: Ana Ferraz de Freitas" << endl << endl << endl;

    //F2
    Roster classRoster;

    //F3
    for (int i = 0; i < numStudents; i++) {
        classRoster.parse(studentData[i]);
    }

    //F4
    cout << "Displaying all students:" << endl;
    classRoster.printAll();
    cout << endl << endl;

    //Invalid emails
    cout << "Displaying invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl << endl;

    //Avg days
    cout << "Average days in course:" << endl;
    for (int i = 0; i < 1; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;

    //Degree Program: SOFTWARE
    cout << "Showing students in degree program: SOFTWARE" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    //Remove A3
    cout << "Removing A3:" << endl;
    classRoster.remove("A3");
    cout << endl;

    //Remove A3 again
    cout << "Removing A3 again:" << endl;
    classRoster.remove("A3");
    cout << endl;

    //Destructor
    cout << "Running the destructor..." << endl;
    classRoster.~Roster();

    return 0;
}































// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
