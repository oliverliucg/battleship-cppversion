#ifndef BATTLESHIP_CPPVERSION_SHIPDISPLAYINFO_H
#define BATTLESHIP_CPPVERSION_SHIPDISPLAYINFO_H

#include "Coordinate.h"
using std::unique_ptr;

template <typename T> 
class ShipDisplayInfo {
public:
  virtual std::unique_ptr<T> getInfo(Coordinate where, bool hit) = 0;
};

#endif //BATTLESHIP_CPPVERSION_SHIPDISPLAYINFO_H