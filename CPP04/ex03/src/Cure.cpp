#include "Cure.hpp"

Cure::Cure(void)
{
	std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(const Cure &other)
{
	*this = other;
}

Cure&	Cure::operator=(const Cure &other)
{
	// if (this != &other)
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure default destructor" << std::endl;
}
