#include "Coordinate.h"
#include "MyException.h"

using std::toupper;
Coordinate::Coordinate(string descr){
    if(descr.length() != 2){
        throw MyException("Error: the length of string to build coordinate is not equal to 2\n");
    }
    char firstChar = toupper(descr[0]);
    char secondChar = toupper(descr[1]);
    if(firstChar < 'A' || firstChar > 'Z'){
        throw MyException("Error: The first charactor of string should be a uppercase-letter\n");
    }
    if(secondChar < '0' || secondChar > '9'){
        throw MyException("Error: The second charactor should be a single number\n");
    }
    this->row = firstChar-'A';
    this->column = secondChar-'0';
}

Coordinate::Coordinate(const Coordinate& other){
    this->row = other.row;
    this->column = other.column;
}

Coordinate& Coordinate::operator=(const Coordinate& other){
    if(this != &other){
        this->row = other.row;
        this->column = other.column;
    }
    return (*this);
}

string Coordinate::toString() {
    return "("+ std::to_string(row) + "," + std::to_string(column) + ")";
}

int Coordinate::toHashCode() {
    return std::hash<std::string>{}(toString());
}
bool operator==(const Coordinate &lhs, const Coordinate &rhs){
    return lhs.row==rhs.row && lhs.column == rhs.column;
}

bool operator<(const Coordinate &lhs, const Coordinate &rhs){
    return lhs.row < rhs.row || (lhs.row == rhs.row && lhs.column < rhs.column);
}