//#include "Ship.hpp"
#include <utility>
#include <vector>
#include <set>
#include "Point.hpp"
#include <iostream>
using namespace std;
class Board{
 private:
  int width;
  int height;
  //std::vector<Ship>;
  std::set<pair<char,char> > miss;
 public:
  int getWidth(){
    return width;
  }
  int getHeight(){
    return height;
  }
  Board():width(10),height(20){};
  Board(int w, int d):width(w),height(d){};
  void fireShip(Point targetPoint);
  void moveShip(Point targetPoint);
  void getShip(Point targetPoint);
};

void show(Board myself, Board other,bool isOnlyMyself);
