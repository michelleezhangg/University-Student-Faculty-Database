/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This file contains the main method for Assignment 6.
*/

#include "Database.h"
#include "Serialization.h"

int main(int argc, char** argv) {
    Database *database = new Database();

    database->readFiles();
    database->simulate();

    delete database;
    return 0;
}