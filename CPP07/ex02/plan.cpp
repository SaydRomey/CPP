
/*
Exercise : 02
Array
Turn-in directory : ex02/
Files to turn in : Makefile, main.cpp, Array.{h, hpp}
and optional file: Array.tpp
Forbidden functions : None
Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
• Construction with no parameter: Creates an empty array.
• Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.
• Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
• You MUST use the operator new[] to allocate memory. Preventive allocation (al-
locating memory in advance) is forbidden. Your program must never access non-
allocated memory.
• Elements can be accessed through the subscript operator: [ ].
• When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
• A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance.
As usual, ensure everything works as expected and turn in a main.cpp file that con-
tains your tests.
*/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // For std::exception

template <typename T>
class Array {
private:
	T *m_data;          // Pointer to the dynamically allocated array
	unsigned int m_size; // Size of the array

public:
	// Constructors
	Array();                    // Default constructor
	explicit Array(unsigned int n); // Parameterized constructor
	Array(const Array<T> &other); // Copy constructor

	// Destructor
	~Array();

	// Assignment operator
	Array<T> &operator=(const Array<T> &other);

	// Access operators
	T &operator[](unsigned int index); // Subscript operator
	const T &operator[](unsigned int index) const; // Subscript operator for const objects

	// Member function
	unsigned int size() const; // Returns the size of the array
};

#include "Array.tpp" // Include template definitions

#endif // ARRAY_HPP

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_data(nullptr), m_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : m_data(new T[n]), m_size(n) {}

template <typename T>
Array<T>::Array(const Array<T> &other) : m_data(nullptr), m_size(0) {
	*this = other; // Use assignment operator to perform deep copy
}

template <typename T>
Array<T>::~Array() {
	delete[] m_data; // Free dynamically allocated memory
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		// Delete current data
		delete[] m_data;

		// Allocate new memory
		m_size = other.m_size;
		m_data = new T[m_size];

		// Copy elements
		for (unsigned int i = 0; i < m_size; ++i) {
			m_data[i] = other.m_data[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= m_size) {
		throw std::out_of_range("Index out of range");
	}
	return m_data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= m_size) {
		throw std::out_of_range("Index out of range");
	}
	return m_data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return m_size;
}

#endif // ARRAY_TPP

/*
Array Class Template (Array.hpp):

Private Members: m_data for storing the array elements and m_size for tracking the number of elements.

Public Member Functions:

Constructors: Default constructor (Array()), parameterized constructor (Array(unsigned int n)), and copy constructor (Array(const Array<T> &other)).
Destructor: Releases dynamically allocated memory (~Array()).
Assignment Operator: Performs deep copy (operator=).
Subscript Operator (operator[]): Allows accessing elements of the array. Throws std::out_of_range if the index is out of bounds.
Size Function (size()): Returns the number of elements in the array.
Array Template Definitions (Array.tpp):

Defines the implementations of the member functions declared in Array.hpp.
*/

#include <iostream>
#include "Array.hpp"

int main() {
	// Test default constructor
	Array<int> intArrayDefault;
	std::cout << "Default Array size: " << intArrayDefault.size() << std::endl;

	// Test parameterized constructor
	Array<double> doubleArray(5);
	for (unsigned int i = 0; i < doubleArray.size(); ++i) {
		doubleArray[i] = i * 1.5;
	}
	std::cout << "Double Array elements:" << std::endl;
	for (unsigned int i = 0; i < doubleArray.size(); ++i) {
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;

	// Test copy constructor and assignment operator
	Array<double> doubleArrayCopy(doubleArray);
	std::cout << "Copy of Double Array elements:" << std::endl;
	for (unsigned int i = 0; i < doubleArrayCopy.size(); ++i) {
		std::cout << doubleArrayCopy[i] << " ";
	}
	std::cout << std::endl;

	// Modify original array and check copy
	doubleArray[0] = 99.9;
	std::cout << "Modified Double Array elements:" << std::endl;
	for (unsigned int i = 0; i < doubleArray.size(); ++i) {
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Copy of Double Array after modification:" << std::endl;
	for (unsigned int i = 0; i < doubleArrayCopy.size(); ++i) {
		std::cout << doubleArrayCopy[i] << " ";
	}
	std::cout << std::endl;

	// Exception handling - Index out of bounds
	try {
		std::cout << "Accessing out of bounds index:" << std::endl;
		std::cout << doubleArray[10] << std::endl; // This should throw an exception
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
