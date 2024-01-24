#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	std::cout << "IMateriaSource default constructor" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
	*this = other;
}

IMateriaSource&	IMateriaSource::operator=(const IMateriaSource &other)
{
	// if (this != &other)
	return (*this);
}

IMateriaSource::~IMateriaSource(void)
{
	std::cout << "IMateriaSource default destructor" << std::endl;
}
