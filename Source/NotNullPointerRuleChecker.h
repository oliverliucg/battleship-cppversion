//
// Created by 刘小东 on 10/18/21.
//

#ifndef BATTLESHIP_CPPVERSION_NOTNULLPOINTERRULECHECKER_H
#define BATTLESHIP_CPPVERSION_NOTNULLPOINTERRULECHECKER_H

template<typename T>
class NotNullPointerRuleChecker : public PlacementRuleChecker<T> {
protected:
    virtual string checkMyRule(std::shared_ptr<Ship<T>> theShip,
                               std::shared_ptr<Board<T>> theBoard);

public:
    NotNullPointerRuleChecker(unique_ptr<PlacementRuleChecker<T>> _next)
            : PlacementRuleChecker<T>(std::move(_next)) {}
};

template<typename T>
string
NotNullPointerRuleChecker<T>::checkMyRule(std::shared_ptr<Ship<T>> theShip,
                                          std::shared_ptr<Board<T>> theBoard) {
    if (theShip == nullptr || theBoard == nullptr) {
        return "Null pointer for ship or board.\n";
    }
    return "";
}

#endif // BATTLESHIP_CPPVERSION_NOTNULLPOINTERRULECHECKER_H
