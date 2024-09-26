#ifndef BATTLESHIP_CPPVERSION_RECTANGLESHIP_H
#define BATTLESHIP_CPPVERSION_RECTANGLESHIP_H

#include "BasicShip.h"
#include "SimpleShipDisplayInfo.h"

template<typename T>
class RectangleShip : public BasicShip<T> {
protected:
    static vector<Coordinate> makeCoords(Coordinate upperLeft, int width,
                                         int height);

public:
    RectangleShip(string _name, Coordinate _upperLeft, int width, int height,
                  std::shared_ptr<SimpleShipDisplayInfo<T>> myDisplayInfo,
                  std::shared_ptr<SimpleShipDisplayInfo<T>> enemyDisplayInfo);

    RectangleShip(string _name, Coordinate _upperLeft, int width, int height, std::shared_ptr<T> data,
                  std::shared_ptr<T> onHit);
};

template<typename T>
vector<Coordinate> RectangleShip<T>::makeCoords(Coordinate upperLeft, int width,
                                                int height) {
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
RectangleShip<T>::RectangleShip(
        string _name, Coordinate _upperLeft, int width, int height,
        std::shared_ptr<SimpleShipDisplayInfo<T>> myDisplayInfo,
        std::shared_ptr<SimpleShipDisplayInfo<T>> enemyDisplayInfo)
        : BasicShip<T>(_name, _upperLeft, makeCoords(_upperLeft, width, height),
                       myDisplayInfo, enemyDisplayInfo) {}

template<typename T>
RectangleShip<T>::RectangleShip(string _name, Coordinate _upperLeft, int width, int height,
                                std::shared_ptr<T> data, std::shared_ptr<T> onHit)
        : RectangleShip<T>(_name, _upperLeft, width, height,
                           std::make_shared<SimpleShipDisplayInfo<T>>(data, onHit),
                           std::make_shared<SimpleShipDisplayInfo<T>>(nullptr, data)) {}

#endif // BATTLESHIP_CPPVERSION_RECTANGLESHIP_H