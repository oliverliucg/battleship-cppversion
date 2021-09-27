#include <string>
using std::string;

class Coordinate{
private:
    int row;
    int column;
public:
    Coordinate() : row(0), column(0){}
    Coordinate(int _row, int _column):row(_row),column(_column){}
    Coordinate(string descr);
    Coordinate(const Coordinate& other);
    Coordinate& operator=(const Coordinate& other);
    int getRow(){return row;}
    int getColumn(){return column;}
};

