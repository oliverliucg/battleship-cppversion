#include "Coordinate.h"
#include "MyException.h"

class Placement{
private:
    Coordinate where;
    char orientation;

public:
    Placement(Coordinate _where, char _orientation): where(_where), orientation(toupper(_orientation)){}
    Placement(string& rco);
};