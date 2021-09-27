#include "Ship.h"
#include "ShipDisplayInfo.h"

template <typename T> 
class BasicShip : public Ship<T> {
protected:
  Coordinate upperLeft;
  unordered_map<Coordinate, bool> myPieces;
  ShipDisplayInfo<T> myDisplayInfo;
  ShipDisplayInfo<T> enemyDisplayInfo;

    void checkCoordinateInThisShip(Coordinate c);
public:
  BasicShip(Coordinate _upperLeft, unordered_set<Coordinate> where,
            ShipDisplayInfo<T> _myDisplayInfo,
            ShipDisplayInfo<T> _enemyDisplayInfo)
      : upperLeft(_upperLeft), myDisplayInfo(_myDisplayInfo),
        enemyDisplayInfo(_enemyDisplayInfo) {
    unordered_set<Coordinate>::iterator it = where.begin();
    while (it != where.end()) {
     // true means hit
      myPieces[*it] = false;
      ++it;
    }
  }

    virtual bool occupyCoordinates(Coordinate where);
    virtual bool isSunk();
    virtual bool wasHitAt(Coordinate where);
    virtual void recordHitAt(Coordinate where);
    virtual void moveTo(Placement p);
    virtual T getDisplayAt(Coordinate where, bool myShip) ;
    virtual unordered_set<Coordinate> getCoordinates();
    virtual Coordinate getUpperLeft(); 
};

template<typename T>
void BasicShip<T>::checkCoordinateInThisShip(Coordinate where){
    if(!myPieces.count(where)){
        throw MyException("The target Coordinate is not in this ship");
    }
}

template<typename T>
bool BasicShip<T>::occupyCoordinates(Coordinate where){
    return myPieces.count(where);
}

template<typename T>
bool BasicShip<T>::isSunk(){
    unordered_map<Coordinate, bool>::iterator it = myPieces.begin();
    while(it != myPieces.end()){
        if(!it->second){
            return false;
        }
    }
    return true;
}

template<typename T>
void BasicShip<T>::recordHitAt(Coordinate where){
    checkCoordinateInThisShip(where);
    myPieces[where] = true;
}

template<typename T>
bool BasicShip<T>::wasHitAt(Coordinate where){
    checkCoordinateInThisShip(where);
    return myPieces[where];
}
template<typename T>
void BasicShip<T>::moveTo(Placement p){
    
}

template<typename T>
T BasicShip<T>::getDisplayAt(Coordinate where, bool myShip){
    checkCoordinateInThisShip(where);
    if(myShip){
        return myDisplayInfo.getInfo(where, wasHitAt(where));
    }else{
        return enemyDisplayInfo.getInfo(where, wasHitAt(where));
    }
}

template<typename T>
unordered_set<Coordinate> BasicShip<T>::getCoordinates(){
    unordered_set<Coordinate> keys;
    unordered_map<Coordinate, bool>::iterator it = myPieces.begin();
    while(it != myPieces.end()){
        keys.insert(it->first);
        ++it;
    }
    return keys;
}

template<typename T>
Coordinate BasicShip<T>::getUpperLeft(){
    return upperLeft;
}


