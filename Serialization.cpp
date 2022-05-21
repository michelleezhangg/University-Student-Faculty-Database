#include "Serialization.h"

Serialization::Serialization(){}

Serialization::~Serialization(){}

void Serialization::writeToStudentFile(TreeNode<Student> *student, BST<Student> *studentDB){

    ofstream WriteFile("studentTable.txt");

    WriteFile.open("studentTable.txt", ios_base::app);

    if(studentDB != NULL) {
        
        WriteFile << endl;

        WriteFile << student->key.getID() << endl;
        WriteFile << student->key.getName() << endl;
        WriteFile << student->key.getLevel() << endl;
        WriteFile << student->key.getMajor() << endl;
        WriteFile << student->key.getGPA() << endl;
        WriteFile << student->key.getAdvisorID() << endl;
        
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

void Serialization::writeToFacultyFile(TreeNode<Faculty> *faculty, BST<Faculty> *facultyDB){

    ofstream WriteFile("facultyTable.txt");

    WriteFile.open("facultyTable.txt", ios_base::app);

    if(facultyDB != NULL) {
        
        WriteFile << endl;

        WriteFile << faculty->key.getName() << endl;
        WriteFile << faculty->key.getID() << endl;
        WriteFile << faculty->key.getLevel() << endl;
        WriteFile << faculty->key.getDepartment() << endl;
        WriteFile << faculty->key.getAdviseeIDs().size() << endl;
        
        for (int i = 0; i < faculty->key.getAdviseeIDs().size(); ++i) {
            WriteFile << faculty->key.getAdviseeIDs().at(i) << endl;
        }
        
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

void Serialization::readToStudentDB(BST<Student> *studentDB){

    ifstream studentFile;

    string line = "";
    string divider = "";
    string name = "";
    string level = "";
    string major = "";
    
    string adID = ""; //need to turn into int
    string stuID = "";;
    string GPA = "";

    double gpa = 0;
    int advisorID = 0;
    int studentID = 0;

    studentFile.open("studentTable.txt");

    if(studentFile.is_open()) {

        cout << "Reading File." << endl;

        getline(studentFile,line);

        if (line.empty()) {

            cout << "File is empty." << endl;
            return;
        }

        int numStudents = stoi(line); //FIXME (get size of tree in previous function)

        while(getline(studentFile,divider)) {

            for (int i = 0; i < numStudents; ++i){

                getline(studentFile, name);

                getline(studentFile, stuID);
                studentID = stoi(stuID);

                getline(studentFile, level);

                getline(studentFile, major);

                getline(studentFile, GPA);
                gpa = stod(GPA);

                getline(studentFile, adID);
                advisorID = stoi(adID);

                getline(studentFile, divider);

                Student student = Student(name, studentID, level, major, gpa, advisorID);
                studentDB->insert(student);  
            }
        }

    } else {
        studentFile.close();
    }
    studentFile.close();


}

void Serialization::readToFacultyDB(BST<Faculty> *facultyDB){

    ifstream facultyFile;

    string line = "";
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

    facultyFile.open("facultyTable.txt");

    if(facultyFile.is_open()) {

        cout << "Reading Faculty File." << endl;

        getline(facultyFile,line);

        if (line.empty()) {
            return;
        }
        int numFaculty = stoi(line);

        while(getline(facultyFile,divider)) {
            //The first line should be the number of students

            for (int i = 0; i < numFaculty; ++i) {

                getline(facultyFile, name);

                getline(facultyFile, fID);
                facultyID = stoi(fID);

                getline(facultyFile, level);

                getline(facultyFile, department);

                getline(facultyFile, nA);
                numAdvisees = stoi(nA);

                Faculty faculty = Faculty(name, facultyID, level, department);

                for (int i = 0; i < numAdvisees; ++i) {
                    getline(facultyFile, sID);
                    adviseeID = stoi(sID);
                    cout << "HERE" << endl;
                    faculty.addAdvisee(adviseeID);
                }

                getline(facultyFile, divider);
    
                facultyDB->insert(faculty);  
                
            }

        }
    }
    facultyFile.close();

}

void Serialization::serialize(BST<Student> *studentDB, BST<Faculty> *facultyDB){

    ofstream studentFile;
    studentFile.open("studentTable.txt");

    if (studentFile.is_open()) {
        studentFile << studentDB->getSize() << endl;
        TreeNode<Student> *student = studentDB->getRoot();
        writeToStudentFile(student, studentDB);
    }
    studentFile.close();

    ofstream facultyFile;  
    facultyFile.open("facultyTable.txt");

    if (facultyFile.is_open()) {
        facultyFile << facultyDB->getSize() << endl;
        TreeNode<Faculty> *faculty = facultyDB->getRoot();
        writeToFacultyFile(faculty, facultyDB);
    }
    facultyFile.close();



}