#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include "anyArray.h"
#include "myExceptions.h"
#define MAXARRAYLENGHT 15
using namespace std;

namespace myNSForFunc {
	enum comForFunc
	{
		DEFAULT_C = -1,
		HELP = 0,
		ARRAY,
		FUNC,
		EXIT
	};
	enum typeOfElem
	{
		DEFAULT_T = -1,
		INT = 1,
		CHAR = 2,
		FLOAT = 3,
		DOUBLE = 4,
		STRING = 5,
	};

	enum idOfTypes
	{
		DEFAULT_ID = -1,
		INT_ID = 1,
		CHAR_ID = 2,
		FLOAT_ID = 3,
		DOUBLE_ID = 4,
		STRING_ID = 5,
	};
}

using namespace myNSForFunc;

template <typename T>
int* fill_find_array(const int arraySize) {
	int* result = new int[1];
	memset(result, 0, _msize(result));
	result[0] = -1;
	T* arr = new T[arraySize];
	memset(arr, 0, _msize(arr));
	int currLen = 0;
	int key_count = 0;
	int tempIndex = 0;
	T value = T();
	T key = T();

	/*part where adding elements happenning*/
	printf("Input %d elements\n", arraySize);
	while (currLen != arraySize)
	{
		try
		{
			cin >> value;
			if (cin.fail())
			{
				throw exception("Exception. Can`t parse input value.\n");
			}
			arr[currLen] = value;
			currLen++;
		}
		catch (const std::exception& someException)
		{
			printf("%s\n", someException.what());
		}

	}

	cin.clear();

	/* find by key part (stupid but works)*/
	cout << "Input key to find indexes\n" << endl;
	try
	{
		cin >> key;
		if (cin.fail())
		{
			throw exception("Exception. Can`t parse input value.\n");
		}
	}
	catch (const std::exception& someException)
	{
		printf("%s\n", someException.what());
	}

	/*counting found equals by key*/
	if (typeid(T).hash_code() == typeid(char*).hash_code())
	{
		for (int i = 0; i < arraySize; i++)
			if (arr[i] == key) /*there had to be !strcmp(arr[i]), key) but hsn`t worked */ {
				key_count++;
			}
	}
	else
	{
		for (int i = 0; i < arraySize; i++)
			if (arr[i] == key) {
				key_count++;
			}
	}
	result = (int*)calloc(key_count, sizeof(int));
	/* now writing indexes*/
	if (typeid(T).hash_code() == typeid(char*).hash_code())
	{
		for (int i = 0; i < arraySize; i++)
			if (arr[i] == key) {
				result[i] = i;
			}
	}
	else
	{
		for (int i = 0; i < arraySize; i++)
			if (arr[i] == key) {
				result[tempIndex] = i;
				tempIndex++;
			}
	}

	delete[] arr;
	return result;
}

int* inputUndefinedTypeArray(const int arraySize, const myNSForFunc::typeOfElem type) {
	int temp[1] = { -1 };

	switch (type)
	{
	case myNSForFunc::DEFAULT_T:
		return temp;
		break;
	case myNSForFunc::INT:
		return fill_find_array<int>(arraySize);
		break;
	case myNSForFunc::CHAR:
		return fill_find_array<char>(arraySize);
		break;
	case myNSForFunc::FLOAT:
		return fill_find_array<float>(arraySize);
		break;
	case myNSForFunc::DOUBLE:
		return fill_find_array<double>(arraySize);
		break;
	case myNSForFunc::STRING:
		printf("I tried...\n");
		return temp; //fill_find_array<char*>(arraySize);
		break;
	default:
		return temp;
		break;
	}
	return temp;
}

void start() {
	myNSForFunc::typeOfElem typeElem = myNSForFunc::typeOfElem::DEFAULT_T;
	double hashOfChosenType = 0;
	int* output_array = nullptr;

	do
	{
		typeElem = myNSForFunc::typeOfElem::DEFAULT_T;
		int arraySize = 0;
		try
		{
			printf("Input type of array ( int -> 1, char -> 2, float -> 3, double -> 4, string -> 5 )\n");
			if (scanf_s("%d", &typeElem) == 0)
			{
				throw NonNumericInputException("Exception. Non integer input found in type input option.\n");
			}
			if ((typeElem < myNSForFunc::typeOfElem::INT) or (typeElem > myNSForFunc::typeOfElem::STRING))
			{
				throw exception("There-is-no-such-a-type-exception\n");
			}

			printf("Input size of array\n");
			if (scanf_s("%d", &arraySize) == 0)
			{
				throw NonNumericInputException("Exception. Non integer input found in type input option.\n");
			}
			if (arraySize <= 0)
			{
				char c;
				do
				{
					c = getc(stdin);
				} while ((c != EOF) and (c != '\n'));
				throw exception("Can`t create array with this size\n");
			}

			output_array = inputUndefinedTypeArray(arraySize, typeElem);

			printf("Answer: ");
			for (int i = 0; i < _msize(output_array) / sizeof(int); i++)
			{
				printf("%d ", output_array[i]);
			}
			printf("\n");

			break;
		}
		catch (const NonNumericInputException& MetNonNumericExeption)
		{
			char c;
			do
			{
				c = getc(stdin);
			} while ((c != EOF) and (c != '\n'));
			printf("%s\n", MetNonNumericExeption.what());
		}
		catch (const std::exception& someException)
		{
			printf("%s\n", someException.what());
			continue;
		}

	} while (true);

}

/*
1. вначале выбрать тип данных
2. затем размер
3. выделение памяти в соответсвии с введённым типом
4. запрос на введение ключа
5. получение массива с индексами
6. вывод массива с индексами
*/

int main(void) {
	comForFunc comFunc = comForFunc::DEFAULT_C;

	printf("%d - help.\n", comForFunc::HELP);

	// to repeat bug
	/*anyArray<int> a;
	a.addElem(1);a.addElem(2);a.addElem(3);
	a.printArray();*/ 


	do
	{
		comFunc = comForFunc::DEFAULT_C;
		printf("\nAwaiting comand number...\n");
		try
		{
			if (scanf_s("%d", &comFunc) == 0)
			{
				throw NonNumericInputException("Exception. Non Numeric input found in command input option.\n");
			};

			switch (comFunc)
			{
			case myNSForFunc::HELP:
				printf("%d - help.\n%d - initialise array.\n%d - activating function that returns array of index of element that equal to key.\n%d - exit.\n", \
					comForFunc::HELP, comForFunc::ARRAY, comForFunc::FUNC, comForFunc::EXIT);
				break;
			case myNSForFunc::FUNC:
				start();
				break;
			case myNSForFunc::ARRAY:
				// there had to be displaying of working array but it crashes if i use addElem in anyArray or any otherr element, LNK2019.
				break;
			case myNSForFunc::EXIT:
				break;
			default:
				printf("Invalid command.\n");
				break;
			}
		}
		catch (const NonNumericInputException& MetNonNumericExeption)
		{
			char c;
			do
			{
				c = getc(stdin);
			} while ((c != EOF) and (c != '\n'));
			printf("%s\n", MetNonNumericExeption.what());
		}
		catch (const exception& ex)
		{
			printf("%s\n", ex.what());
		}

	} while (comFunc != comForFunc::EXIT);

};
