//
// Created by 刘小东 on 10/4/21.
//

#include "ShipFactory.h"
std::shared_ptr<Ship<char>>
ShipFactory::createRectangleShip(Placement p, int w, int h, char letter, string name) {
  if (p.getOrientation() == 'H') {
    int temp = w;
    w = h;
    h = temp;
  } else if (p.getOrientation() != 'V') {
    throw MyException("Orientation should be H or V, but is " +
                      string(1, p.getOrientation()) + "\n");
  }
  return std::make_shared<RectangleShip<char>>(name, p.getWhere(), w, h, std::make_shared<char>(letter), std::make_shared<char>('*'));
}

std::shared_ptr<Ship<char>> ShipFactory::createBattleShip(Placement p,
                                                          char letter, string name) {
  char orientation = p.getOrientation();
  if (orientation != 'U' && orientation != 'R' && orientation != 'D' &&
      orientation != 'L') {
    throw MyException("Orientation should be U, R, D or L , but is " +
                      string(1, orientation) + "\n");
  }
  return std::make_shared<BattleShip<char>>(name, p.getWhere(), p.getOrientation(),
                                            std::make_shared<char>(letter), std::make_shared<char>('*'));
}

std::shared_ptr<Ship<char>> ShipFactory::createCarrier(Placement p,
                                                       char letter, string name) {
  char orientation = p.getOrientation();
  if (orientation != 'U' && orientation != 'R' && orientation != 'D' &&
      orientation != 'L') {
    throw MyException("Orientation should be U, R, D or L , but is " +
                      string(1, orientation) + "\n");
  }
  return std::make_shared<Carrier<char>>(name, p.getWhere(), p.getOrientation(),
                                         std::make_shared<char>(letter), std::make_shared<char>('*'));
}
std::shared_ptr<Ship<char>> ShipFactory::makeSubmarine(Placement p) {
  return createRectangleShip(p, 1, 2, 's', nameOfSubmarine);
}

std::shared_ptr<Ship<char>> ShipFactory::makeDestroyer(Placement p) {
  return createRectangleShip(p, 1, 3, 'd', nameOfDestroyer);
}

std::shared_ptr<Ship<char>> ShipFactory::makeBattleShip(Placement p) {
  return createBattleShip(p, 'b', nameOfBattleship);
}

std::shared_ptr<Ship<char>> ShipFactory::makeCarrier(Placement p) {
  return createCarrier(p, 'c', nameOfCarrier);
}