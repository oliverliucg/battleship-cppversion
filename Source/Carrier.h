#ifndef BATTLESHIP_CPPVERSION_CARRIER_H
#define BATTLESHIP_CPPVERSION_CARRIER_H

#include "BasicShip.h"
#include "SimpleShipDisplayInfo.h"

template <typename T> class Carrier : public BasicShip<T> {
protected:
  static vector<Coordinate> makeCoords(Coordinate upperLeft, char orientation);

public:
  Carrier(string _name, Coordinate _upperLeft, char _orientation,
          std::unique_ptr<SimpleShipDisplayInfo<T>> myDisplayInfo,
          std::unique_ptr<SimpleShipDisplayInfo<T>> enemyDisplayInfo);
  Carrier(string _name, Coordinate _upperLeft, char _orientation, std::shared_ptr<T> data, std::shared_ptr<T> onHit);
};


template <typename T>
vector<Coordinate> Carrier<T>::makeCoords(Coordinate upperLeft,
                                          char orientation) {
  vector<Coordinate> res;
  int startRow = upperLeft.getRow();
  int startColumn = upperLeft.getColumn();
  switch (orientation) {
  case 'U':
    res.emplace_back(Coordinate(startRow, startColumn));
    res.emplace_back(Coordinate(startRow + 1, startColumn));
    res.emplace_back(Coordinate(startRow + 2, startColumn));
    res.emplace_back(Coordinate(startRow + 2, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 3, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 4, startColumn + 1));
    break;
  case 'R':
    res.emplace_back(Coordinate(startRow, startColumn + 2));
    res.emplace_back(Coordinate(startRow, startColumn + 3));
    res.emplace_back(Coordinate(startRow, startColumn + 4));
    res.emplace_back(Coordinate(startRow + 1, startColumn));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 2));
    break;
  case 'D':
    res.emplace_back(Coordinate(startRow, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 2, startColumn));
    res.emplace_back(Coordinate(startRow + 2, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 3, startColumn));
    res.emplace_back(Coordinate(startRow + 4, startColumn));
    break;
  case 'L':
    res.emplace_back(Coordinate(startRow, startColumn));
    res.emplace_back(Coordinate(startRow, startColumn + 1));
    res.emplace_back(Coordinate(startRow, startColumn + 2));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 2));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 3));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 4));
    break;
  }
  return res;
}

template <typename T>
Carrier<T>::Carrier(string _name, Coordinate _upperLeft, char _orientation,
                    std::unique_ptr<SimpleShipDisplayInfo<T>> myDisplayInfo,
                    std::unique_ptr<SimpleShipDisplayInfo<T>> enemyDisplayInfo)
    : BasicShip<T>(_name, _upperLeft, makeCoords(_upperLeft, _orientation),
                   std::move(myDisplayInfo), std::move(enemyDisplayInfo)) {}

template <typename T>
Carrier<T>::Carrier(string _name, Coordinate _upperLeft, char _orientation, std::shared_ptr<T> data, std::shared_ptr<T> onHit)
    : Carrier(_name, _upperLeft, _orientation,
              std::make_unique<SimpleShipDisplayInfo<T>>(data, onHit),
              std::make_unique<SimpleShipDisplayInfo<T>>(nullptr, data)) {}

#endif // BATTLESHIP_CPPVERSION_CARRIER_H