//
// Created by 刘小东 on 10/4/21.
//

#include "ShipFactory.h"

std::shared_ptr<Ship<char> > ShipFactory::createRectangleShip(Placement p, int w, int h, char letter) {
    if(p.getOrientation() == 'H'){
        int temp = w;
        w = h;
        h = temp;
    }else if(p.getOrientation() != 'V'){
        throw MyException("Orientation should be H or V, but is " + string(1, p.getOrientation()) + "\n");
    }
    return std::make_shared<RectangleShip<char> >(p.getWhere(), w, h, letter, '*');
}

std::shared_ptr<Ship<char> > ShipFactory::createBattleShip(Placement p, char letter) {
    char orientation = p.getOrientation();
    if(orientation != 'U' && orientation != 'R' && orientation != 'D' && orientation != 'L'){
        throw MyException("Orientation should be U, R, D or L , but is " + string(1, orientation)+ "\n");
    }
    return std::make_shared<BattleShip<char> >(p.getWhere(), p.getOrientation(), letter, '*');
}

std::shared_ptr<Ship<char> > ShipFactory::createCarrier(Placement p, char letter) {
    char orientation = p.getOrientation();
    if(orientation != 'U' && orientation != 'R' && orientation != 'D' && orientation != 'L'){
        throw MyException("Orientation should be U, R, D or L , but is " + string(1, orientation)+ "\n");
    }
    return std::make_shared<Carrier<char> >(p.getWhere(), p.getOrientation(), letter, '*');
}
std::shared_ptr<Ship<char> > ShipFactory::makeSubmarine(Placement p) {
    return createRectangleShip(p, 1, 2, 's');
}

std::shared_ptr<Ship<char> > ShipFactory::makeDestroyer(Placement p) {
    return createRectangleShip(p, 1, 3, 'd');
}

std::shared_ptr<Ship<char> > ShipFactory::makeBattleShip(Placement p) {
    return createBattleShip(p, 'b');
}

std::shared_ptr<Ship<char> > ShipFactory::makeCarrier(Placement p) {
    return createCarrier(p, 'c');
}