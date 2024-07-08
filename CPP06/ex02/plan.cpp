
/*
Exercise : 02
Identify real type
Turn-in directory : ex02/
Files to turn in : Makefile, *.cpp, *.{h, hpp}
Forbidden functions : std::typeinfo
Implement a Base class that has a public virtual destructor only. Create three empty
classes A, B and C, that publicly inherit from Base.
These four classes don’t have to be designed in the Orthodox
Canonical Form.
Implement the following functions:
Base * generate(void);
It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base& p);
It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.
Including the typeinfo header is forbidden.
Write a program to test that everything works as expected.
*/

#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
	virtual ~Base() {}
};

class A : public Base {
	// A specific implementation can be added if needed
};

class B : public Base {
	// B specific implementation can be added if needed
};

class C : public Base {
	// C specific implementation can be added if needed
};

#endif // BASE_HPP

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"

Base * generate();
void identify(Base* p);
void identify(Base& p);

#endif // FUNCTIONS_HPP

#include "Functions.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

Base * generate() {
	// Initialize random seed
	std::srand(static_cast<unsigned int>(std::time(0)));

	// Generate a random number between 0 and 2
	int randomNum = std::rand() % 3;

	// Instantiate and return a random object of type A, B, or C
	switch (randomNum) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr; // Should never happen due to modulo operation
	}
}

void identify(Base* p) {
	// Check the actual type of the object pointed to by p
	// Use dynamic_cast to perform the type check
	if (dynamic_cast<A*>(p) != nullptr) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p) != nullptr) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p) != nullptr) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	// Call the identify(Base*) function using the address of p
	identify(&p);
}

#include <iostream>
#include "Functions.hpp"

int main() {
	// Generate a random object of type A, B, or C
	Base* obj = generate();

	// Identify the type of the object using pointer and reference
	identify(obj);
	identify(*obj);

	// Clean up memory
	delete obj;

	return 0;
}

/*
Base Class and Derived Classes: Base serves as the base class with a virtual destructor, and A, B, and C are derived classes inheriting publicly from Base.

Function generate(): Randomly generates an instance of A, B, or C and returns it as a Base*.

Functions identify(Base* p) and identify(Base& p):

identify(Base* p): Checks the dynamic type of the object pointed to by p using dynamic_cast and prints "A", "B", or "C".
identify(Base& p): Calls identify(Base*) using the address of p.
Testing: In main(), we generate a random object, identify its type using both pointer and reference forms of identify(), and then clean up the dynamically allocated memory.

Notes:
dynamic_cast: Used for runtime type identification without using std::typeinfo. It returns nullptr if the cast is not possible.
*/
