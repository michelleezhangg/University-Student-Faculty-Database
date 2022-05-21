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
    s = new Serialization();
}

Database::~Database() { // destructors
    delete masterStudent;
    delete masterFaculty;
    delete rb;
    delete s;
}

void Database::run() {
    //s->serialize();
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
                printAdvisorInfo();
                break;
            case 6:
                printAdviseesInfo();
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
                changeAdvisor();
                break;
            case 12:
                removeAdvisee();
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
 * prints out the menu for the user and obtains the user's option input.
 * @return input an integer representing the user's number choice from the menu.
 * auxiliary function for the function run()
 */
int Database::printMenu() {
    // print menu
    cout << endl << "1. Print all students and their information (sorted by ascending ID number)." << endl;
    cout << "2. Print all faculty and their information (sorted by ascending ID number)." << endl;
    cout << "3. Find and display student information given the student's id." << endl;
    cout << "4. Find and display faculty information given the faculty id." << endl;
    cout << "5. Given a student ID, print the name and info of their faculty advisor." << endl;
    cout << "6. Given a faculty ID, print all the names and info of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the ID." << endl;
    cout << "9. Add a new faculty member." << endl;
    cout << "10. Delete a faculty member given the ID." << endl;
    cout << "11. Change a student's advisor given the student id and the new faculty ID." << endl;
    cout << "12. Remove an advisee from a faculty member given the IDs. " << endl;
    cout << "13. Rollback." << endl;
    cout << "14. Exit." << endl << endl;

    // user input
    cout << "Please enter an option (1-14): ";
    int input;
    cin >> input;

    // error handling: user input
    while (input > 14 && input < 1) {
        cout << "Invalid input." << endl;
        cout << "Please enter an option (1-14): ";
        cin >> input;
    }

    return input;
}

/**
 * option 1
 * prints all of the students in the database.
 * if the database contains no students, a message will print out informing the user.
 */
void Database::printAllStudents() {
    if (masterStudent->isEmpty()) // checks if tree is empty
        cout << "There are no students in your database." << endl;
    else
        masterStudent->printNodes();
}

/**
 * option 2
 * prints all of the faculty members in the database.
 * if the database contains no faculty members, a message will print out informing the user.
 */
void Database::printAllFaculty() {
    if (masterFaculty->isEmpty()) // checks if tree is empty
        cout << "There are no faculty members in your database." << endl;
    else
        masterFaculty->printNodes();
}

/**
 * option 3
 * prints out a student's information given the student ID.
 * if the database contains no students, a message will print out informing the user.
 */
void Database::printStudentInfo() {
    if (masterStudent->isEmpty()) // checks if tree is empty
        cout << "There are no students in your database." << endl;

    else {
        while (true) {
            // get user's input
            cout << "Please enter the student ID: ";
            int id;
            cin >> id;

            // finds student
            if (masterStudent->idExists(id)) { // student is found
                cout << endl << masterStudent->getNode(id) << endl;
                break;
            } else // student is not found
                cout << "That student does not exist in the database." << endl;
                cout << "Please try again." << endl;
        }
    }
}

/**
 * option 4
 * prints out a student's advisor information given the student ID.
 * if the database contains no faculty members, a message will print out informing the user.
 */
void Database::printFacultyInfo() {
    if (masterFaculty->isEmpty()) // checks if tree is empty
        cout << "There are no faculty members in your database." << endl;

    else {
        while (true) {
            // get user's input
            cout << "Please enter the faculty ID: ";
            int id;
            cin >> id;

            // finds faculty
            if (masterFaculty->idExists(id)) { // faculty is found
                cout << endl << masterFaculty->getNode(id) << endl;
                break;
            } else // faculty is not found
                cout << "That faculty does not exist in the database." << endl;
                cout << "Please try again." << endl;
        }
    }
}

/**
 * option 5
 * print out a student's advisor's info given the student ID.
 * if the database contains no students, a message will print out informing the user.
 */
void Database::printAdvisorInfo() {
    if (masterStudent->isEmpty()) // checks if tree is empty
        cout << "There are no students in your database." << endl;
    else {
        while (true) {
            // get user's input
            cout << "Please enter the student ID: ";
            int id;
            cin >> id;

            // finds student
            if (masterStudent->idExists(id)) { // student is found
                int advisorID = masterStudent->getNode(id).getAdvisorID();
                cout << endl << masterFaculty->getNode(advisorID) << endl;
                break;
            } else // student is not found
                cout << "That student does not exist in the database." << endl;
                cout << "Please try again." << endl;
        }
    }
}

/**
 * option 6
 * prints the advisees of a faculty member given the faculty ID.
 * if the database contains no faculty members, a message will print out informing the user.
 */
void Database::printAdviseesInfo() {
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

                cout << endl;

                for (int i = 0; i < f.getAdviseesIDs().size(); ++i)
                    cout << masterStudent->getNode(f.getAdviseesIDs().at(i)) << endl;

                break;
            } else // faculty is not found
                cout << "That faculty does not exist in database." << endl;
                cout << "Please try again." << endl;
        }
    }    
}

/**
 * option 7
 * adds a new student to the database.
 * the name, level, major, and gpa are prompted from the user.
 * the student ID is randomized and must be unique.
 * if the database contains no faculty members, a message will print out informing the user that they must add a faculty member before adding a student in the database.
 */
void Database::addNewStudent() {
    string name = "";
    int id = -1;
    string level = "";
    string major = "";
    double gpa = 0.0;
    int advisorID = -1;

    if (masterFaculty->isEmpty()) // checks for if there are faculty/advisors
        cout << "You must add a faculty member (advisor) before adding a new student." << endl;
    else {
        cout << "Please enter the information about the student." << endl;
        
        cout << "Name: ";
        cin >> name;

        cout << "Level: ";
        cin >> level;

        cout << "Major: ";
        cin >> major;

        cout << "GPA: ";
        cin >> gpa;

        // randomizing student ID (unique)
        while (masterStudent->idExists(id))
            id = rand() % 1000;

        // assigning advisor
        while (true) {
            cout << "Enter an advisor ID: ";
            cin >> advisorID;

            if (masterFaculty->idExists(advisorID)) {
                Faculty f = masterFaculty->getNode(advisorID);
                f.addAdvisee(id);
                break;
            } else {
                cout << "This advisor does not exist" << endl;
            }
        }

        Student *s = new Student(id, name, level, major, gpa, advisorID);
        masterStudent->insert(*s);

        rb->studentAction(s, "is"); // rollback
    }
}

/**
 * option 8
 * delete a student from the database given the student ID.
 * if the database contains no students, a message will print out informing the user.
 */
void Database::deleteStudent() {
    if (masterStudent->isEmpty()) // checks if tree is empty
        cout << "There are no students in your database." << endl;

    else {
        while (true) {
            // get user's input
            cout << "Please enter the student ID: ";
            int id;
            cin >> id;

            // finds student
            if (masterStudent->idExists(id)) { // student is found
                Student s = masterStudent->getNode(id);
                masterStudent->deleteNode(s);

                // remove this student from its advisor's advisee vector
                int advisorID = s.getAdvisorID();
                Faculty f = masterFaculty->getNode(advisorID);
                f.removeAdvisee(id);

                rb->studentAction(&s, "ds"); // roll back
                break;
            } else // student is not found
                cout << "That student does not exist in the database." << endl;
                cout << "Please try again." << endl;
        }
    }
}

/**
 * option 9
 * adds a new faculty member to the database.
 * the name, level, and department are prompted from the user.
 * the faculty ID is randomized and must be unique.
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

    // randomizing faculty ID (unique)
    while (masterFaculty->idExists(id))
        id = rand() % 1000;

    Faculty *f = new Faculty(id, name, level, department);
    masterFaculty->insert(*f);
    rb->facultyAction(f, "if");
}

/**
 * option 10
 * delete a faculty member from the database given the student ID.
 * the faculty member's advisee's advisor will be set to -1.
 * if the database contains no faculty members, a message will print out informing the user.
 */
void Database::deleteFaculty() {
    if (masterFaculty->isEmpty()) // checks if tree is empty
        cout << "There are no faculty members in your database." << endl;

    else {
        while (true) {
            // get user's input
            cout << "Please enter the faculty ID: ";
            int id;
            cin >> id;

            // finds faculty
            if (masterFaculty->idExists(id)) { // faculty is found
                Faculty f = masterFaculty->getNode(id);
                masterFaculty->deleteNode(f);

                // remove faculty from advisees (set to NULL)
                for (int i = 0; i < f.getAdviseesIDs().size(); ++i) {
                    int adviseeID = f.getAdviseesIDs().at(i);
                    Student s = masterStudent->getNode(adviseeID);
                    s.setAdvisorID(-1);
                }

                rb->facultyAction(&f, "df"); // rollback
                break;
            } else // faculty is not found
                cout << "That faculty does not exist in the database." << endl;
                cout << "Please try again." << endl;
        }
    }
}

/**
 * option 11
 * changes a student's advisor given the student ID and the new faculty member's ID.
 * if the database contains no students, a message will print out informing the user.
 * if the database contains no faculty members, a message will print out informing the user.
 */
void Database::changeAdvisor() {
    // checks if any tree is empty
    if (masterStudent->isEmpty())
        cout << "There are no students in your database." << endl;
        return;
    if (masterFaculty->isEmpty())
        cout << "There are no faculty members in your database." << endl;
        return;


    int studentID;
    int facultyID;
    
    // get user's input: student ID
    while (true) {
        cout << "Please enter the student ID: ";
        cin >> studentID;

        if (masterStudent->idExists(studentID))
            break;
        else
            cout << "That student does not exist in the database." << endl;
            cout << "Please try again." << endl;
    }

    // get user's input: faculty ID
    while (true) {
        cout << "Please enter the faculty ID: ";
        cin >> facultyID;

        if (masterFaculty->idExists(facultyID))
            break;
        else
            cout << "That faculty does not exist in the database." << endl;
            cout << "Please try again." << endl;
    }

    // modifying advisor & advisee for the student & faculty
    Student s = masterStudent->getNode(studentID);
    Faculty f = masterFaculty->getNode(facultyID);

    s.setAdvisorID(facultyID);
    f.addAdvisee(studentID);
}

/**
 * option 12
 * removes a faculty member's advisee given the faculty member's ID and the advisee's ID.
 * prompts for the advisee's new advisor's ID and assigns that to the removed advisee's advisor.
 * if the database contains no faculty members, a message will print out informing the user.
 * if the database contains no students, a message will print out informing the user.
 */
void Database::removeAdvisee() {
    // checks if any tree is empty
    if (masterFaculty->isEmpty())
        cout << "There are no faculty members in your database." << endl;
        return;
    if (masterStudent->isEmpty())
        cout << "There are no students in your database." << endl;
        return;

    int studentID;
    int facultyID;
    int advisorID;

    // get user's input: faculty ID
    while (true) {
        cout << "Please enter the faculty ID: ";
        cin >> facultyID;

        if (masterFaculty->idExists(facultyID))
            break;
        else
            cout << "That faculty does not exist in the database." << endl;
            cout << "Please try again." << endl;
    }

    // get user's input: student ID
    while (true) {
        cout << "Please enter the student ID: ";
        cin >> studentID;

        if (masterStudent->idExists(studentID))
            break;
        else
            cout << "That student does not exist in the database." << endl;
            cout << "Please try again." << endl;
    }

    // get user's input: new advisor ID
    while (true) {
        cout << "Please enter the new advisor ID: ";
        cin >> advisorID;

        if (masterFaculty->idExists(advisorID))
            break;
        else
            cout << "That faculty does not exist in the database." << endl;
            cout << "Please try again." << endl;
    }
    
    // modifying advisor & advisee for the student & faculty
    Faculty f = masterFaculty->getNode(facultyID);
    Student s = masterStudent->getNode(studentID);

    f.removeAdvisee(studentID);
    s.setAdvisorID(advisorID);
}

/**
 * option 13
 * undos the previous action.
 * if cannot undo, a message will print informing the user.
 */
void Database::rollBack() {
    if (!rb->undo(masterStudent, masterFaculty))
        cout << "Cannot undo" << endl;
}

/**
 * exits the program using serialization
 * option 14
 */
void Database::exit() {
    s->serialize(masterStudent, masterFaculty);
    cout << "Exiting program" << endl;
}
