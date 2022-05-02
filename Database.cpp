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
    cout << "Which option would you like: " << endl;
    int input = -1;
    cin >> input; //FIXME: error handle user input
    return input;
}

void Database::printAllStudents() {

}

void Database::printAllFaculty() {

}

void Database::printStudentInfo() {

}

void Database::printFacultyInfo() {

}

void Database::printFacultyInfoFromStudent() {

}

void Database::printFacultyAdviseesInfo() {

}

void Database::addNewStudent() {

}

void Database::deleteStudent() {

}

void Database::addNewFaculty() {

}

void Database::deleteFaculty() {

}

void Database::changeStudentAdvisors() {

}

void Database::removeFacultyAdvisees() {

}

void Database::undo() {
    
}