#ifndef BATTLESHIP_CPPVERSION_BATTLESHIPBOARD_H
#define BATTLESHIP_CPPVERSION_BATTLESHIPBOARD_H

#include "Board.h"
#include "ordinary.h"
#include "PlacementRuleChecker.h"
#include "NoCollisionRuleChecker.h"
#include "NotNullPointerRuleChecker.h"

template<typename T>
class BattleShipBoard : public Board<T>, public std::enable_shared_from_this<BattleShipBoard<T> >{
private:
    const int width;
    const int height;
    const unique_ptr<PlacementRuleChecker<T> > placementRuleChecker;
protected:
    std::unique_ptr<T> whatIsAt(Coordinate where, bool isSelf);
    string removeShipFromBoardIfExist(Coordinate where);
public:
    vector<std::shared_ptr<Ship<T> > > myShips;
    T missInfo;
    set<Coordinate> enemyMisses;

    BattleShipBoard(int w, int h, std::unique_ptr<PlacementRuleChecker<T>> placementChecker, T missInfo);
    BattleShipBoard(int w, int h, T missInfo);
    //BattleShipBoard(const BattleShipBoard& other);
    //BattleShipBoard& operator=(const BattleShipBoard& other);
    int getWidth();
    int getHeight();
    string tryAddShip(std::shared_ptr<Ship<T> > toAdd);
    int numOfShips();
    std::unique_ptr<T> whatIsAtForSelf(Coordinate where);
    std::unique_ptr<T> whatIsAtForEnemy(Coordinate where);
    shared_ptr<Ship<T> > fireAt(Coordinate c);
    bool ifAllSunk();
    bool move(Coordinate c, Placement p);
    int sonarScanning(Coordinate c, T target);
    Coordinate pickSunkShip();
    Coordinate randomlyPickShip();
    vector<Coordinate> getAvailablePoints(bool isToGetAll);
    vector<Placement> getAvailablePlacements(bool isToGetAll, char type_of_ship);
    Placement pickPlacement(vector<Placement> availablePlacements);
    int getNumOfSunkShips();
    bool isInRange(Coordinate where);
};

template<typename T>
unique_ptr<T> BattleShipBoard<T>::whatIsAt(Coordinate where, bool isSelf){
    for(shared_ptr<Ship<T> > s : myShips){
        if(s->occupyCoordinates(where)){
            return s->getDisplayInfoAt(where, isSelf);
        }
    }
    if(!isSelf && enemyMisses.count(where)){
        return std::make_unique<T>(missInfo);
    }
    return nullptr;
}

template<typename T>
string BattleShipBoard<T>::removeShipFromBoardIfExist(Coordinate where){
    size_t i = 0;
    for(std::shared_ptr<Ship<T> > ship : myShips){
        if(ship->getUpperLeft() == where){
            myShips.erase(myShips.begin()+i);
            return "";
        }
    }
    return "No Ship At (" + std::to_string(where.getRow())  + "," + std::to_string(where.getColumn()) + ")";
}

template<typename T>
BattleShipBoard<T>::BattleShipBoard(int w, int h, unique_ptr<PlacementRuleChecker<T> > _placementRuleChecker, T _missInfo) : width(w), height(h),
placementRuleChecker(std::move(_placementRuleChecker)), missInfo(_missInfo){
    if (w <= 0) {
      throw MyException("BattleShipBoard's width must be positive but is " + std::to_string(w));
    }
    if (h <= 0) {
      throw MyException("BattleShipBoard's height must be positive but is " + std::to_string(h));
    }
}
template<typename T>
BattleShipBoard<T>::BattleShipBoard(int w, int h, T _missInfo) : 
BattleShipBoard(w, h, std::make_unique<NotNullPointerRuleChecker<T> >(std::make_unique<NoCollisionRuleChecker<T> >(std::make_unique<InBoundRuleChecker<T> >(nullptr))), _missInfo){
}
//template<typename T>
//BattleShipBoard<T>::BattleShipBoard(const BattleShipBoard<T> &other): width(other.width), height(other.height),
//placementRuleChecker(std::make_unique<NotNullPointerRuleChecker<T> >(std::make_unique<NoCollisionRuleChecker<T> >(std::make_unique<InBoundRuleChecker<T> >(nullptr)))), missInfo(other.missInfo) {
//}
//
//template<typename T>
//BattleShipBoard<T> &BattleShipBoard<T>::operator=(const BattleShipBoard<T> &other) {
//    if(this != other){
//        this->width = other.width;
//        this->height = other.height;
//        this->placementRuleChecker = std::make_unique<NotNullPointerRuleChecker<T> >(std::make_unique<NoCollisionRuleChecker<T> >(std::make_unique<InBoundRuleChecker<T> >(nullptr)));
//        this->missInfo = other.missInfo;
//    }
//    return (*this);
//}
template<typename T>
int BattleShipBoard<T>::getWidth(){
    return width;
}

template<typename T>
int BattleShipBoard<T>:: getHeight(){
    return height;
}

template<typename T>
string BattleShipBoard<T>::tryAddShip(shared_ptr<Ship<T> > toAdd){
    string placementProblem = placementRuleChecker->checkPlacement(toAdd,
                                                                   std::enable_shared_from_this<BattleShipBoard<T> >::shared_from_this());
    if(placementProblem == ""){
        myShips.emplace_back(toAdd);
    }
    return placementProblem;
}


template<typename T>
unique_ptr<T> BattleShipBoard<T>::whatIsAtForSelf(Coordinate where){
    return whatIsAt(where, true);
}

template<typename T>
unique_ptr<T> BattleShipBoard<T>::whatIsAtForEnemy(Coordinate where){
    return whatIsAt(where, false);
}

template<typename T>
shared_ptr<Ship<T> > BattleShipBoard<T>::fireAt(Coordinate c){
    for(std::shared_ptr<Ship<T> > s : myShips){
        if(s->occupyCoordinates(c)){
            s->recordHitAt(c);
            return s;
        }
    }
    enemyMisses.insert(c);
    return nullptr;
}

template<typename T>
bool BattleShipBoard<T>::ifAllSunk(){
    for(std::shared_ptr<Ship<T> > s : myShips){
        if(!s->isSunk()){
            return false;
        }
    }
    return true;
}

template<typename T>
bool BattleShipBoard<T>::move(Coordinate c, Placement p){
    std::shared_ptr<Ship<T> > target;
    Coordinate original;
    size_t i = 0;
    for(std::shared_ptr<Ship<T> > ship : myShips){
        if(ship->getUpperLeft() == c || ship->occupyCoordinates(c)){
            original = ship->getUpperLeft();
            target = ship;
            myShips.erase(myShips.begin()+i);
            break;
        }
        ++i;
    }
    target->moveTo(p);
    string placementProblem = placementRuleChecker->checkPlacement(target,
                                                                   std::enable_shared_from_this<BattleShipBoard<T>>::shared_from_this());
    if(placementProblem != ""){
        target->moveTo(Placement(original, 'U'));
        myShips.emplace_back(target);
        return false;
    }
    myShips.emplace_back(target);
    return true;
}

template<typename T>
int BattleShipBoard<T>::sonarScanning(Coordinate c, T target){
    int row = c.getRow(), column = c.getColumn(), count = 0;
    std::unique_ptr<T> temp = nullptr;
    for(int i = row+3; i >= row-3; --i){
        std::unique_ptr<T> temp = whatIsAtForSelf(Coordinate(i, column));
        if(temp != nullptr && target == *temp){
            ++count;
        }
    }
    for(int len = 2; len >= 0; --len){
        for(int i = row+len; i >= row-len; --i){
            temp = whatIsAtForSelf(Coordinate(i, column-3+len));
            if(temp != nullptr && target == *temp){
                ++count;
            }
            temp = whatIsAtForSelf(Coordinate(i, column+3-len));
            if(temp != nullptr && target == *temp){
                ++count;
            }
        }
    }
    return count;
}

template<typename T>
Coordinate BattleShipBoard<T>::pickSunkShip(){
    Coordinate res(-1, -1);
    for(std::shared_ptr<Ship<T> > ship : myShips){
        if(ship->isSunk()){
            if(res == Coordinate(-1, -1) || randomlyPickFrom(0, 1) == 1){
                res = ship->getUpperLeft();
            }
        }
    }
    return res;
}

template<typename T>
Coordinate BattleShipBoard<T>::randomlyPickShip(){
    Coordinate res(-1, -1);
    for(std::shared_ptr<Ship<T> > ship : myShips){
        if(ship->isSunk()){
            if(res == Coordinate(-1, -1) || randomlyPickFrom(0, 1) == 1){
                res = ship->getUpperLeft();
            }
        }
    }
    return res;
}


template<typename T>
vector<Coordinate> BattleShipBoard<T>::getAvailablePoints(bool isToGetAll){
    vector<Coordinate> availablePoints;
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if(isToGetAll || whatIsAtForSelf(Coordinate(i, j)) == NULL){
                availablePoints.emplace_back(Coordinate(i, j));
            }
        }
    }
    return availablePoints;
}

template<typename T>
vector<Placement> BattleShipBoard<T>::getAvailablePlacements(bool isToGetAll, char type_of_ship){
    vector<Coordinate> availablePoints = getAvailablePoints(isToGetAll);
    vector<Placement> availablePlacements;
    if(type_of_ship == 'S' || type_of_ship == 'D'){
        for(int i = 0; i < availablePoints.size(); ++i){
            availablePlacements.emplace_back(Placement(availablePoints[i], 'H'));
            availablePlacements.emplace_back(Placement(availablePoints[i], 'V'));
        }
    }else{
        for(int i = 0; i < availablePoints.size(); ++i){
            availablePlacements.emplace_back(Placement(availablePoints[i], 'U'));
            availablePlacements.emplace_back(Placement(availablePoints[i], 'R'));
            availablePlacements.emplace_back(Placement(availablePoints[i], 'D'));
            availablePlacements.emplace_back(Placement(availablePoints[i], 'L'));
        }
    }
    return availablePlacements;
}

template<typename T>
Placement BattleShipBoard<T>::pickPlacement(vector<Placement> availablePlacements){
    int randomPoint = randomlyPickFrom(0, availablePlacements.size()-1);
    Placement res = availablePlacements[randomPoint];
    availablePlacements.erase(availablePlacements.begin()+randomPoint);
    return res;
}

template<typename T>
int BattleShipBoard<T>::getNumOfSunkShips(){
    int num = 0;
    for(std::shared_ptr<Ship<T> > ship: myShips){
        if(ship->isSunk()){
            ++num;
        }
    }
    return num;
}
template<typename T>
int BattleShipBoard<T>::numOfShips() {
    return myShips.size();
}
template<typename T>
bool BattleShipBoard<T>::isInRange(Coordinate where){
    return where.getRow() >= 0 && where.getRow() < height && where.getColumn() >= 0 && where.getColumn() < width;
}


#endif //BATTLESHIP_CPPVERSION_BATTLESHIPBOARD_H