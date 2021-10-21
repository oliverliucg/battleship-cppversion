#ifndef BATTLESHIP_CPPVERSION_ORDINARY_H
#define BATTLESHIP_CPPVERSION_ORDINARY_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;
using std::getline;

int randomlyPickFrom(int a, int b);

vector<string> splitStringByCharacter(string s, char c);

string strToUppercase(string s);

string strToLowercase(string s);

#endif //BATTLESHIP_CPPVERSION_ORDINARY_H