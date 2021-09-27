#include <string>
#include <exception>
using std::exception;
using std::string;

class MyException : public exception
{   
private:
    /* data */
    const char* exceptionMessage;
public:
    MyException(const char* _exceptionMessage) : exceptionMessage(_exceptionMessage){}
    const char* what() const throw() {
        return exceptionMessage;
    }
};
