/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Database Class.
*/

#include "Database.h"

Database::Database() { // default constructor
    masterStudent = new BST<Student>();
    masterFaculty = new BST<Faculty>();
    rb = new RollBack();
}

Database::~Database() { // destructors
    delete masterStudent;
    delete masterFaculty;
    delete rb;
}

void Database::run() {
    // 1. check if files "facultyTable" & "studentTable" exist in current directories
        // if they do: put them in as data for masterStudent & masterFaculty (object serialization).
        // else: initialize masterStudent & masterFaculty as empty BSTs.

    int option = printMenu();

    while (true) {

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
                changeStudentAdvisor();
                break;
            case 12:
                removeFacultyAdvisee();
                break;
            case 13:
                rollBack();
                break;
            case 14:
                exit();
                break;
        }

        if (option == 14)
            break;

        option = printMenu();
    }
}

/**
 * prints out the menu for the user and obtains the user's input.
 * @return input an integer representing the user's number choice from the menu.
 * auxiliary function for the function run()
 */
int Database::printMenu() {
    // print menu
    cout << endl << "1. Print all students and their information (sorted by ascending ID number)." << endl;
    cout << "2. Print all faculty and their information (sorted by ascending ID number)." << endl;
    cout << "3. Find and display student information given the student's id." << endl;
    cout << "4. Find and display faculty information given the faculty id." << endl;
    cout << "5. Given a student's id, print the name and info of their faculty advisor." << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the id." << endl;
    cout << "9. Add a new faculty member." << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student's advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids. " << endl;
    cout << "13. Rollback." << endl;
    cout << "14. Exit." << endl << endl;

    // user input
    cout << "Please enter an option (1-14): ";
    int input;
    cin >> input;

    // error handling: user input
    while (input > 14 || input < 1) {
        cout << "Please pick one of the options (1-14): ";
        cin >> input;
    }

    return input;
}

/**
 * prints all of the students in the database.
 * if the database contains no students, a message will print out informing the user.
 * option 1
 */
void Database::printAllStudents() {
    if (masterStudent->isEmpty()) // checks if tree is empty
        cout << "There are no students in your database." << endl;
    else
        masterStudent->printNodes();
}

/**
 * prints all of the faculty members in the database.
 * if the database contains no faculty members, a message will print out informing the user.
 * option 2
 */
void Database::printAllFaculty() {
    if (masterFaculty->isEmpty()) // checks if tree is empty
        cout << "There are no faculty members in your database." << endl;
    else
        masterFaculty->printNodes();
}

/**
 * prints out a student's information based on a user-entered ID.
 * option 3
 */
void Database::printStudentInfo() {
    while (true) {
        if (masterStudent->isEmpty()) // checks if tree is empty
            cout << "There are no students in your database." << endl;

        else {
            // get user's input
            cout << "Please enter the student ID: ";
            int id;
            cin >> id;

            // finds student
            if (masterStudent->idExists(id)) { // student is found
                cout << masterStudent->getNode(id) << endl;
                break;
            } else // student is not found
                cout << "That student does not exist in the database." << endl;
        }
    }
}

/**
 * prints out a faculty member's information based on a user-entered ID.
 * option 4
 */
void Database::printFacultyInfo() {
    while (true) {
        if (masterFaculty->isEmpty()) // checks if tree is empty
            cout << "There are no faculty members in your database." << endl;

        else {
            // get user's input
            cout << "Please enter the faculty ID: ";
            int id;
            cin >> id;

            // finds faculty
            if (masterFaculty->idExists(id)) { // faculty is found
                cout << masterFaculty->getNode(id) << endl;
                break;
            } else // faculty is not found
                cout << "That faculty does not exist in the database." << endl;
        }
    }
}

void Database::printFacultyInfoFromStudent() {
    // find student, store faculty id, find faculty
}

/**
 * prints the advisees of a faculty member
 */
void Database::printFacultyAdviseesInfo() {
    while (true) {
        if (masterFaculty->isEmpty()) // check if tree is empty
            cout << "There are no faculty members in your database." << endl;

        else {
            // get user's input
            cout << "Please enter the faculty ID: ";
            int id;
            cin >> id;

            if (masterFaculty->idExists(id)) { // faculty is found
                Faculty f = masterFaculty->getNode(id);
                cout << f.getAdviseesIDs() << endl;
                break;
            } else // faculty is not found
                cout << "That faculty does not exist in database." << endl;
        }
    }    
}

/**
 * adds a new student to the database.
 * the name, level, major, and gpa are prompted from the user.
 * the ID and the advisor ID are randomly generated.
 * option 7
 */
void Database::addNewStudent() {
    string name = "";
    int id = -1;
    string level = "";
    string major = "";
    double gpa = 0.0;
    int advisorID = -1;

    cout << "Please enter the information about the student." << endl;
    
    cout << "Name: ";
    cin >> name;

    cout << "Level: ";
    cin >> level;

    cout << "Major: ";
    cin >> major;

    cout << "GPA: ";
    cin >> gpa;

    // randomizing student ID
    while (masterStudent->idExists(id))
        id = rand() % 10000;

    // FIXME: assign random advisorID

    Student *s = new Student(id, name, level, major, gpa, advisorID);
}

/**
 * option 8
 */
void Database::deleteStudent() {
    // delete student
}

/**
 * adds a new faculty member to the database.
 * the name, level, and department are prompted from the user.
 * option 9
 */
void Database::addNewFaculty() {
    string name = "";
    int id = -1;
    string level = "";
    string department = "";

    cout << "Please enter the information about the faculty member." << endl;

    cout << "Name: ";
    cin >> name;

    cout << "Level: ";
    cin >> level;

    cout << "Department: ";
    cin >> department;

    Faculty *f = new Faculty(id, name, level, department);
    masterFaculty->insert(*f);
}

/**
 * option 10
 */
void Database::deleteFaculty() {
    // delete faculty
}

/**
 * option 11
 */
void Database::changeStudentAdvisor() {
    
}

/**
 * option 12
 */
void Database::removeFacultyAdvisee() {
    if (masterFaculty->isEmpty())
        cout << "There are no faculty members in your database." << endl;
    if (masterStudent->isEmpty())
        cout << "There are no students in your database." << endl;

    while (true){
        cout << "Enter the student ID to remove from faculty: ";
    }
}

/**
 * option 13
 */
void Database::rollBack() {

}

/**
 * option 14
 */
void Database::exit() {

}