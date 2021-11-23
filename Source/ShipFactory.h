//
// Created by 刘小东 on 10/4/21.
//

#ifndef BATTLESHIP_CPPVERSION_SHIPFACTORY_H
#define BATTLESHIP_CPPVERSION_SHIPFACTORY_H
#include "AbstractShipFactory.h"
#include "BattleShip.h"
#include "Carrier.h"
#include "RectangleShip.h"
#include "ordinary.h"

class ShipFactory : public AbstractShipFactory<char> {
protected:
  std::shared_ptr<Ship<char>> createRectangleShip(Placement p, int w, int h,
                                                  char letter, string name);

  std::shared_ptr<Ship<char>> createBattleShip(Placement p, char letter, string name);

  std::shared_ptr<Ship<char>> createCarrier(Placement p, char letter, string name);

  virtual std::shared_ptr<Ship<char>> makeSubmarine(Placement p);
  virtual std::shared_ptr<Ship<char>> makeDestroyer(Placement p);
  virtual std::shared_ptr<Ship<char>> makeBattleShip(Placement p);
  virtual std::shared_ptr<Ship<char>> makeCarrier(Placement p);
};
#endif // BATTLESHIP_CPPVERSION_SHIPFACTORY_H
