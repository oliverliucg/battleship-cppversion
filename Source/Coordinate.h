
#ifndef BATTLESHIP_CPPVERSION_COORDINATE_H
#define BATTLESHIP_CPPVERSION_COORDINATE_H
#include <string>
using std::string;

class Coordinate {
private:
  int row;
  int column;

public:
  Coordinate() : row(0), column(0) {}
  Coordinate(int _row, int _column) : row(_row), column(_column) {}
  Coordinate(string descr);
  Coordinate(const Coordinate &other);
  Coordinate &operator=(const Coordinate &other);
  int getRow() const{ return row; }
  int getColumn() const{ return column; }
  string toString();
  int toHashCode();
  friend bool operator==(const Coordinate &lhs, const Coordinate &rhs);
  friend bool operator<(const Coordinate &lhs, const Coordinate &rhs);
};

#endif // BATTLESHIP_CPPVERSION_COORDINATE_H