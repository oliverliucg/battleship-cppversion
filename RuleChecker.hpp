#include <cstdlib>
#include <cstdio>
#include "Board.hpp"
bool isOutOfBound(Ship ship){
  bool result = false;
  set<pair<char,char>>::iterator it = ship.points.begin();
  while(it != ship.points.end()){
    if(isInvalid(*it)){
      result = true;
    }
    ++it;
  }
  return result;
}

bool isInvalid(pair<char,char> inputPoint){
  bool result = false;
  if(inputPoint.first<'A'||inputPoint.first>'T'||inputPoint.second<'0'||inputPoint.second>'9'){
    result = true;
  }
  return result;
}

bool isCollision(Board b,Ship ship){
  set<pair<char,char>> shipsPointSet = FindAllShipPoints(b);
  bool isCollision = hasSamePoint(shipsPointSet,ship.points);
  return isCollision;
}
set<pair<char,char>> FindAllShipPoints(Board b){
  set<pair<char,char>> result;
  set<Ship>::iterator it = b.ships.begin();
  while(it != b.ships.end()){
    set<pair<char,char>>::iterator iter = it->points.begin();
    while(iter != it->points.end()){
      result.insert(*iter);
      ++iter;
    }
    ++it;
  }
  return result;
}
bool hasSamePoint(set<pair<char,char>> shipsPointSetFromBoard, set<pair<char,char>>shipPoints){
  bool result = false;
  set<pair<char,char>>::iterator it = shipsPointSetFromBoard.begin();
  while(it != shipsPointSetFromBoard.end()){
    set<pair<char,char>>::iterator iter = shipPoints.begin();
    while(iter != shipPoints.end()){
      if(*it == *iter){
	result = true;
      }
      ++iter;
    }
    ++it;
  }
  return result;
  
}
