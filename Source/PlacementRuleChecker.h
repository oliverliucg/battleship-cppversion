#ifndef BATTLESHIP_CPPVERSION_PLACEMENTRULECHECKER_H
#define BATTLESHIP_CPPVERSION_PLACEMENTRULECHECKER_H

#include "Board.h"
#include "Ship.h"

using std::move;
using std::unique_ptr;

template<typename T>
class PlacementRuleChecker {
protected:
    unique_ptr<PlacementRuleChecker<T>> next;

    virtual string checkMyRule(std::shared_ptr<Ship<T>> theShip,
                               std::shared_ptr<Board<T>> theBoard) {
        return "";
    };

public:
    PlacementRuleChecker(unique_ptr<PlacementRuleChecker<T>> _next)
            : next(move(_next)) {}

    string checkPlacement(std::shared_ptr<Ship<T>> theShip,
                          std::shared_ptr<Board<T>> theBoard);
};

template<typename T>
string
PlacementRuleChecker<T>::checkPlacement(std::shared_ptr<Ship<T>> theShip,
                                        std::shared_ptr<Board<T>> theBoard) {
    string temp = checkMyRule(theShip, theBoard);
    if (temp != "") {
        return temp;
    }
    if (next != NULL) {
        return next->checkPlacement(theShip, theBoard);
    }
    return "";
}

#endif // BATTLESHIP_CPPVERSION_PLACEMENTRULECHECKER_H