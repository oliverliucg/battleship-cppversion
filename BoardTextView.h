//
// Created by 刘小东 on 10/3/21.
//

#ifndef BATTLESHIP_CPPVERSION_BOARDTEXTVIEW_H
#define BATTLESHIP_CPPVERSION_BOARDTEXTVIEW_H

#include "Board.h"
#include "Coordinate.h"
#include "MyException.h"
#include "ordinary.h"

class BoardTextView {
private:
  std::shared_ptr<Board<char>> toDisplay;
  string makeHeader();

protected:
  string displayAnyBoard(bool isMyBoard);

public:
  BoardTextView();
  BoardTextView(std::shared_ptr<Board<char>> _toDisplay);
  string displayMyOwnBoard();
  string displayEnemyBoard();
  string displayMyBoardWithEnemyNextToIt(BoardTextView enemyView,
                                         string myHeader, string enemyHeader);
};

#endif // BATTLESHIP_CPPVERSION_BOARDTEXTVIEW_H
