/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees
*/

#include "Database.h"
#include <exception>

int main(int argc, char** argv) {
    try {
        Database *db = new Database();
        db->run();

        delete db;
    } catch (runtime_error &excpt) { // error handling
        cout << excpt.what() << endl;
    }

    return 0;
}