/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Serialization Class.
*/

#include "Serialization.h"

Serialization::Serialization() {} // default constructor

Serialization::~Serialization() {} // destructor

/* reading files */
/**
 * reads the file studentTable.txt and populates the database with the contents of that file if it exists.
 * @param studentDB the database to populate if studentTable.txt exists.
 */
void Serialization::readStudentFile(BST<Student> *studentDB) {
    ifstream studentFile;

    string line = "";
    string title = "";
    string divider = "";
    string name = "";
    string level = "";
    string major = "";
    
    string adID = ""; // need to turn into int
    string stuID = "";
    string GPA = "";

    double gpa = 0.0;
    int advisorID = 0;
    int studentID = 0;

    stringstream id;
    stringstream aID;

    studentFile.open("studentTable.txt");

    // if file exists / can be opened
    if(studentFile.is_open()) {
        // first line of file: number of students in database
        getline(studentFile,line);

        if (!line.empty()) {
            int numStudents = stoi(line);

            getline(studentFile, title);

            while(getline(studentFile, divider)) {

                for (int i = 0; i < numStudents; ++i){
                    getline(studentFile, name);

                    getline(studentFile, stuID);
                    id << stuID;
                    id >> studentID;

                    getline(studentFile, level);
                    getline(studentFile, major);

                    getline(studentFile, GPA);
                    gpa = stod(GPA);

                    getline(studentFile, adID);
                    aID << stuID;
                    aID >> studentID;

                    getline(studentFile, divider);

                    Student student = Student(studentID, name, level, major, gpa, advisorID);
                    studentDB->insert(student);  
                }
            }
        }
    }

    studentFile.close();
}

/**
 * read the file facultyTable.txt and populates the database with the contents of that file if it exists.
 * @param facultyDB the database to populate if the file facultyTable.txt exists.
 */
void Serialization::readFacultyFile(BST<Faculty> *facultyDB) {
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

    // if file exists / can be opened
    if(facultyFile.is_open()) {
        // first line of file: number of faculty in database
        getline(facultyFile,line);

        if (!line.empty()) {
            int numFaculty = stoi(line);

            getline(facultyFile, title);

            while(getline(facultyFile, divider)) {

                for (int i = 0; i < numFaculty; ++i) {
                    getline(facultyFile, name);

                    getline(facultyFile, fID);
                    facID << fID;
                    facID >> facultyID;

                    getline(facultyFile, level);
                    getline(facultyFile, department);

                    getline(facultyFile, nA);
                    facAdvisees << nA;
                    facAdvisees >> numAdvisees;

                    Faculty faculty = Faculty(facultyID, name, level, department);

                    for (int i = 0; i < numAdvisees; ++i) {
                        getline(facultyFile, sID);
                        facadviseeID << sID;
                        facadviseeID >> adviseeID;
                        faculty.addAdvisee(adviseeID);
                    }

                    getline(facultyFile, divider);
                    getline(facultyFile, divider);
        
                    facultyDB->insert(faculty);  
                }
            }
        }
    }

    facultyFile.close();
}

/* writing files */
/**
 * writes the student BST database to a file, studentTable.txt.
 * @param student the first student used to traverse through the student BST.
 * @param studentDB the database to traverse through to write to studentTable.txt file.
 * recursive
 */
void Serialization::writeStudentFile(TreeNode<Student> *student, BST<Student> *studentDB) {
    ofstream WriteFile;

    WriteFile.open("studentTable.txt", ios_base::app);

    if(studentDB != NULL) {
        WriteFile << endl << "-----------------" << endl;
        WriteFile << student->key.name << endl;
        WriteFile << student->key.id << endl;
        WriteFile << student->key.level << endl;
        WriteFile << student->key.getMajor() << endl;
        WriteFile << student->key.getGPA() << endl;
        WriteFile << student->key.getAdvisorID() << endl;
        
        // recursion
        if (student->left != NULL)
            writeStudentFile(student->left, studentDB);
        else if (student->right != NULL)
            writeStudentFile(student->right , studentDB);
    }
    
    else
        cout << "The student database is empty" << endl;
    

    WriteFile.close();
}

/**
 * * writes the faculty BST database to a file, facultyTable.txt.
 * @param faculty the first faculty used to traverse through the faculty BST.
 * @param studentDB the database to traverse through to write to facultyTable.txt file.
 * recursive
 */
void Serialization::writeFacultyFile(TreeNode<Faculty> *faculty, BST<Faculty> *facultyDB) {
    ofstream WriteFile;
    WriteFile.open("facultyTable.txt", ios_base::app);

    if (facultyDB != NULL) {
        WriteFile << endl << "-----------------" << endl;
        WriteFile << faculty->key.name << endl;
        WriteFile << faculty->key.id << endl;
        WriteFile << faculty->key.level << endl;
        WriteFile << faculty->key.getDepartment() << endl;
        WriteFile << faculty->key.getAdviseeIDs().size() << endl;
        
        for (int i = 0; i < faculty->key.getAdviseeIDs().size(); ++i)
            WriteFile << faculty->key.getAdviseeIDs().at(i) << endl;


        if (faculty->left != NULL)
            writeFacultyFile(faculty->left, facultyDB);
        if (faculty->right != NULL)
            writeFacultyFile(faculty->right, facultyDB);

    }
    
    else
        cout << "The faculty database is empty" << endl;

    WriteFile.close();
}

/* serialize (core function) */
/**
 * performs the serialization for the program.
 * @param studentDB the student database.
 * @param facultyDB the faculty database.
 */
void Serialization::serialize(BST<Student> *studentDB, BST<Faculty> *facultyDB) {
    ofstream studentFile;
    studentFile.open("studentTable.txt");

    if (studentFile.is_open()) {
        studentFile << studentDB->getSize() << endl;
        TreeNode<Student> *student = studentDB->getRoot();
        writeStudentFile(student, studentDB);
    }
    studentFile.close();

    ofstream facultyFile;  
    facultyFile.open("facultyTable.txt");
    if (facultyFile.is_open()) {
        facultyFile << facultyDB->getSize() << endl;
        TreeNode<Faculty> *faculty = facultyDB->getRoot();
        writeFacultyFile(faculty, facultyDB);
    }
    facultyFile.close();
}