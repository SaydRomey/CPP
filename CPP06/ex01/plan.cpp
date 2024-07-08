
/*
Exercise : 01
Serialization
Turn-in directory : ex01/
Files to turn in : Makefile, *.cpp, *.{h, hpp}
Forbidden functions : None
Implement the following functions:
uintptr_t serialize(Data* ptr);
It takes a pointer and converts it to the unsigned integer type uintptr_t.
Data* deserialize(uintptr_t raw);
It takes an unsigned integer parameter and converts it to a pointer to Data.
Write a program to test that your functions works as expected.
You must create a non-empty (it means it has data members) Data structure.
Use serialize() on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value of deserialize() compares equal to the
original pointer.
Do not forget to turn in the files of your Data structure.
*/

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
	int id;
	std::string name;
	double value;

	Data(int id, const std::string& name, double value);
	void display() const;
};

#endif // DATA_HPP

#include "Data.hpp"
#include <iostream>

Data::Data(int id, const std::string& name, double value)
	: id(id), name(name), value(value) {}

void Data::display() const {
	std::cout << "Data { id: " << id << ", name: " << name << ", value: " << value << " }" << std::endl;
}

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstdint> // For uintptr_t
#include "Data.hpp"

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif // SERIALIZATION_HPP

#include "Serialization.hpp"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

#include <iostream>
#include "Data.hpp"
#include "Serialization.hpp"

int main() {
	// Create a Data object
	Data originalData(1, "Test", 3.14);
	originalData.display();

	// Serialize the pointer to Data
	uintptr_t serialized = serialize(&originalData);

	// Deserialize and obtain the pointer to Data
	Data* deserializedData = deserialize(serialized);

	// Display the deserialized data
	deserializedData->display();

	// Compare the original and deserialized pointers
	if (&originalData == deserializedData) {
		std::cout << "Serialization and deserialization successful!" << std::endl;
	} else {
		std::cout << "Serialization and deserialization failed!" << std::endl;
	}

	return 0;
}
