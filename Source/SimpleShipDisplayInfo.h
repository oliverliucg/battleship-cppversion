#ifndef BATTLESHIP_CPPVERSION_SIMPLESHIPDISPLAYINFO_H
#define BATTLESHIP_CPPVERSION_SIMPLESHIPDISPLAYINFO_H

#include "ShipDisplayInfo.h"

template<typename T>
class SimpleShipDisplayInfo : public ShipDisplayInfo<T> {
protected:
    std::shared_ptr<T> myData, onHit;

public:
    SimpleShipDisplayInfo(std::shared_ptr<T> _myData, std::shared_ptr<T> _onHit);

    std::shared_ptr<T> getInfo(Coordinate where, bool hit);
};

template<typename T>
SimpleShipDisplayInfo<T>::SimpleShipDisplayInfo(std::shared_ptr<T> _myData, std::shared_ptr<T> _onHit)
        : myData(_myData), onHit(_onHit) {}

template<typename T>
std::shared_ptr<T> SimpleShipDisplayInfo<T>::getInfo(Coordinate where,
                                                     bool hit) {
    return hit ? onHit : myData;
}

#endif // BATTLESHIP_CPPVERSION_SIMPLESHIPDISPLAYINFO_H