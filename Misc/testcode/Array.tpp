
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
        throw IndexOutOfBoundsException(); // Throw custom exception
    }
    return m_data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= m_size) {
        throw IndexOutOfBoundsException(); // Throw custom exception
    }
    return m_data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return m_size;
}

#endif // ARRAY_TPP
