#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
	std::cout << "ICharacter default constructor" << std::endl;
}

ICharacter::ICharacter(const ICharacter &other)
{
	*this = other;
}

ICharacter&	ICharacter::operator=(const ICharacter &other)
{
	// if (this != &other)
	return (*this);
}

ICharacter::~ICharacter(void)
{
	std::cout << "ICharacter default destructor" << std::endl;
}
