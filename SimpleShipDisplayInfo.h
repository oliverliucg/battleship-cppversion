#ifndef BATTLESHIP_CPPVERSION_SIMPLESHIPDISPLAYINFO_H
#define BATTLESHIP_CPPVERSION_SIMPLESHIPDISPLAYINFO_H

#include "ShipDisplayInfo.h"

template <typename T> class SimpleShipDisplayInfo : public ShipDisplayInfo<T> {
protected:
  T myData, onHit;

public:
  SimpleShipDisplayInfo(T _myData, T _onHit);
  std::unique_ptr<T> getInfo(Coordinate where, bool hit);
};

template <typename T>
SimpleShipDisplayInfo<T>::SimpleShipDisplayInfo(T _myData, T _onHit)
    : myData(_myData), onHit(_onHit) {}

template <typename T>
std::unique_ptr<T> SimpleShipDisplayInfo<T>::getInfo(Coordinate where,
                                                     bool hit) {
  return hit ? std::make_unique<T>(onHit) : std::make_unique<T>(myData);
}

#endif // BATTLESHIP_CPPVERSION_SIMPLESHIPDISPLAYINFO_H