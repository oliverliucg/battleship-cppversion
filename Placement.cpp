#include "Placement.h"

Placement::Placement(string& rco){
    if(rco.length() != 3){
        throw MyException("Error: The placement is invalid: the length of input string should be three.\n");
    }
    string rc = rco.substr(0, 2);
    this->where = Coordinate(rc);
    this->orientation = toupper(rco[2]);
}

Placement::Placement() {}
char Placement::getOrientation() {
    return orientation;
}

Coordinate Placement::getWhere() {
    return where;
}

string Placement::toString() {
    return where.toString()+orientation;
}

int Placement::toHashCode() {
    return std::hash<std::string>{}(toString());
}
bool operator==(const Placement &lhs, const Placement &rhs){
    return lhs.orientation == rhs.orientation && lhs.where == rhs.where;
}