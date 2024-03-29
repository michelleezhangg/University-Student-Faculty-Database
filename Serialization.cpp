/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Serialization Class.
*/

#include "Serialization.h"

Serialization::Serialization(){} // default constructor

Serialization::~Serialization(){} // destructor

/**
 * writes the student BST database to a file, studentTable.txt.
 * @param student the first student used to traverse through the student BST.
 * @param studentDB the database to traverse through to write to studentTable.txt file.
 * recursive
 */
void Serialization::writeToStudentFile(TreeNode<Student> *student, BST<Student> *studentDB){

    ofstream WriteFile;

    WriteFile.open("studentTable.txt", ios_base::app);

    //WriteFile << endl << "STUDENT DATABASE" << endl;

    if(studentDB != NULL) {
        
        WriteFile << endl << "-----------------" << endl;

        WriteFile << student->key.getName() << endl;
        WriteFile << student->key.getID() << endl;
        WriteFile << student->key.getLevel() << endl;
        WriteFile << student->key.getMajor() << endl;
        WriteFile << student->key.getGPA() << endl;
        WriteFile << student->key.getAdvisorID() << endl;

        /*
        WriteFile << "NAME: " << student->key.getName() << endl;
        WriteFile << "ID: " << student->key.getID() << endl;
        WriteFile << "LEVEL: " << student->key.getLevel() << endl;
        WriteFile << "MAJOR: " << student->key.getMajor() << endl;
        WriteFile << "GPA: " << student->key.getGPA() << endl;
        WriteFile << "ADVISOR ID: " << student->key.getAdvisorID() << endl;
        */

        //WriteFile << "-----------------" << endl;
        
        //Same idea as recursive print
        if (student->left != NULL) {
            writeToStudentFile(student->left, studentDB);
        }
        if (student->right != NULL) {
            writeToStudentFile(student->right , studentDB);
        }

    }else {
        cout << "Student Database is Empty" << endl;
    }

    WriteFile.close();
}

/**
 * * writes the faculty BST database to a file, facultyTable.txt.
 * @param faculty the first faculty used to traverse through the faculty BST.
 * @param facultyDB the database to traverse through to write to facultyTable.txt file.
 * recursive
 */
void Serialization::writeToFacultyFile(TreeNode<Faculty> *faculty, BST<Faculty> *facultyDB){

    ofstream WriteFile;

    WriteFile.open("facultyTable.txt", ios_base::app);

    //WriteFile << endl << "FACULTY DATABASE" << endl;

    if(facultyDB != NULL) {

        WriteFile << endl << "-----------------" << endl;

        WriteFile << faculty->key.getName() << endl;
        WriteFile << faculty->key.getID() << endl;
        WriteFile << faculty->key.getLevel() << endl;
        WriteFile << faculty->key.getDepartment() << endl;
        WriteFile << faculty->key.getAdviseeIDs().size() << endl;

        /*
        WriteFile << "NAME: " << faculty->key.getName() << endl;
        WriteFile << "ID: " << faculty->key.getID() << endl;
        WriteFile << "LEVEL: " << faculty->key.getLevel() << endl;
        WriteFile << "DEPARTMENT: " << faculty->key.getDepartment() << endl;
        WriteFile << "ADVISEE IDs: " << faculty->key.getAdviseeIDs().size() << endl;
        */
        
        for (int i = 0; i < faculty->key.getAdviseeIDs().size(); ++i) {
            WriteFile << faculty->key.getAdviseeIDs().at(i) << endl;
        }

        //WriteFile << "-----------------" << endl;
        
        //Same idea as recurssive print
        if (faculty->left != NULL) {
            writeToFacultyFile(faculty->left, facultyDB);
        }
        if (faculty->right != NULL) {
            writeToFacultyFile(faculty->right, facultyDB);
        }

    }else {
        cout << "Faculty Database is Empty" << endl;
    }

    WriteFile.close();

}

/**
 * reads the file studentTable.txt and populates the database with the contents of that file if it exists.
 * @param masterStudent the database to populate if studentTable.txt exists.
 */
void Serialization::readToStudentDB(BST<Student> *masterStudent){

    ifstream studentFile;

    string line = "";
    string title = "";
    string divider = "";
    string name = "";
    string level = "";
    string major = "";
    
    string adID = ""; //need to turn into int
    string stuID = "";
    string GPA = "";

    double gpa = 0.0;
    int advisorID = 0;
    int studentID = 0;

    stringstream id;
    stringstream aID;

    studentFile.open("studentTable.txt");

    if(studentFile.is_open()) {


        getline(studentFile,line);

        if (line.empty()) {

            cout << "File is empty." << endl;
            return;
        }

        int numStudents = stoi(line);

        getline(studentFile,title);

        while(getline(studentFile,divider)) {

            for (int i = 0; i < numStudents; ++i){

                getline(studentFile, name);

                getline(studentFile, stuID);
                id << stuID;
                id >> studentID;
                //studentID = stoi(stuID);

                getline(studentFile, level);

                getline(studentFile, major);

                getline(studentFile, GPA);
                gpa = stod(GPA);

                getline(studentFile, adID);
                aID << stuID;
                aID >> studentID;
                //advisorID = stoi(adID);

                getline(studentFile, divider);

                Student student = Student(name, studentID, level, major, gpa, advisorID);
                masterStudent->insert(student);  
            }
        }

    } else {
        studentFile.close();
    }
    studentFile.close();


}

/**
 * read the file facultyTable.txt and populates the database with the contents of that file if it exists.
 * @param masterFaculty the database to populate if the file facultyTable.txt exists.
 */
void Serialization::readToFacultyDB(BST<Faculty> *masterFaculty){

    ifstream facultyFile;

    string line = "";
    string title = "";
    string divider = "";
    string name = "";
    string level = "";
    string department = "";
    
    string fID = ""; //need to turn into int
    string sID = "";
    string nA = "";

    int numAdvisees = 0;
    int adviseeID = 0;
    int facultyID = 0;

    stringstream facadviseeID;
    stringstream facID;
    stringstream facAdvisees;

    facultyFile.open("facultyTable.txt");

    if(facultyFile.is_open()) {

        getline(facultyFile,line);

        if (line.empty()) {
            return;
        }
        int numFaculty = stoi(line);

        getline(facultyFile,title);

        while(getline(facultyFile,divider)) {
            //The first line should be the number of students

            for (int i = 0; i < numFaculty; ++i) {

                getline(facultyFile, name);

                getline(facultyFile, fID);
                facID << fID;
                facID >> facultyID;
                //facultyID = stoi(fID);

                getline(facultyFile, level);

                getline(facultyFile, department);

                getline(facultyFile, nA);
                facAdvisees << nA;
                facAdvisees >> numAdvisees;
                //numAdvisees = stoi(nA);

                Faculty faculty = Faculty(name, facultyID, level, department);

                for (int i = 0; i < numAdvisees; ++i) {
                    getline(facultyFile, sID);
                    facadviseeID << sID;
                    facadviseeID >> adviseeID;
                    //adviseeID = stoi(sID);
                    cout << "HERE" << endl;
                    faculty.addAdvisee(adviseeID);
                }

                getline(facultyFile, divider);
                getline(facultyFile, divider);
    
                masterFaculty->insert(faculty);  
                
            }

        }
    }
    facultyFile.close();

}

/**
 * performs the serialization for the program.
 * @param studentDB the student database.
 * @param facultyDB the faculty database.
 */
void Serialization::serialize(BST<Student> *studentDB, BST<Faculty> *facultyDB){

    ofstream studentFile;
    studentFile.open("studentTable.txt");

    if (studentFile.is_open()) {
        studentFile << studentDB->getSize() << endl;
        //studentFile << "Number of Students: " << studentDB->getSize() << endl;
        TreeNode<Student> *student = studentDB->getRoot();
        writeToStudentFile(student, studentDB);
    }
    studentFile.close();

    ofstream facultyFile;  
    facultyFile.open("facultyTable.txt");
    if (facultyFile.is_open()) {
        facultyFile << facultyDB->getSize() << endl;
        //facultyFile << "Number of Faculty Members: " << facultyDB->getSize() << endl;
        TreeNode<Faculty> *faculty = facultyDB->getRoot();
        writeToFacultyFile(faculty, facultyDB);
    }
    facultyFile.close();



}
