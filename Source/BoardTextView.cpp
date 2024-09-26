//
// Created by 刘小东 on 10/8/21.
//

#include "BoardTextView.h"

BoardTextView::BoardTextView() : toDisplay(nullptr) {}

BoardTextView::BoardTextView(shared_ptr<Board<char>> _toDisplay)
        : toDisplay(_toDisplay) {
    if (toDisplay->getWidth() > 10 || toDisplay->getHeight() > 26) {
        throw MyException("Board must be no larger than 10x26, but is " +
                          std::to_string(toDisplay->getWidth()) + "x" +
                          std::to_string(toDisplay->getHeight()));
    }
}

string BoardTextView::makeHeader() {
    string ans = "  ";
    string sep = "";
    for (int i = 0; i < toDisplay->getWidth(); ++i) {
        ans.append(sep);
        ans.append(std::to_string(i));
        sep = "|";
    }
    ans += '\n';
    return ans;
}

string BoardTextView::displayAnyBoard(bool isMyBoard) {
    string ans = "";
    string header = makeHeader();
    ans.append(header);
    int letter = 65;
    string sep = "";
    for (int row = 0; row < toDisplay->getHeight(); ++row) {
        ans += (char) letter;
        ans += ' ';
        for (int column = 0; column < toDisplay->getWidth(); ++column) {
            ans.append(sep);
            if (isMyBoard) {
                toDisplay->whatIsAtForSelf(Coordinate(row, column)) != nullptr
                ? ans += *(toDisplay->whatIsAtForSelf(Coordinate(row, column)))
                : ans += ' ';
            } else {
                toDisplay->whatIsAtForEnemy(Coordinate(row, column)) != nullptr
                ? ans += *(toDisplay->whatIsAtForEnemy(Coordinate(row, column)))
                : ans += ' ';
            }
            sep = '|';
        }
        ans += ' ';
        ans += (char) letter;
        ans += '\n';
        ++letter;
        sep = "";
    }
    ans.append(header);
    return ans;
}

string BoardTextView::displayMyOwnBoard() { return displayAnyBoard(true); }

string BoardTextView::displayEnemyBoard() { return displayAnyBoard(false); }

string BoardTextView::displayMyBoardWithEnemyNextToIt(BoardTextView enemyView,
                                                      string myHeader,
                                                      string enemyHeader) {
    vector<string> myLines = splitStringByCharacter(displayMyOwnBoard(), '\n');
    vector<string> enemyLines = splitStringByCharacter(enemyView.displayEnemyBoard(), '\n');
    if (myLines.size() != enemyLines.size()) {
        throw MyException("Boards must be the same height to put side by side");
    }
    string ans(5, ' ');
    int enemyHdrStartCol = toDisplay->getWidth() * 2 + 33;
    int enemyNumHedStartCol = toDisplay->getWidth() * 2 + 31;
    int enemyBoardStartCol = toDisplay->getWidth() * 2 + 29;
    ans.append(myHeader);
    ans.append(string(enemyHdrStartCol - myHeader.length() - 5, ' '));
    ans.append(enemyHeader);
    int sizeOfMyLinesMinusOne = myLines.size() - 1;
    ans += '\n';
    ans.append(myLines[0]);
    ans.append(string(enemyNumHedStartCol - myLines.size(), ' '));
    ans.append(enemyLines[0]);
    ans += '\n';
    for (int i = 1; i < sizeOfMyLinesMinusOne; ++i) {
        ans.append(myLines[i]);
        ans.append(string(enemyBoardStartCol - myLines.size(), ' '));
        ans.append(enemyLines[i]);
        ans += '\n';
    }
    ans.append(myLines[sizeOfMyLinesMinusOne]);
    ans.append(string(enemyNumHedStartCol - myLines.size(), ' '));
    ans.append(enemyLines[sizeOfMyLinesMinusOne]);
    ans += '\n';
    return ans;
}