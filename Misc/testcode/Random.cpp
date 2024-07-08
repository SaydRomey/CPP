/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:24:47 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/07 18:34:06 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Random.hpp"

// Static member initialization
unsigned long	Random::_seed = 0;

/* ************************************************************************** */ // Functions / Methods

// Initializes the random seed using a local variable adress
void	Random::seed(void)
{
	if (_seed == 0)
	{
		int	var;
		_seed = reinterpret_cast<unsigned long>(&var);
	}
}

// Initializes the random seed using current time
void	Random::trueSeed(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	_seed = std::rand();
}

// LCG based random integer in range [min, max]
int	Random::randomInt(int min, int max)
{
	seed();
	
	_seed = _seed * LCG_MULT + LCG_INCR;
	int	range = max - min - 1;
	int	random_int = ((_seed / LCG_DIV) % range) + min;
	
	return (random_int);
}

// Generates a random boolean with given percentage of returning true
bool	Random::chance(int percentage)
{
	seed();
	
	int	random_value = randomInt(1, 100);

	return (random_value <= percentage);
}

// Generates a random bool (true or false)
bool	Random::randomBool(void)
{
	seed();

	return (randomInt(0, 2) == 1);
}

// Generates a random floating-point number between 0 and 1
float	Random::randomFloat(void)
{
	seed();
	
	return (static_cast<float>(randomInt(0, RAND_MAX)) / RAND_MAX);
}

// Shuffle elements of an array using the Fisher-Yates shuffle algorithm
template <typename T, size_t N>
void	Random::shuffleArray(T (&array[N]))
{
	seed();
	
	size_t	i = N - 1;
	while (i > 0)
	{
		size_t	j = randomInt(0, i + 1);
		std::swap(array[i], array[j]);
		i--;
	}
}

// Return a random element from an array
template <typename T, size_t N>
T	Random::randomElement(const T (&array[N]))
{
	seed();
	
	return (array[randomInt(0, N)]);
}

std::string	Random::randomString(size_t length)
{
	static const char	alphanum[] = \
		"0123456789"
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	seed();
	std::string	str;
	str.reserve(length);
	size_t	i = 0;
	while (i < length)
	{
		str += alphanum[randomInt(0, sizeof(alphanum) - 2)];
		i++;
	}
	return (str);
}

// Generate random password
static std::string	Random::randomPassword(size_t length, bool useLowercase, bool useUppercase, bool useDigits, bool useSymbols);
{
	seed();
	const std::string	lowercase = "abcdefghijklmnopqrstuvwxyz";
	const std::string	uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const std::string	digits = "0123456789";
	const std::string	symbols = "!@#$%^&*()_+{}[]";
	
	std::string	charset;
	if (useLowercase)
		charset += lowercase;
	if (useUppercase)
		charset += uppercase;
	if (useDigits)
		charset += digits;
	if (useSymbols)
		charset += symbols;

	std::string	password;
	password.reserve(length);
	size_t	i = 0;
	while (i < length)
	{
		password += charset[randomInt(0, charset.length())];
		i++;
	}
	return (password);
}

// Generate a random RGB color
Random::Color	Random::randomColor(void)
{
	seed();
	return ({ \
		static_cast<unsigned int>(randomInt(0, 256)),
		static_cast<unsigned int>(randomInt(0, 256)),
		static_cast<unsigned int>(randomInt(0, 256)) });
}

// Generates a random point in 2D space
Random::Point	Random::randomPoint(int minX, int minY, int maxX, int maxY)
{
	seed();
	return ({ randomInt(minX, maxX), randomInt(minY, maxY) });
}

/* ************************************************************************** */ // Constructors / Destructors

// Random::Random(void)
// {
// 	// Default constructor
// 	seed();
// }

// Random::Random(const Random &other)
// {
// 	// Copy constructor
// 	_seed = other._seed;
// }

// Random::~Random(void)
// {
// 	// Default destructor
// }

/* ************************************************************************** */ // Operators

// Random& Random::operator=(const Random &other)
// {
// 	// Copy assignment operator
// 	if (this != &other)
// 	{
// 		_seed = other._seed;
// 	}
// 	return (*this);
// }

/* ************************************************************************** */
/*
#include <iostream>
#include "Random.hpp"

int	main(void)
{
	Random::seed();

	// Generate a random value between 1 and 10
	int		random_value = Random::randomInt(1, 10);
	std::cout << "Randomized value: " << random_val << std::endl;

	// Simulate a 30% chance of success
	bool	success = Random::chance(30);
	if (success)
		std::cout << "Success" << std::endl;
	else
		std::cout << "Failure" << std::endl;

	return (0);
}
*/
