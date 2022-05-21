
#include "DB.h"

int main(int argc, char** argv){

    DB *database = new DB();
    database->simulate();

    delete database;
    return 0;
}