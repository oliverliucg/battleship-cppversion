#include "ordinary.h"

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