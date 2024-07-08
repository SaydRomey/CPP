
/*
Exercise : 01
Iter
Turn-in directory : ex01/
Files to turn in : Makefile, main.cpp, iter.{h, hpp}
Forbidden functions : None
Implement a function template iter that takes 3 parameters and returns nothing.
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be call on every element of the array.
Turn in a main.cpp file that contains your tests. Provide enough code to generate a
test executable.
Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.
*/

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

#endif // ITER_HPP

/*
Template Definition:

template <typename T>: Defines a template function where T is the type of elements in the array.
Function Parameters:

T *array: Pointer to the array of type T.
size_t length: Length of the array.
void (*func)(T &): Pointer to a function that takes a reference to T and returns void. This function will be applied to each element of the array.
Iteration and Function Application:

The iter function iterates through each element of the array using a simple for loop.
For each element array[i], it calls the function func with array[i] as an argument.
*/

#include <iostream>
#include "iter.hpp"

// Example function to print elements of an array
template <typename T>
void printElement(T &elem) {
	std::cout << elem << " ";
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

	// Using iter with an array of integers and printElement function
	std::cout << "Printing integers: ";
	iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	// Using iter with an array of doubles and printElement function
	std::cout << "Printing doubles: ";
	iter(doubleArray, doubleArraySize, printElement<double>);
	std::cout << std::endl;

	return 0;
}
