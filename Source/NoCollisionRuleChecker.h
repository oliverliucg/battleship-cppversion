#ifndef BATTLESHIP_CPPVERSION_NOCOLLISIONRULECHECKER_H
#define BATTLESHIP_CPPVERSION_NOCOLLISIONRULECHECKER_H

#include "InBoundRuleChecker.h"

template<typename T>
class NoCollisionRuleChecker : public PlacementRuleChecker<T> {
protected:
    virtual string checkMyRule(std::shared_ptr<Ship<T>> theShip,
                               std::shared_ptr<Board<T>> theBoard);

public:
    NoCollisionRuleChecker(unique_ptr<PlacementRuleChecker<T>> _next)
            : PlacementRuleChecker<T>(std::move(_next)) {}
};

template<typename T>
string
NoCollisionRuleChecker<T>::checkMyRule(std::shared_ptr<Ship<T>> theShip,
                                       std::shared_ptr<Board<T>> theBoard) {
    for (Coordinate c: theShip->getCoordinates()) {
        if (theBoard->whatIsAtForSelf(c) != NULL) {
            return "That placement is invalid: the ship overlaps another ship.\n";
        }
    }
    return "";
}

#endif // BATTLESHIP_CPPVERSION_NOCOLLISIONRULECHECKER_H