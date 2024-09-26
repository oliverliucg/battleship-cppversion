#ifndef BATTLESHIP_CPPVERSION_BASICSHIP_H
#define BATTLESHIP_CPPVERSION_BASICSHIP_H

#include "Ship.h"
#include "ShipDisplayInfo.h"

template<typename T>
class BasicShip : public Ship<T> {
protected:
    string name;
    Coordinate upperLeft;
    map<Coordinate, bool> myPieces;
    std::shared_ptr<ShipDisplayInfo<T>> myDisplayInfo;
    std::shared_ptr<ShipDisplayInfo<T>> enemyDisplayInfo;

    void checkCoordinateInThisShip(Coordinate c);

public:
    BasicShip(string _name, Coordinate _upperLeft, vector<Coordinate> where,
              std::shared_ptr<ShipDisplayInfo<T>> _myDisplayInfo,
              std::shared_ptr<ShipDisplayInfo<T>> _enemyDisplayInfo)
            : name(_name), upperLeft(_upperLeft), myDisplayInfo(_myDisplayInfo),
              enemyDisplayInfo(_enemyDisplayInfo) {
        for (const auto &x: where) {
            myPieces[x] = false;
        }
    }

    virtual bool occupyCoordinates(Coordinate where);

    virtual bool isSunk();

    virtual bool wasHitAt(Coordinate where);

    virtual void recordHitAt(Coordinate where);

    virtual void moveTo(Placement p);

    virtual std::shared_ptr<T> getDisplayInfoAt(Coordinate where, bool myShip);

    virtual vector<Coordinate> getCoordinates();

    virtual Coordinate getUpperLeft();

    virtual string getName();
};

template<typename T>
void BasicShip<T>::checkCoordinateInThisShip(Coordinate where) {
    if (!myPieces.count(where)) {
        throw MyException("The target Coordinate is not in this ship");
    }
}

template<typename T>
bool BasicShip<T>::occupyCoordinates(Coordinate where) {
    return myPieces.count(where);
}

template<typename T>
bool BasicShip<T>::isSunk() {
    map<Coordinate, bool>::iterator it = myPieces.begin();
    while (it != myPieces.end()) {
        if (!it->second) {
            return false;
        }
        ++it;
    }
    return true;
}

template<typename T>
void BasicShip<T>::recordHitAt(Coordinate where) {
    checkCoordinateInThisShip(where);
    myPieces[where] = true;
}

template<typename T>
bool BasicShip<T>::wasHitAt(Coordinate where) {
    checkCoordinateInThisShip(where);
    return myPieces[where];
}

template<typename T>
void BasicShip<T>::moveTo(Placement p) {}

template<typename T>
std::shared_ptr<T> BasicShip<T>::getDisplayInfoAt(Coordinate where, bool myShip) {
    checkCoordinateInThisShip(where);
    if (myShip) {
        return myDisplayInfo->getInfo(where, wasHitAt(where));
    } else {
        return enemyDisplayInfo->getInfo(where, wasHitAt(where));
    }
}

template<typename T>
vector<Coordinate> BasicShip<T>::getCoordinates() {
    vector<Coordinate> keys;
    map<Coordinate, bool>::iterator it = myPieces.begin();
    while (it != myPieces.end()) {
        keys.emplace_back(it->first);
        ++it;
    }
    return keys;
}

template<typename T>
Coordinate BasicShip<T>::getUpperLeft() {
    return upperLeft;
}

template<typename T>
string BasicShip<T>::getName() {
    return name;
}

#endif // BATTLESHIP_CPPVERSION_BASICSHIP_H
