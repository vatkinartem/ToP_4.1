#include "anyArray.h"
#include <malloc.h>
#include <iostream>
using namespace std;

/*by "any" i mean only int, char, float, double, char* */

template<typename Type>
anyArray<Type>::anyArray()
{
	int len = 0;
	this->arr = nullptr;
}

template<typename Type>
anyArray<Type>::anyArray(int lenght)
{
	int len = lenght;
	this->arr = new Type[len];
}

template<typename Type>
anyArray<Type>::anyArray(const anyArray& source)
{
	int len = source.len;
	this->arr = new Type[len];
	for (size_t i = 0; i < len; i++)
	{
		this->arr[i] = source.arr[i];
	}
}

template<typename Type>
anyArray<Type>::~anyArray()
{
	delete[] this->arr;
}

template<typename Type>
void anyArray<Type>::addElem(const Type &value)
{
	if (this->arr == nullptr)
	{
		this->arr = (Type*)calloc(1, sizeof(Type));
	}
	else {
		this->arr = (Type*)realloc(this->arr, sizeof(Type) + _msize(this->arr));
	}
	this->arr[this->len] = value;
	this->len++;
}

template<typename Type>
void anyArray<Type>::setError(exception exeption)
{
	this->error = exeption.what();
}

template<typename Type>
int anyArray<Type>::getLen()
{
	return this->len;
}

template<typename Type>
void anyArray<Type>::printArray()
{
	for (int i = 0; i < this->len; i++)
	{
		cout << this->arr[i] <<endl;
		printf(" ");
	}
	printf("\n");
}

template<typename Type>
bool anyArray<Type>::operator!=(const anyArray& source)
{
	if (this->len != source.len)
	{
		if (typeid(this->arr[1]).hash_code() != typeid(source.arr[1]).hash_code()) {
			return true;
		}
		for (int i = 0; i < this->len; i++)
		{
			if (this->arr[i] == source.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<typename Type>
bool anyArray<Type>::operator==(const anyArray& source)
{
	if (this->len == source.len)
	{
		if (typeid(this->arr[1]).hash_code() != typeid(source.arr[1]).hash_code()) {
			return false;
		}
		for (int i = 0; i < this->len; i++)
		{
			if (this->arr[i] != source.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<typename Type>
Type anyArray<Type>::operator[](int index)
{
	Type temp;
	temp = this->arr[index];

	return temp;
}
