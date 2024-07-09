
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
