#include "Database.h"

Database::Database() { // default constructor
    studentDB = new BST<Student>();
    facultyDB = new BST<Faculty>();
}

Database::~Database() { //destructor
    delete studentDB;
    delete facultyDB;
}

