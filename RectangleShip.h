#ifndef BATTLESHIP_CPPVERSION_RECTANGLESHIP_H
#define BATTLESHIP_CPPVERSION_RECTANGLESHIP_H

#include "BasicShip.h"
#include "SimpleShipDisplayInfo.h"

template<typename T>
class RectangleShip: public BasicShip<T>{
protected:
  static vector<Coordinate> makeCoords(Coordinate upperLeft, int width, int height);

public:
  RectangleShip(Coordinate _upperLeft, int width, int height,
             std::unique_ptr<SimpleShipDisplayInfo<T> > myDisplayInfo,
             std::unique_ptr<SimpleShipDisplayInfo<T> > enemyDisplayInfo);
  RectangleShip(Coordinate _upperLeft, int width, int height, T data,
             T onHit);
  static const vector<string> names;
};

template<typename T>
const vector<string> RectangleShip<T>::names{"Submarine", "Destroyer"};

template <typename T>
vector<Coordinate> RectangleShip<T>::makeCoords(Coordinate upperLeft, int width, int height){
  vector<Coordinate> res;
  int startRow = upperLeft.getRow();
  int startColumn = upperLeft.getColumn();
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      res.emplace_back(Coordinate(startRow + i, startColumn + j));
    }
  }
  return res; 
}
template<typename T>
RectangleShip<T>:: RectangleShip(Coordinate _upperLeft, int width, int height,
             std::unique_ptr<SimpleShipDisplayInfo<T> > myDisplayInfo,
             std::unique_ptr<SimpleShipDisplayInfo<T> > enemyDisplayInfo):BasicShip<T>(_upperLeft, makeCoords(_upperLeft, width, height),
                                                                                       std::move(myDisplayInfo),
                                                                                       std::move(enemyDisplayInfo)){
               
             }

template<typename T>
RectangleShip<T>::RectangleShip(Coordinate _upperLeft, int width, int height, T data,
             T onHit):RectangleShip<T>(_upperLeft, width, height,
                                       std::make_unique<SimpleShipDisplayInfo<T> >(data, onHit),
                                       std::make_unique<SimpleShipDisplayInfo<T> >(T(), data)){}


#endif //BATTLESHIP_CPPVERSION_RECTANGLESHIP_H