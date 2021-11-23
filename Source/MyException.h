#ifndef BATTLESHIP_CPPVERSION_MYEXCEPTION_H
#define BATTLESHIP_CPPVERSION_MYEXCEPTION_H

#include <exception>
#include <string>
using std::exception;
using std::string;

class MyException : public exception {
private:
  string message;

public:
  MyException(const string &_message) : message(_message + "\n") {}
  const char *what() const noexcept override { return message.c_str(); }
};

#endif // BATTLESHIP_CPPVERSION_MYEXCEPTION_H