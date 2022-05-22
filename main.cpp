
#include "DB.h"
#include "Serialization.h"

int main(int argc, char** argv){

    DB *database = new DB();

    database->simulate();

    delete database;
    return 0;
}