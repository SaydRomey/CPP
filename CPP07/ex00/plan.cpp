
/*
Exercise : 00
Start with a few functions
Turn-in directory : ex00/
Files to turn in : Makefile, main.cpp, whatever.{h, hpp}
Forbidden functions : None
Implement the following function templates:
• swap: Swaps the values of two given arguments. Does not return anything.
• min: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.
• max: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.
These functions can be called with any type of argument. The only requirement is
that the two arguments must have the same type and must support all the comparison
operators.
Templates must be defined in the header files.
Running the following code:
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
Should output:
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

// Template function to swap two values
template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

// Template function to find the minimum of two values
template <typename T>
T min(const T &a, const T &b) {
	return (b < a) ? b : a;
}

// Template function to find the maximum of two values
template <typename T>
T max(const T &a, const T &b) {
	return (a < b) ? b : a;
}

#endif // FUNCTIONS_HPP

#include <iostream>
#include <string>
#include "functions.hpp"

int main() {
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return 0;
}

//

// Template function to swap two values using XOR bitwise operation
template <typename T>
void swap(T &a, T &b) {
	if (&a == &b) // No need to swap if both references point to the same object
		return;

	a ^= b;
	b ^= a;
	a ^= b;
}

// or

// Template function to swap two values using addition and subtraction
template <typename T>
void swap(T &a, T &b) {
	if (&a == &b) // No need to swap if both references point to the same object
		return;

	a = a + b; // Add a and b, store the result in a
	b = a - b; // Subtract b from the new value of a, store the result in b
	a = a - b; // Subtract the new value of b from the updated value of a, store the result in a
}



