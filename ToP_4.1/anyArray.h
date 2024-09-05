#pragma once
#include <stdexcept>
using namespace std;

template<typename Type>
class anyArray
{
private:
	int len;
	anyArray* arr;
public:
	anyArray();
	anyArray(int size);
	anyArray(const anyArray& source);
	~anyArray();
	void setError(exception exeption);
	void addElem(const Type &value);
	int getLen();
	void printArray();
	bool operator!=(const anyArray& value);
	bool operator==(const anyArray& value);
	Type operator[](int index);
	const exception error;
	//anyArray* operator new[](size_t count);
};

