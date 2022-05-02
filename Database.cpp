#include "Database.h"

Database::Database() { // default constructor
    masterStudent = new BST<Student>();
    masterFaculty = new BST<Faculty>();
}

Database::~Database() { // destructors
    delete masterStudent;
    delete masterFaculty;
}

void Database::run() {
    // check if files "facultyTable" & "studentTable" exist in current directories
        // if they do: put them in as data for masterStudent & masterFaculty (object serialization).
        // else: initialize masterStudent & masterFaculty as empty BSTs.

    int option = printMenu();

    while (option != 14) {

        switch(option) {
            case 1:
                printAllStudents();
                break;
            case 2:
                printAllFaculty();
                break;
            case 3:
                printStudentInfo();
                break;
            case 4:
                printFacultyInfo();
                break;
            case 5:
                printFacultyInfoFromStudent();
                break;
            case 6:
                printFacultyAdviseesInfo();
                break;
            case 7:
                addNewStudent();
                break;
            case 8:
                deleteStudent();
                break;
            case 9:
                addNewFaculty();
                break;
            case 10:
                deleteFaculty();
                break;
            case 11:
                changeStudentAdvisors();
                break;
            case 12:
                removeFacultyAdvisees();
                break;
            case 13:
                undo();
                break;
        }

        option = printMenu();
    }
}

int Database::printMenu() {
    // print menu
    cout << endl << "1) Print all students and their information (sorted by ascending ID number)." << endl;
    cout << "2) Print all faculty and their information (sorted by ascending ID number)." << endl;
    cout << "3) Find and display student information given the students id." << endl;
    cout << "4) Find and display faculty information given the faculty id." << endl;
    cout << "5) Given a student's id, print the name and info of their faculty advisor." << endl;
    cout << "6) Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7) Add a new student." << endl;
    cout << "8) Delete a student given the id." << endl;
    cout << "9) Add a new faculty member." << endl;
    cout << "10) Delete a faculty member given the id." << endl;
    cout << "11) Change a student's advisor given the student id and the new faculty id." << endl;
    cout << "12) Remove an advisee from a faculty member given the ids. " << endl;
    cout << "13) Rollback." << endl;
    cout << "14) Exit." << endl << endl;

    // user input
    cout << "Which option would you like: ";
    int input = -1;
    cin >> input;

    // error handling: user input
    while (input > 14 || input < 1) {
        cout << "Please pick one of the options (1-14): ";
        cin >> input;
    }

    return input;
}

void Database::printAllStudents() {
    // traverse & return (all students)
}

void Database::printAllFaculty() {
    // traverse & return (all faculty)
}

void Database::printStudentInfo() {
    // find student
}

void Database::printFacultyInfo() {
    // find faculty
}

void Database::printFacultyInfoFromStudent() {
    // find student, store faculty id, find faculty
}

void Database::printFacultyAdviseesInfo() {
    // find faculty, return advisees info
}

void Database::addNewStudent() {
    // insert student
}

void Database::deleteStudent() {
    // delete student
}

void Database::addNewFaculty() {
    // insert faculty
}

void Database::deleteFaculty() {
    // delete faculty
}

void Database::changeStudentAdvisors() {
    // find student, modify student
}

void Database::removeFacultyAdvisees() {
    // find faculty, modify faculty
}

void Database::undo() {

}