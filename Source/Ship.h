#ifndef BATTLESHIP_CPPVERSION_SHIP_H
#define BATTLESHIP_CPPVERSION_SHIP_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include "Coordinate.h"
#include "Placement.h"
using std::set;
using std::pair;
using std::make_pair;
using std::map;
using std::vector;

template<typename T>
class Ship{
public:
    virtual bool occupyCoordinates(Coordinate where) = 0;
    virtual bool isSunk() = 0;
    virtual bool wasHitAt(Coordinate where) = 0;
    virtual void recordHitAt(Coordinate where) = 0;
    virtual void moveTo(Placement p) = 0;
    virtual std::shared_ptr<T> getDisplayInfoAt(Coordinate where, bool myShip) = 0;
    virtual vector<Coordinate> getCoordinates() = 0;
    virtual Coordinate getUpperLeft() = 0;
    virtual std::string getName() = 0;
};

#endif //BATTLESHIP_CPPVERSION_SHIP_H