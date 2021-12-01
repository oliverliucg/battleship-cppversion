//
// Created by 刘小东 on 10/7/21.
//

#include "TextPlayer.h"

TextPlayer::TextPlayer(string _name, shared_ptr<Board<char>> _theBoard,
                       shared_ptr<AbstractShipFactory<char>> _shipFactory)
    : name(_name), theBoard(_theBoard), shipFactory(std::move(_shipFactory)),
      moves(3), sonars(3), isAI(false), view(_theBoard),
      scores_matrix(_theBoard->getHeight(),
                    vector<int>(_theBoard->getWidth(), 0)) {
  setupShipCreationList();
}

TextPlayer::TextPlayer(const TextPlayer &other) {
  this->moves = other.moves;
  this->sonars = other.sonars;
  this->isAI = other.isAI;
  this->scores_matrix = other.scores_matrix;
  this->theBoard = other.theBoard;
  this->view = other.view;
  this->shipFactory = other.shipFactory;
  this->name = other.name;
  this->shipsToPlace = other.shipsToPlace;
  this->unit = other.unit;
}

TextPlayer &TextPlayer::operator=(const TextPlayer &other) {
  if (this != &other) {
    this->moves = other.moves;
    this->sonars = other.sonars;
    this->isAI = other.isAI;
    this->scores_matrix = other.scores_matrix;
    this->theBoard = other.theBoard;
    this->view = other.view;
    this->shipFactory = std::move(other.shipFactory);
    this->name = other.name;
    this->shipsToPlace = other.shipsToPlace;
    this->unit = other.unit;
  }
  return *this;
}

void TextPlayer::setupShipCreationList() {
  size_t numOfSubmarine = 2, numOfDestroyer = 3, numOfBattleship = 3,
         numOfCarrier = 2;
  shipsToPlace[nameOfSubmarine] = numOfSubmarine;
  shipsToPlace[nameOfDestroyer] = numOfDestroyer;
  shipsToPlace[nameOfBattleship] = numOfBattleship;
  shipsToPlace[nameOfCarrier] = numOfCarrier;
}

bool TextPlayer::ifHasLost() { return theBoard->ifAllSunk(); }

bool TextPlayer::isInValid(string descr) {
  descr = strToUppercase(descr);
  if (descr.length() != 2 || descr[0] < 'A' ||
      descr[0] > 'A' + theBoard->getHeight() - 1 || descr[1] < '0' ||
      descr[1] > '0' + theBoard->getWidth() - 1) {
    return true;
  }
  return false;
}

Coordinate TextPlayer::readCoordinate(string prompt) {
  string s = "";
  do {
      std::cout << prompt << std::endl;
    std::cin >> s;
    if (s == "") {
      throw MyException(
          "Error: Could not read a new string to create Coordinate.");
    }
  } while (isInValid(s));
  return Coordinate(s);
}

Placement TextPlayer::readPlacementForMove(string prompt) {
  string s = "";
  do {
    std::cin >> s;
    if (s == "") {
      throw MyException(
          "Error: Could not read a new string to create Placement.");
    }
  } while (isInValid(s.substr(0, 2)) || s.length() != 3);
  return Placement(s);
}

char TextPlayer::toChooseAction() {
  char option = ' ';
  if (!isAI) {
    string prompt1 = "Possible actions for Player " + this->name + "\n\n";
    string prompt_F = " F Fire at a square\n";
    string prompt_M = " M Move a ship to another square (" +
                      std::to_string(moves) + " remaining)\n";
    string prompt_S =
        " S Sonar scan (" + std::to_string(sonars) + " remaining)\n";
    while (true) {
      if (!isAI) {
        cout << prompt1;
        cout << prompt_F;
        if (moves > 0) {
          cout << prompt_M;
        }
        if (sonars > 0) {
          cout << prompt_S;
        }
        cout << "Please select one valid action above: " << std::endl;
        cin >> option;
        option = std::toupper(option);
        if (option == 'M' && moves == 0 || option == 'S' && sonars == 0 ||
            option != 'M' && option != 'S' && option != 'F') {
          continue;
        } else {
          break;
        }
      }
    }
    switch (option) {
    case 'M':
      --moves;
      break;
    case 'S':
      --sonars;
      break;
    default:
      break;
    }
  } else {
    int n = randomlyPickFrom(0, 2);
    switch (n) {
    case 0:
      option = 'F';
      break;
    case 1:
      if (moves == 0 || theBoard->getNumOfSunkShips() == 0) {
        option = 'F';
      } else {
        --moves;
        option = 'M';
      }
      break;
    default:
      if (sonars == 0) {
        option = 'F';
      } else {
        --sonars;
        option = 'S';
      }
      break;
    }
  }
  return option;
}

void TextPlayer::addScores(Coordinate targetCor, int val) {
  scores_matrix[targetCor.getRow()][targetCor.getColumn()] += val;
}

Placement TextPlayer::readPlacement(string prompt) {
  cout << prompt;
  string s = "";
  cin >> s;
  if (s == "") {
    throw MyException(
        "Error: Could not read a new string to create Placement.");
  }
  return Placement(s);
}

std::shared_ptr<Ship<char>> TextPlayer::createShip(string shipName,
                                                   Placement p) {
  if (shipName == nameOfSubmarine) {
    return shipFactory->makeSubmarine(p);
  } else if (shipName == nameOfDestroyer) {
    return shipFactory->makeDestroyer(p);
  } else if (shipName == nameOfBattleship) {
    return shipFactory->makeBattleShip(p);
  } else if (shipName == nameOfCarrier) {
    return shipFactory->makeCarrier(p);
  }
  return nullptr;
}

void TextPlayer::doOnePlacement(string shipName) {
  string res = "The first placement in this function";
  Placement p;
  do {
    try {
      if (!isAI) {
        p = readPlacement("Player " + name + " where do you want to place a " +
                          shipName + "?\n");
      } else {
        vector<Placement> availablePlacements =
            theBoard->getAvailablePlacements(false, toupper(shipName[0]));
        p = theBoard->pickPlacement(availablePlacements);
      }
      std::shared_ptr<Ship<char>> s = createShip(shipName, p);
      res = theBoard->tryAddShip(s);
      if (res != "") {
        if (!isAI) {
          cout << res;
          cout << view.displayMyOwnBoard();
        }
      }
    } catch (MyException &exp) {
      std::cout << exp.what();
    }
  } while (res != "");
  if (!isAI) {
    cout << view.displayMyOwnBoard();
  } else {
    cout << "Player " + name + " is placing a " + shipName;
  }
}

void TextPlayer::doPlacementPhase() {
  if (!isAI) {
    cout << BoardTextView(theBoard).displayMyOwnBoard();
    string message = "";
    message =
        message +
        "----------------------------------------------------------------------"
        "----------\n" +
        "Player " + name + ": you are going to place the following ships \n" +
        "For each ship, type the coordinate of the upper left\n" +
        "side of the ship. Submarine and Destroyer are followed\n" +
        "by either H (for horizontal) or V (for vertical) while\n" +
        "Battleship and Carrier are followed by U, R, D or L(for up, right, "
        "down or left). \n" +
        "You have\n" + "\n" + "2 \"Submarines\"\n" + "3 \"Destroyers\"\n" +
        "3 \"Battleships\"\n" + "2 \"Carriers\"\n" +
        "----------------------------------------------------------------------"
        "----------\n";
    cout << message;
    std::map<string, size_t>::iterator it = shipsToPlace.begin();
    while (it != shipsToPlace.end()) {
      for (size_t i = 0; i < it->second; ++i) {
        doOnePlacement(it->first);
      }
      ++it;
    }
  } else {
  }
}

void TextPlayer::firing(std::shared_ptr<Board<char> > enemyBoard) {
    Coordinate targetCor = readCoordinate("Please enter a valid coordinate to fire at:");
    std::shared_ptr<Ship<char> > s = enemyBoard->fireAt(targetCor);
    if(s == nullptr){
        cout << "Player " << name << " missed!" << std::endl;
    }else{
        cout << "Player " << name << " hit a " << s->getName() << " on " << targetCor.toString() << endl;
    }
}

void TextPlayer::sonar(std::shared_ptr<Board<char> > enemyBoard) {
    Coordinate targetCor = readCoordinate("Please enter a valid coordinate for sonar detection:");
    std::unordered_map<char, size_t> hashMap = enemyBoard->sonarScanning(targetCor);
    if(hashMap.empty()){
        cout << "Nothing detected" << endl;
    }
    std::string nameOfUnit = " square\n";
    std::string nameOfUnits = " squares\n";
    std::unordered_map<char, size_t>::iterator it = hashMap.begin();
    while(it != hashMap.end()){
        cout << accessToFullName[it->first] << "s occupy " << it->second <<(it->second == 1? nameOfUnit:nameOfUnits) ;
        ++it;
    }
}
void TextPlayer::playOneTurn(std::shared_ptr<Board<char>> enemyBoard, BoardTextView enemyView, string enemyName) {
    cout << view.displayMyBoardWithEnemyNextToIt(enemyView, "Your ocean", "Player " + enemyName + "'s ocean");
    if(moves == 0 && sonars == 0){
        firing(enemyBoard);
    }else{
        char action = toChooseAction();
        switch (action) {
            case 'F':
                firing(enemyBoard);
                break;
            case 'M':
                break;
            case 'S':
                sonar(enemyBoard);
                break;
        }
    }
    cout << view.displayMyBoardWithEnemyNextToIt(enemyView, "Your ocean", "Player " + enemyName + "'s ocean");
}