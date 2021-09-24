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
  Board():width(3),height(3){};
  void fireShip(Point targetPoint);
  void moveShip(Point targetPoint);
  void getShip(Point targetPoint);
};
