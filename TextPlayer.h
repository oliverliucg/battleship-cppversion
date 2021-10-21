//
// Created by 刘小东 on 10/3/21.
//

#ifndef BATTLESHIP_CPPVERSION_TEXTPLAYER_H
#define BATTLESHIP_CPPVERSION_TEXTPLAYER_H

#include "AbstractShipFactory.h"
#include "BattleShip.h"
#include "Board.h"
#include "BoardTextView.h"
#include "Carrier.h"
#include "RectangleShip.h"
#include <iostream>

using std::cin;
using std::cout;
class TextPlayer {
private:
  int moves, sonars;
  bool isAI;
  vector<vector<int>> scores_matrix;

  bool isInValid(string descr);

protected:
  void setupShipCreationList();
  Coordinate readCoordinate(string prompt);
  Placement readPlacementForMove(string prompt);
  char toChooseAction();
  void addScores(Coordinate targetCor, int val);
  std::shared_ptr<Ship<char>> createShip(string shipName, Placement p);

public:
  shared_ptr<Board<char>> theBoard;
  BoardTextView view;
  shared_ptr<AbstractShipFactory<char>> shipFactory;
  string name;
  std::map<string, size_t> shipsToPlace;
  int unit;
  TextPlayer() : moves(3), sonars(3), isAI(false){};
  TextPlayer(string name, std::shared_ptr<Board<char>> theBoard,
             shared_ptr<AbstractShipFactory<char>> shipFactory);
  TextPlayer(const TextPlayer &other);
  TextPlayer &operator=(const TextPlayer &other);
  bool ifHasLost();
  Placement readPlacement(string prompt);
  void doOnePlacement(string shipName);
  void doPlacementPhase();
};

#endif // BATTLESHIP_CPPVERSION_TEXTPLAYER_H
