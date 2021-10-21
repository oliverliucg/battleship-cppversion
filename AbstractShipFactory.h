#ifndef BATTLESHIP_CPPVERSION_ABSTRACTSHIPFACTORY_H
#define BATTLESHIP_CPPVERSION_ABSTRACTSHIPFACTORY_H

#include "Ship.h"

template<typename T>
class AbstractShipFactory{
public:
    virtual std::shared_ptr<Ship<T> > makeSubmarine(Placement p) = 0;
    virtual std::shared_ptr<Ship<T> > makeDestroyer(Placement p) = 0;
    virtual std::shared_ptr<Ship<T> > makeBattleShip(Placement p) = 0;
    virtual std::shared_ptr<Ship<T> > makeCarrier(Placement p) = 0;
};

#endif //BATTLESHIP_CPPVERSION_ABSTRACTSHIPFACTORY_H