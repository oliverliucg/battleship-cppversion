//
// Created by 刘小东 on 10/8/21.
//

#include "App.h"

App::App(TextPlayer _player1, TextPlayer _player2) : player1(_player1), player2(_player2){}

void App::doPlacementPhase() {
    player1.doPlacementPhase();
    player2.doPlacementPhase();
}

int main(int argv, char** argc){
    std::shared_ptr<Board<char> > b1 = std::make_shared<BattleShipBoard<char> >(10, 20, 'X');
    std::shared_ptr<Board<char> > b2 = std::make_shared<BattleShipBoard<char> >(10, 20, 'X');
    shared_ptr<AbstractShipFactory<char> > factory = std::make_shared<ShipFactory>();
    TextPlayer p1("A", b1, factory);
    TextPlayer p2("B", b2, factory);
    App app(p1, p2);
    app.doPlacementPhase();
    return EXIT_SUCCESS;
}