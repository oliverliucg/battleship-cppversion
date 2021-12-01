#include "ordinary.h"

const string nameOfBattleship = "Battleship";
const string nameOfCarrier = "Carrier";
const string nameOfSubmarine = "Submarine";
const string nameOfDestroyer = "Destroyer";
std::unordered_map<char, std::string> accessToFullName{{tolower(nameOfBattleship[0]), nameOfBattleship},
                                                       {tolower(nameOfCarrier[0]),    nameOfCarrier},
                                                       {tolower(nameOfDestroyer[0]),  nameOfDestroyer},
                                                       {tolower(nameOfSubmarine[0]), nameOfSubmarine}};

int randomlyPickFrom(int a, int b) { return a + (int)(rand() * (b - a + 1)); }

vector<string> splitStringByCharacter(string s, char c) {
  stringstream ss(s);
  string segment;
  vector<string> res;
  while (getline(ss, segment, c)) {
    res.emplace_back(segment);
  }
  return res;
}

string strToUppercase(string s) {
  string res = "";
  for (const auto &c : s) {
    res += std::toupper(c);
  }
  return res;
}

string strToLowercase(string s) {
  string res = "";
  for (const auto &c : s) {
    res += std::tolower(c);
  }
  return res;
}