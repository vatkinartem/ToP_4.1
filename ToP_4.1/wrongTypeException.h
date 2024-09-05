#pragma once
#include <stdexcept>
using namespace std;

class wrongTypeException :
    public std::exception
{
private:

public:
    wrongTypeException(const char* msg);
    ~wrongTypeException();
};
