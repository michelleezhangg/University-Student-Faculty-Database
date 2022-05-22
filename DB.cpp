#include "DB.h"

DB::DB(){

    masterStudent = new BST<Student>();
    masterFaculty = new BST<Faculty>();

    rb = new RollBack();

    s = new Serialization();
}

DB::~DB(){

    delete masterStudent;
    delete masterFaculty;
    delete rb;
}

void DB::simulate(){

    //s->readToStudentDB(masterStudent);
    //s->readToFacultyDB(masterFaculty);

    int option = printOptions();

    while (true) {

        if (option == 1){
            printAllStudentInfo();

        } else if (option == 2) {
            printAllFacultyInfo();

        } else if (option == 3) {
            printSpecificStudent();
            
        } else if (option == 4) {
            printSpecificFaculty();
            
        } else if (option == 5) {
            printFacultyAdvisor();
            
        } else if (option == 6) {
            printFacultyAdvisees();
            
        } else if (option == 7) {
            addNewStudent();
            
        } else if (option == 8) {
            deleteStudent();
            
        } else if (option == 9) {
            addNewFaculty();
            
        } else if (option == 10) {
            deleteFaculty();
            
        } else if (option == 11) {
            changeStudentAdvisor();
            
        } else if (option == 12) {
            removeAdvisee();
            
        } else if (option == 13) {
            Undo();
        } else if (option == 14){

            Exit();
            break;
        } else {

            cout << endl << "NOT A VALID INPUT." << endl;
        }

        option = printOptions();
    }
}

void DB::printAllStudentInfo(){ //option 1

    if (masterStudent->isEmpty()){

        cout << endl << "There are no students in the database. Please add one."<< endl;

    } else {

        masterStudent->printNodes();
    }


}

void DB::printAllFacultyInfo(){ //option 2

    if (masterFaculty->isEmpty()){

        cout << endl << "There are no faculty members in the database. Please add one."<< endl;
    } else {

        masterFaculty->printNodes();
    }


}

void DB::printSpecificStudent(){ //option 3

    while (true){

        if (masterStudent->isEmpty()){

            cout << endl << "There are no students in the database. Please add one." << endl;
            break;

        }
        int sID;
        cout << "Enter the student ID: ";

        cin >> sID;

        if (masterStudent->idExists(sID)) {
            masterStudent->printNode(sID);
            return;

        } else {
            cout << endl << "Student does not exist in the database." << endl;
            return;
        }

    }

}

void DB::printSpecificFaculty(){ //option 4

    while (true){

        if (masterFaculty->isEmpty()){

            cout << endl << "There are no faculty members in the database. Please add one." << endl;
            break;

        }

        int fID;
        cout << "Enter the faculty ID: ";

        cin >> fID;

        if (masterFaculty->idExists(fID)) {
            masterFaculty->printNode(fID);
            return;

        } else {
            cout << endl << "Faculty does not exist in the database." << endl;
            return;
        }

    }


}

void DB::printFacultyAdvisor(){ //option 5

    int sID;

    while (true) {


        if (masterStudent->isEmpty()){

            cout << endl << "There are not students in the database. Please add one. " << endl;
            break;

        } else {

            cout << "Enter the student ID: ";
            cin >> sID;

            if (masterStudent->idExists(sID)){

                cout << endl << masterStudent->getNode(sID).name << "'s Advisor Information: \n" << endl;

                int advisorID = masterStudent->getNode(sID).getAdvisorID();

                cout << masterFaculty->getNode(advisorID) << endl;

                break;

            } else {

                cout << endl << "That student does not exist in the database." << endl;
                break;
            }

        }
    }

}

void DB::printFacultyAdvisees(){ //option 6
    
    int fID;

    while(true){


        if (masterFaculty->isEmpty()){

            cout << endl << "There are no faculty members in the database. Please add one." << endl;
            break;
        
        } 

        cout << "Please enter faculty ID: ";

        cin >> fID;

        if (masterFaculty->idExists(fID)) {

            cout << masterFaculty->getNode(fID).name << "'s advisees: \n" << endl;
            Faculty faculty = masterFaculty->getNode(fID);

            for (int i = 0; i < faculty.getAdviseeIDs().size(); i++){

                cout << masterStudent->getNode(faculty.getAdviseeIDs().at(i));
            }

            break;

        } else {

            cout << endl << "Faculty member is not in the database." << endl;
            break;
        }
    } 
    

}

void DB::addNewStudent(){ //option 7

    int id;
    string name;
    string level;
    string major;
    double gpa;
    int advisorID;
    bool isNewID = false;

    if (masterFaculty->isEmpty()) {
        cout << endl << "There are no advisors in the database. Add an advisor before adding student." << endl;

    } else {

        srand(time(NULL));
        id = rand() % 900 + 100; //Max of 1000 IDs

        while(isNewID == false) {

            if(masterFaculty->idExists(id)) {

                id = rand() % 900 + 100;

            } else {
                isNewID = true;
            }
        }

        cout << endl << "Please enter information about the student: " << endl;

        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Level: ";
        cin >> level;

        cout << "Major: ";
        cin.ignore();
        getline(cin, major);

        while (true) {
            cin.clear();
            cout << "GPA: ";
            cin >> gpa;
        
            if(!cin) {
                cin.clear();
                cin.ignore();
                cout << "INVALID INPUT" << endl;
                continue;
            }
            break;
        }


        while (true){

            cout << "Enter your advisor ID: ";
            cin >> advisorID;

            if (masterFaculty->idExists(advisorID)){

                masterFaculty->getNode(advisorID).addAdvisee(id);
                break;

            } else {
                cout << endl << "This advisor does not exist in the database." << endl;
                break;
            }



        }

        Student *student = new Student (name, id, level, major, gpa, advisorID);

        masterStudent->insert(*student);


        cout << endl << "-----------------------------";
        cout << endl << "SUCCESSFULLY ADDED STUDENT" << endl;
        cout << "-----------------------------" << endl << endl;

        masterStudent->printNodes();

        rb->studentAction("ADD STUDENT", student);
    }



}

void DB::deleteStudent(){ //option 8

    while (true){

        if (masterStudent->isEmpty()){

            cout << endl << "There are no students in the database. Please add one." << endl;
            break;

        } else {

            int sID;
            cout << "Enter the student ID: ";

            cin >> sID;

            if (masterStudent->idExists(sID)) {
                
                Student student = masterStudent->getNode(sID);
                masterStudent->deleteNode(student);

                int advisorID = student.getAdvisorID();
                Faculty faculty = masterFaculty->getNode(advisorID);
                faculty.removeAdvisee(sID);

                cout << endl << "-----------------------------";
                cout << "STUDENT SUCCESSFULLY DELETED" << endl;
                cout << "-----------------------------" << endl << endl;

                rb->studentAction("DELETE STUDENT",&student);
                break;

            } else {

                cout << endl << "Student does not exist in the database." << endl;
                break;
            }
        }

    }

}

void DB::addNewFaculty(){ //option 9

    int id;
    string name;
    string level;
    string department;
    bool isNewID = false;

    cout << endl << "Please enter information about the faculty: " << endl;

    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Level: ";
    cin >> level;

    cout << "Department: ";
    cin.ignore();
    getline(cin, department);

    srand(time(NULL));
    id = rand() % 900 + 100; //Max of 1000 IDs

    while(isNewID == false) {

        if(masterFaculty->idExists(id)) {

            id = rand() % 900 + 100;
        } else {
            isNewID = true;
        }
    }


    Faculty *faculty = new Faculty (name, id, level, department);


    masterFaculty->insert(*faculty);

    cout << endl << "-----------------------------";
    cout << endl << "SUCCESSFULLY ADDED FACULTY" << endl;
    cout << "-----------------------------" << endl << endl;


    masterFaculty->printNodes();

    rb->facultyAction("ADD FACULTY", faculty);

}

void DB::deleteFaculty(){ //option 10

    while (true){

        if (masterFaculty->isEmpty()){

            cout << endl << "There are no faculty members in the database. Please add one." << endl;
            break;

        } else {

            int fID;
            cout << "Enter the faculty ID: ";

            cin >> fID;

            if (masterFaculty->idExists(fID)) {
                
                Faculty faculty = masterFaculty->getNode(fID);
                masterFaculty->deleteNode(faculty);

                for (int i =0; i < faculty.getAdviseeIDs().size(); ++i){

                    int adviseeID = faculty.getAdviseeIDs().at(i);
                    Student student = masterStudent->getNode(adviseeID);
                    student.setAdvisorID(-1);
                }

                cout << endl << "-----------------------------";
                cout << endl << "FACULTY SUCCESSFULLY DELETED" << endl;
                cout << "-----------------------------" << endl << endl;

                rb->facultyAction("DELETE FACULTY", &faculty);
                break;

            } else {

                cout << endl << "Faculty member does not exist in the database." << endl;
                break;
            }
        }

    }
}

void DB::changeStudentAdvisor(){ //option 11

    int studentID;
    int facultyID;

    Student student;
    Faculty faculty;

    if (masterStudent->isEmpty()){

        cout << endl << "There are no students in the database. Please add one." << endl;
        return;
    }

    if (masterFaculty->isEmpty()){

        cout << endl << "There are no faculty members in the database. Please add one." << endl;
        return;
    }

    while (true){

        cout << "Enter student ID: ";
        cin >> studentID;

        if (masterStudent->idExists(studentID)){

            student = masterStudent->getNode(studentID);
            break;

        } else {

            cout << endl << "That student does not exist in the database." << endl;
            break;
        }
    }

    Faculty oldfac = masterFaculty->getNode(student.advisorID);

    while (true){

        cout << "Enter faculty ID: ";
        cin >> facultyID;

        if (masterFaculty->idExists(facultyID)){

            faculty = masterFaculty->getNode(facultyID);
            break;

        } else {

            cout << endl << "That faculty member does not exist in the database." << endl;
            break;

        }
    }

    for(int i = 0; i < oldfac.getAdviseeIDs().size(); i++){
        //When the ID is found delete it from the list
        if(oldfac.getAdviseeIDs().at(i) == studentID)
        {
            oldfac.removeAdvisee(studentID);
        }
    }

    faculty.addAdvisee(studentID);
    student.setAdvisorID(facultyID);

}

void DB::removeAdvisee(){ //option 12


    if (masterStudent->isEmpty()){

        cout << endl << "There are no students in the database. Please add one." << endl;
        return;
    }


    if (masterFaculty->isEmpty()){

        cout << endl << "There are no faculty members in the database. Please add one." << endl;
        return;
    }

    int advisorID;
    int fID;
    int sID;
    Student student;
    Faculty faculty;

    while (true){

        cout << "Enter the student ID: ";
        cin >> fID;

        if (masterStudent->idExists(fID)){

            break;

        } else {

            cout << "This student does not exist in the database." << endl;
            break;

        }
    }

    while (true) {

        cout << "Please enter faculty ID: " << endl;

        cin >> advisorID;

        if (masterFaculty->idExists(advisorID)){

            break;

        } else {

            cout << "That faculty member does not exist in the database." << endl;
            break;
        }
    }

    student = masterStudent->getNode(sID);
    faculty = masterFaculty->getNode(fID);

    faculty.removeAdvisee(fID);
    student.setAdvisorID(advisorID);

}

void DB::Undo(){ //option 13

    if(!rb->undo(masterStudent, masterFaculty)){

        cout << endl << "UNDO FAILED." << endl;
    }
}

void DB::Exit(){ //option 14

    
    s->serialize(masterStudent, masterFaculty);
    cout << "Exiting Program." << endl;
    exit(0);

}

int DB::printOptions(){

    int userInput;

    cout << "------------------------------------------------------------------------------" << endl;

    cout << endl << "PICK AN OPTION: " << endl;

    cout << endl << "1. Print all students and their information (sorted by ascending id #)" << endl; 
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl; 
    cout << "3. Find and display student information given the students id" << endl; 
    cout << "4. Find and display faculty information given the faculty id" << endl; 
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl; 
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl; 
    cout << "7. Add a new student" << endl; 
    cout << "8. Delete a student given the id" << endl; 
    cout << "9. Add a new faculty member" << endl; 
    cout << "10. Delete a faculty member given the id." << endl; 
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl; 
    cout << "12. Remove an advisee from a faculty member given the ids" << endl; 
    cout << "13. Rollback" << endl; 
    cout << "14. Exit" << endl; 

    cout << endl << "------------------------------------------------------------------------------" << endl;
    cout << endl;


    cout << "Option: ";
    cin >> userInput;

    return userInput;
}

