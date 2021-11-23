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

const string nameOfBattleship = "Battleship";
const string nameOfCarrier = "Carrier";
const string nameOfSubmarine = "Submarine";
const string nameOfDestroyer = "Destroyer";

#endif // BATTLESHIP_CPPVERSION_ORDINARY_H