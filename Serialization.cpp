/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Serialization Class.
*/

#include "Serialization.h"

Serialization::Serialization() {} // default constructor

Serialization::~Serialization() {} // destructor

/* reading files */
/***/
void Serialization::readStudentFile(BST<Student> *studentDB) {
    ifstream ReadFile("studentTable.txt");

    // if file exists / can be opened
    if (ReadFile.is_open()) {
        ReadFile.open("studentTable.txt");
        populateStudentDB(studentDB);
    }

    // if file does not exist, do nothing
    ReadFile.close();
}

/***/
void Serialization::readFacultyFile(BST<Faculty> *facultyDB) {
    ifstream ReadFile("facultyTable.txt");

    // if file exists
    if (ReadFile.is_open()) {
        ReadFile.open("facultyTable.txt");
        populateFacultyDB(facultyDB);
    }

    // if file does not exist, do nothing
    ReadFile.close();
}

/***/
void Serialization::populateStudentDB(BST<Student> *studentDB) {
    ifstream ReadFile("studentTable.txt");

    string str_id = "";
    string name = "";
    string level = "";
    string major = "";
    string str_gpa = "";
    string str_advisorID = "";

    int id = 0;
    double gpa = 0.0;
    int advisorID = 0;

    string line = "";

    // gets number of students in database
    getline(ReadFile, line);
    int numStudent = stoi(line);

    // populates masterStudent
    while (getline(ReadFile, line)) {
        for (int i = 0; i < numStudent; ++i) {
            getline(ReadFile, str_id);
            getline(ReadFile, name);
            getline(ReadFile, level);
            getline(ReadFile, major);
            getline(ReadFile, str_gpa);
            getline(ReadFile, str_advisorID);

            id = stoi(str_id);
            gpa = stod(str_gpa);
            advisorID = stoi(str_advisorID);

            Student s = Student(id, name, level, major, gpa, advisorID);
            studentDB->insert(s);

            getline(ReadFile, line); // read newline between students
        }
    }

    ReadFile.close();
}

/***/
void Serialization::populateFacultyDB(BST<Faculty> *facultyDB) {
    ifstream ReadFile("facultyTable.txt");

    string str_id = "";
    string name = "";
    string level = "";
    string department = "";
    string numAdvisees = "";
    string str_adviseeID = "";
    
    int id = 0;
    int adviseeID = 0;
    string line = "";

    // gets number of faculty in database
    getline(ReadFile, line);
    int numFaculty = stoi(line);

    // populates masterFaculty
    while (getline(ReadFile, line)) { // 
        for (int i = 0; i < numFaculty; ++i) {
            getline(ReadFile, str_id);
            getline(ReadFile, name);
            getline(ReadFile, level);
            getline(ReadFile, department);
            
            id = stoi(str_id);

            Faculty f = Faculty(id, name, level, department);

            getline(ReadFile, numAdvisees);
            for (int i = 0; i < stoi(numAdvisees); ++i) {
                getline(ReadFile, str_adviseeID);
                adviseeID = stoi(str_adviseeID);
                f.addAdvisee(adviseeID);
            }

            facultyDB->insert(f);

            getline(ReadFile, line); // read newline between faculties
        }
    }
    ReadFile.close();
}

/* writing files */
/***/
void Serialization::writeStudentFile(TreeNode<Student> *node, BST<Student> *studentDB) {
    ofstream WriteFile("studentTable.txt", ios_base::app); //https://en.cppreference.com/w/cpp/io/ios_base/openmode

    if (studentDB != NULL) {
        WriteFile << endl;
        WriteFile << node->key.id << endl;
        WriteFile << node->key.name << endl;
        WriteFile << node->key.level << endl;
        WriteFile << node->key.getMajor() << endl;
        WriteFile << node->key.getGPA() << endl;
        WriteFile << node->key.getAdvisorID() << endl;

        // recursion
        if (node->left != NULL)
            writeStudentFile(node->left, studentDB);
        if (node->right != NULL)
            writeStudentFile(node->right, studentDB);
    }

    WriteFile.close();
}

/***/
void Serialization::writeFacultyFile(TreeNode<Faculty> *node, BST<Faculty> *facultyDB) {
    ofstream WriteFile("facultyTable.txt", ios_base::app); //https://en.cppreference.com/w/cpp/io/ios_base/openmode

    if (facultyDB != NULL) {
        WriteFile << endl;
        WriteFile << node->key.id << endl;
        WriteFile << node->key.name << endl;
        WriteFile << node->key.level << endl;
        WriteFile << node->key.getDepartment() << endl;

        WriteFile << node->key.getAdviseesIDs().size() << endl;
        for (int i = 0; i < node->key.getAdviseesIDs().size(); ++i) {
            WriteFile << node->key.getAdviseesIDs().at(i) << endl;
        }

        // recursion
        if (node->left != NULL)
            writeFacultyFile(node->left, facultyDB);
        if (node->right != NULL)
            writeFacultyFile(node->right, facultyDB);
    }

    WriteFile.close();
}

/* serialize */
/***/
void Serialization::serialize(BST<Student> *studentDB, BST<Faculty> *facultyDB) {
    ifstream ReadStudentFile("studentTable.txt");
    ifstream ReadFacultyFile("facultyTable.txt");
    ofstream WriteStudentFile("studentTable.txt");
    ofstream WriteFacultyFile("facultyTable.txt");

    if (ReadStudentFile.is_open()) {
        WriteStudentFile << studentDB->getSize() << endl;
        writeStudentFile(studentDB->getRoot(), studentDB);
    }

    if (ReadFacultyFile.is_open()) {
        WriteFacultyFile << facultyDB->getSize() << endl;
        writeFacultyFile(facultyDB->getRoot(), facultyDB);
    }
}