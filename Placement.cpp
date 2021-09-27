#include "Placement.h"

Placement::Placement(string& rco){
    if(rco.length() != 3){
        throw new MyException("Error: The placement is invalid: the length of input string should be three.\n");
    }
    string rc = rco.substr(0, 2);
    this->where = Coordinate(rc);
    this->orientation = rco[2];
}