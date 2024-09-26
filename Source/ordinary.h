#ifndef BATTLESHIP_CPPVERSION_ORDINARY_H
#define BATTLESHIP_CPPVERSION_ORDINARY_H

#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using std::getline;
using std::string;
using std::stringstream;
using std::vector;
using std::unordered_map;

int randomlyPickFrom(int a, int b);

vector<string> splitStringByCharacter(string s, char c);

string strToUppercase(string s);

string strToLowercase(string s);

extern const string nameOfBattleship;
extern const string nameOfCarrier;
extern const string nameOfSubmarine;
extern const string nameOfDestroyer;

extern std::unordered_map<char, std::string> accessToFullName;
#endif // BATTLESHIP_CPPVERSION_ORDINARY_H