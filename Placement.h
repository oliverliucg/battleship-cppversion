#ifndef BATTLESHIP_CPPVERSION_PLACEMENT_H
#define BATTLESHIP_CPPVERSION_PLACEMENT_H

#include "Coordinate.h"
#include "MyException.h"

class Placement{
private:
    Coordinate where;
    char orientation;

public:
    Placement(Coordinate _where, char _orientation): where(_where), orientation(toupper(_orientation)){}
    Placement(string& rco);
    Placement();
    Coordinate getWhere();
    char getOrientation();
    string toString();
    int toHashCode();
    friend bool operator==(const Placement &lhs, const Placement &rhs);
};

#endif //BATTLESHIP_CPPVERSION_PLACEMENT_H