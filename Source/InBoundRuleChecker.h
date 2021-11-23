#ifndef BATTLESHIP_CPPVERSION_INBOUNDRULECHECKER_H
#define BATTLESHIP_CPPVERSION_INBOUNDRULECHECKER_H

#include "PlacementRuleChecker.h"

template <typename T>
class InBoundRuleChecker : public PlacementRuleChecker<T> {
protected:
  virtual string checkMyRule(std::shared_ptr<Ship<T>> theShip,
                             std::shared_ptr<Board<T>> theBoard);

public:
  InBoundRuleChecker(unique_ptr<PlacementRuleChecker<T>> _next)
      : PlacementRuleChecker<T>(std::move(_next)) {}
};

template <typename T>
string InBoundRuleChecker<T>::checkMyRule(std::shared_ptr<Ship<T>> theShip,
                                          std::shared_ptr<Board<T>> theBoard) {
  int height = theBoard->getHeight();
  int width = theBoard->getWidth();
  for (Coordinate c : theShip->getCoordinates()) {
    int row = c.getRow();
    int column = c.getColumn();
    if (row < 0) {
      return "That placement is invalid: the ship goes off the top of the "
             "board.\n";
    }
    if (row >= height) {
      return "That placement is invalid: the ship goes off the bottom of the "
             "board.\n";
    }
    if (column < 0) {
      return "That placement is invalid: the ship goes off the left of the "
             "board.\n";
    }
    if (column >= width) {
      return "That placement is invalid: the ship goes off the right of the "
             "board.\n";
    }
  }
  return "";
}

#endif // BATTLESHIP_CPPVERSION_INBOUNDRULECHECKER_H