#include "Ship.hpp"
#include <vector>
#include <set>
#include <pair>
#include "Point.hpp"
class Board{
 private:
  int width;
  int height;
  std::vector<Ship>;
  std::set<pair<char,char>>;
 public:
  Board():width(10),height(20){};
  Board(int w, int d):width(w),height(d){};
  void fireShip(Point targetPoint){
    
  };
  void moveShip(Point targetPoint){

  };
  void getShip(Point targetPoint){

  };
};

void show(Board myself, Board other){
  if(other != NULL){
    
  }else{
    //print myself
    
    
  }
}
