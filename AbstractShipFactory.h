#include "Ship.h"

template<typename T>
class AbstractShipFactory{
public:
    Ship<T> makeSubmarine(Placement where);
    Ship<T> makeDestroyer(Placement where);
    Ship<T> makeBattleShip(Placement where);
    Ship<T> makeCarrier(Placement where);
};