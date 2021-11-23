#ifndef BATTLESHIP_CPPVERSION_BATTLESHIP_H
#define BATTLESHIP_CPPVERSION_BATTLESHIP_H

#include "BasicShip.h"
#include "SimpleShipDisplayInfo.h"

template <typename T> class BattleShip : public BasicShip<T> {
protected:
  static vector<Coordinate> makeCoords(Coordinate upperLeft, char orientation);

public:
  BattleShip(string _name, Coordinate _upperLeft, char _orientation,
             std::unique_ptr<SimpleShipDisplayInfo<T>> myDisplayInfo,
             std::unique_ptr<SimpleShipDisplayInfo<T>> enemyDisplayInfo);
  BattleShip(string _name, Coordinate _upperLeft, char _orientation, std::shared_ptr<T> data, std::shared_ptr<T> onHit);
};


template <typename T>
vector<Coordinate> BattleShip<T>::makeCoords(Coordinate upperLeft,
                                             char orientation) {
  vector<Coordinate> res;
  int startRow = upperLeft.getRow();
  int startColumn = upperLeft.getColumn();
  switch (orientation) {
  case 'U':
    res.emplace_back(Coordinate(startRow, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 1, startColumn));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 2));
    break;
  case 'R':
    res.emplace_back(Coordinate(startRow, startColumn));
    res.emplace_back(Coordinate(startRow + 1, startColumn));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 2, startColumn));
    break;
  case 'D':
    res.emplace_back(Coordinate(startRow, startColumn));
    res.emplace_back(Coordinate(startRow, startColumn + 1));
    res.emplace_back(Coordinate(startRow, startColumn + 2));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 1));
    break;
  case 'L':
    res.emplace_back(Coordinate(startRow, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 1, startColumn));
    res.emplace_back(Coordinate(startRow + 1, startColumn + 1));
    res.emplace_back(Coordinate(startRow + 2, startColumn + 1));
    break;
  }
  return res;
}

template <typename T>
BattleShip<T>::BattleShip(
    string _name, Coordinate _upperLeft, char _orientation,
    std::unique_ptr<SimpleShipDisplayInfo<T>> myDisplayInfo,
    std::unique_ptr<SimpleShipDisplayInfo<T>> enemyDisplayInfo)
    : BasicShip<T>(_name, _upperLeft, makeCoords(_upperLeft, _orientation),
                   std::move(myDisplayInfo), std::move(enemyDisplayInfo)) {}

template <typename T>
BattleShip<T>::BattleShip(string _name, Coordinate _upperLeft, char _orientation, std::shared_ptr<T> data,
                          std::shared_ptr<T> onHit)
    : BattleShip<T>(_name, _upperLeft, _orientation,
                    std::make_unique<SimpleShipDisplayInfo<T>>(data, onHit),
                    std::make_unique<SimpleShipDisplayInfo<T>>(nullptr, data)) {}

#endif // BATTLESHIP_CPPVERSION_BATTLESHIP_H