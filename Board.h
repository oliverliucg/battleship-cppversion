#ifndef BATTLESHIP_CPPVERSION_BOARD_H
#define BATTLESHIP_CPPVERSION_BOARD_H

#include "Ship.h"
#include <string>
#include <vector>
using std::shared_ptr;
using std::string;
using std::unique_ptr;
template <typename T> class Board {
public:
  virtual int getWidth() = 0;
  virtual int getHeight() = 0;
  virtual string tryAddShip(std::shared_ptr<Ship<T>> toAdd) = 0;
  virtual std::unique_ptr<T> whatIsAtForSelf(Coordinate where) = 0;
  virtual std::unique_ptr<T> whatIsAtForEnemy(Coordinate where) = 0;
  virtual shared_ptr<Ship<T>> fireAt(Coordinate c) = 0;
  virtual bool ifAllSunk() = 0;
  virtual bool move(Coordinate c, Placement p) = 0;
  virtual int sonarScanning(Coordinate c, T target) = 0;
  virtual Coordinate pickSunkShip() = 0;
  virtual Coordinate randomlyPickShip() = 0;
  virtual Placement pickPlacement(vector<Placement> emptyPlacements) = 0;
  virtual int getNumOfSunkShips() = 0;
  virtual bool isInRange(Coordinate where) = 0;
  virtual vector<Coordinate> getAvailablePoints(bool isToGetAll) = 0;
  virtual vector<Placement> getAvailablePlacements(bool isToGetAll,
                                                   char typeOfShip) = 0;
  virtual string removeShipFromBoardIfExist(Coordinate where) = 0;
  virtual int numOfShips() = 0;
};

#endif // BATTLESHIP_CPPVERSION_BOARD_H