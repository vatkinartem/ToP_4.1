#pragma once
#include <stdexcept>
using namespace std;

class unEvenTypesException :
    public std::exception
{
private:

public:
    unEvenTypesException(const char* msg);
    ~unEvenTypesException();
};