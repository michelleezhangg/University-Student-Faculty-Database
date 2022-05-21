#include "DB.h"

DB::DB(){

    masterStudent = new BST<Student>();
    masterFaculty = new BST<Faculty>();

    s = new Serialization();
}

DB::~DB(){

    delete masterStudent;
    delete masterFaculty;
}

void DB::simulate(){

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

        cout << "There are no students in the database."<< endl;

    } else {

        masterStudent->printNodes();
    }


}

void DB::printAllFacultyInfo(){ //option 2

    if (masterFaculty->isEmpty()){

        cout << "There are no faculty in the database."<< endl;
    } else {

        masterFaculty->printNodes();
    }


}

void DB::printSpecificStudent(){ //option 3

    while (true){

        if (masterStudent->isEmpty()){

            cout << "There are no students in the database" << endl;
            break;

        }
        int sID;
        cout << "Enter the student ID: " << endl;

        cin >> sID;

        if (masterStudent->idExists(sID)) {
            masterStudent->printNode(sID);
            return;

        } else {
            cout << "Student does not exist" << endl;
            return;
        }

    }

}

void DB::printSpecificFaculty(){ //option 4

    while (true){

        if (masterFaculty->isEmpty()){

            cout << "There are no faculty members in the database" << endl;
            break;

        }

        int fID;
        cout << "Enter the faculty ID: " << endl;

        cin >> fID;

        if (masterFaculty->idExists(fID)) {
            masterFaculty->printNode(fID);
            return;

        } else {
            cout << "Faculty does not exist" << endl;
            return;
        }

    }


}

void DB::printFacultyAdvisor(){ //option 5

    int sID;

    while (true) {


        if (masterStudent->isEmpty()){

            cout << "There are not students in the database. Please add one. " << endl;
            break;

        } else {

            cout << "Enter the student ID:" << endl;
            cin >> sID;

            if (masterStudent->idExists(sID)){

                cout << masterStudent->getNode(sID).name << "'s Advisor Information: \n" << endl;

                int advisorID = masterStudent->getNode(sID).getAdvisorID();

                cout << masterFaculty->getNode(advisorID) << endl;

            } else {

                cout << "That student does not exist." << endl;
            }

        }
    }

}

void DB::printFacultyAdvisees(){ //option 6
    
    int fID;

    while(true){


        if (masterFaculty->isEmpty()){

            cout << "There are no faculty members in the database" << endl;
            break;
        
        } 

        cout << "Please enter faculty ID" << endl;

        cin >> fID;

        if (masterFaculty->idExists(fID)) {

            cout << masterFaculty->getNode(fID).name << "'s advisees: \n" << endl;
            Faculty faculty = masterFaculty->getNode(fID);

            for (int i = 0; i < faculty.getAdviseeIDs().size(); i++){

                cout << masterStudent->getNode(faculty.getAdviseeIDs().at(i));
            }

            break;

        } else {

            cout << "Faculty member is not in the database." << endl;
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
        cout << "There are no advisors in the database. Add an advisor before adding student." << endl;

    } else {

        cout << "Please enter information about the student: " << endl;

        cout << "Name: " << endl;
        cin >> name;

        cout << "Level: " << endl;
        cin >> name;

        cout << "Major: " << endl;
        cin >> name;

        cout << "GPA: " << endl;
        cin >> name;

        while (masterStudent->idExists(id)){

            id = rand() % 1000;
        }

        while (true){

            cout << "Enter your advisor ID: " << endl;
            cin >> advisorID;

            if (masterFaculty->idExists(advisorID)){

                masterFaculty->getNode(advisorID).addAdvisee(id);
                break;

            } else {
                cout << "This advisor does not exist" << endl;
                continue;
            }



        }

        Student *student = new Student (name, id, level, major, gpa, advisorID);

        masterStudent->insert(*student);

        //rb->studentAction("is", student);
    }



}

void DB::deleteStudent(){ //option 8

    while (true){

        if (masterStudent->isEmpty()){

            cout << "There are no students in the database" << endl;
            break;

        } else {

            int sID;
            cout << "Enter the student ID: " << endl;

            cin >> sID;

            if (masterStudent->idExists(sID)) {
                
                Student student = masterStudent->getNode(sID);
                masterStudent->deleteNode(student);

                int advisorID = student.getAdvisorID();
                Faculty faculty = masterFaculty->getNode(advisorID);
                faculty.removeAdvisee(sID);

                //rb->studentAction("ds", &student);
                break;

            } else {

                cout << "Student does not exist" << endl;
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

    cout << "Please enter information about the faculty: " << endl;

    cout << "Name: " << endl;
    cin >> name;

    cout << "Level: " << endl;
    cin >> level;

    cout << "Department: " << endl;
    cin >> department;

    srand(time(NULL));
    id = rand() % 1000; //Max of 100 IDs

    while(isNewID == false) {
        if(masterFaculty->idExists(id)) {
            id = rand() % 1000;
        } else {
            isNewID = true;
        }
    }

    Faculty *faculty = new Faculty (name, id, level, department);

    masterFaculty->insert(*faculty);

    //rb->facultyAction("if", faculty);

    //cout << "rollback" << endl;


}

void DB::deleteFaculty(){ //option 10

    while (true){

        if (masterFaculty->isEmpty()){

            cout << "There are no faculty members in the database" << endl;
            break;

        } else {

            int fID;
            cout << "Enter the faculty ID: " << endl;

            cin >> fID;

            if (masterFaculty->idExists(fID)) {
                
                Faculty faculty = masterFaculty->getNode(fID);
                masterFaculty->deleteNode(faculty);

                for (int i =0; i < faculty.getAdviseeIDs().size(); ++i){

                    int adviseeID = faculty.getAdviseeIDs().at(i);
                    Student student = masterStudent->getNode(adviseeID);
                    student.setAdvisorID(-1);
                }

                //rb->facultyAction("df", &faculty);
                break;

            } else {

                cout << "Student does not exist" << endl;
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

        cout << "There are no students in the database." << endl;
        return;
    }

    if (masterFaculty->isEmpty()){

        cout << "There are no faculty members in the database." << endl;
        return;
    }

    while (true){

        cout << "Enter student ID: " << endl;
        cin >> studentID;

        if (masterStudent->idExists(studentID)){

            student = masterStudent->getNode(studentID);
            break;

        } else {

            cout << "That faculty member does not exist." << endl;
        }
    }

    while (true){

        cout << "Enter faculty ID: " << endl;
        cin >> facultyID;

        if (masterFaculty->idExists(facultyID)){

            faculty = masterFaculty->getNode(facultyID);
            break;

        } else {

            cout << "That faculty member does not exist." << endl;

        }
    }

    student.setAdvisorID(facultyID);
    faculty.addAdvisee(studentID);

}

void DB::removeAdvisee(){ //option 11

    while (true){

        if (masterStudent->isEmpty()){

            cout << "There are no students in the database." << endl;
            break;
        }
    }

    while (true){

        if (masterFaculty->isEmpty()){

            cout << "There are no faculty members in the database." << endl;
            break;
        }
    }

    int advisorID;
    int fID;
    int sID;
    Student student;
    Faculty faculty;

    while (true){

        cout << "Enter the faculty ID: " << endl;
        cin >> fID;

        if (masterStudent->idExists(fID)){

            break;

        } else {

            cout << "This student does not exist." << endl;

        }
    }

    while (true) {

        cout << "Please enter faculty member ID: " << endl;

        cin >> advisorID;

        if (masterFaculty->idExists(advisorID)){

            break;

        } else {

            cout << "That faculty member does not exist in the database." << endl;
        }
    }

    student = masterStudent->getNode(sID);
    faculty = masterFaculty->getNode(fID);

    faculty.removeAdvisee(fID);
    student.setAdvisorID(advisorID);

}

void DB::Undo(){ //option 13

    if(!rb->undo(masterStudent, masterFaculty)){

        cout << "Cannot Undo." << endl;
    }




}

void DB::Exit(){ //option 14

    
    s->serialize(masterStudent, masterFaculty);
    cout << "Exiting Program." << endl;

}

int DB::printOptions(){

    int userInput;

    cout << "------------------------------------------------------------------------------" << endl;

    cout << endl << "PICK AN OPTION: " << endl;

    cout << "1. Print all students and their information (sorted by ascending id #)" << endl; 
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

    cin >> userInput;

    return userInput;
}

