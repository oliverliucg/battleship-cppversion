#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <unordered_set>

using std::unordered_set;
using std::pair;
using std::make_pair;

typedef pair<char, char> Point;
template<typename T>
class Ship{
protected:
    unordered_set<Point> points;
    Point upperLeft;
    T direction;
    int x;
public:
    Ship(Point _upperLeft, T _direction):upperLeft(_upperLeft), direction(_direction){}
};

template<typename T>
class RectangleShip: public Ship<T>{
protected:
    int height;
    int width;
public:
    RectangleShip(Point _upperLeft, char _direction, int _height, int _width):Ship<T>(_upperLeft, _direction), height(_height), width(_width){
        for(int r = 0; r < height; ++r){
            for(int l = 0; l < width; ++l){
                points.insert(make_pair((int)upperLeft.row+r, (int)upperLeft.col+l));
            }
        }
    }
};

// ** or *
//       *
template<typename T>
class Submarine: public RectangleShip<T>{
private:

public:
    Submarine(Point _upperLeft, T _direction):RectangleShip<T>(_upperLeft, _direction){
        
    }
};

// *** or *
//        *
//        *
template<typename T>
class Destroyer: public RectangleShip<T>{
private:

public:
    Destroyer(Point _upperLeft, T _direction):RectangleShip<T>(_upperLeft, _direction){
        
    }
};

