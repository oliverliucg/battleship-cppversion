#ifndef BATTLESHIP_CPPVERSION_BASICSHIP_H
#define BATTLESHIP_CPPVERSION_BASICSHIP_H

#include "Ship.h"
#include "ShipDisplayInfo.h"

template <typename T> class BasicShip : public Ship<T> {
protected:
  Coordinate upperLeft;
  map<Coordinate, bool> myPieces;
  std::unique_ptr<ShipDisplayInfo<T>> myDisplayInfo;
  std::unique_ptr<ShipDisplayInfo<T>> enemyDisplayInfo;

  void checkCoordinateInThisShip(Coordinate c);

public:
  BasicShip(Coordinate _upperLeft, vector<Coordinate> where,
            std::unique_ptr<ShipDisplayInfo<T>> _myDisplayInfo,
            std::unique_ptr<ShipDisplayInfo<T>> _enemyDisplayInfo)
      : upperLeft(_upperLeft), myDisplayInfo(std::move(_myDisplayInfo)),
        enemyDisplayInfo(std::move(_enemyDisplayInfo)) {
    for (const auto &x : where) {
      myPieces[x] = false;
    }
  }

  virtual bool occupyCoordinates(Coordinate where);
  virtual bool isSunk();
  virtual bool wasHitAt(Coordinate where);
  virtual void recordHitAt(Coordinate where);
  virtual void moveTo(Placement p);
  virtual std::unique_ptr<T> getDisplayInfoAt(Coordinate where, bool myShip);
  virtual vector<Coordinate> getCoordinates();
  virtual Coordinate getUpperLeft();
};

template <typename T>
void BasicShip<T>::checkCoordinateInThisShip(Coordinate where) {
  if (!myPieces.count(where)) {
    throw MyException("The target Coordinate is not in this ship");
  }
}

template <typename T> bool BasicShip<T>::occupyCoordinates(Coordinate where) {
  return myPieces.count(where);
}

template <typename T> bool BasicShip<T>::isSunk() {
  map<Coordinate, bool>::iterator it = myPieces.begin();
  while (it != myPieces.end()) {
    if (!it->second) {
      return false;
    }
  }
  return true;
}

template <typename T> void BasicShip<T>::recordHitAt(Coordinate where) {
  checkCoordinateInThisShip(where);
  myPieces[where] = true;
}

template <typename T> bool BasicShip<T>::wasHitAt(Coordinate where) {
  checkCoordinateInThisShip(where);
  return myPieces[where];
}
template <typename T> void BasicShip<T>::moveTo(Placement p) {}

template <typename T>
unique_ptr<T> BasicShip<T>::getDisplayInfoAt(Coordinate where, bool myShip) {
  checkCoordinateInThisShip(where);
  if (myShip) {
    return myDisplayInfo->getInfo(where, wasHitAt(where));
  } else {
    return enemyDisplayInfo->getInfo(where, wasHitAt(where));
  }
}

template <typename T> vector<Coordinate> BasicShip<T>::getCoordinates() {
  vector<Coordinate> keys;
  map<Coordinate, bool>::iterator it = myPieces.begin();
  while (it != myPieces.end()) {
    keys.emplace_back(it->first);
    ++it;
  }
  return keys;
}

template <typename T> Coordinate BasicShip<T>::getUpperLeft() {
  return upperLeft;
}

#endif // BATTLESHIP_CPPVERSION_BASICSHIP_H
