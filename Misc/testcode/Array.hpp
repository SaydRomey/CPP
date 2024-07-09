
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // Remove this line as we are using custom exceptions
#include "ArrayException.hpp" // Include custom exception header

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
