
#ifndef ARRAYEXCEPTION_HPP
#define ARRAYEXCEPTION_HPP

#include <exception>
#include <string>

class ArrayException : public std::exception {
private:
    std::string m_message;

public:
    explicit ArrayException(const std::string &message) : m_message(message) {}

    virtual const char *what() const noexcept override {
        return m_message.c_str();
    }
};

class IndexOutOfBoundsException : public ArrayException {
public:
    IndexOutOfBoundsException() : ArrayException("Index out of bounds") {}
};

#endif // ARRAYEXCEPTION_HPP
