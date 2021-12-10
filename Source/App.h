//
// Created by 刘小东 on 10/8/21.
//

#ifndef BATTLESHIP_CPPVERSION_APP_H
#define BATTLESHIP_CPPVERSION_APP_H

#include "BattleShipBoard.h"
#include "ShipFactory.h"
#include "TextPlayer.h"

class App {
public:
    TextPlayer player1, player2;

    App(TextPlayer _player1, TextPlayer _player2);

    void doPlacementPhase();

    void doAttackingPhase();
};

#endif // BATTLESHIP_CPPVERSION_APP_H
