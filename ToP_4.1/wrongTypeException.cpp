#include "wrongTypeException.h"

wrongTypeException::wrongTypeException(const char* msg) : exception(msg)
{
}

wrongTypeException::~wrongTypeException()
{
}