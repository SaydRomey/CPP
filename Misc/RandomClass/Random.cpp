/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:24:47 by cdumais           #+#    #+#             */
/*   Updated: 2025/01/09 10:37:18 by cdumais          ###   ########.fr       */
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
	if (min > max)
	{
		throw (std::invalid_argument("randomInt: min cannot be greater than max"));
	}
	seed();
	
	_seed = _seed * LCG_MULT + LCG_INCR;
	int	range = max - min + 1;
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
	
	return (static_cast<float>(randomInt(0, 10000)) / 10000.0f);
}

// Shuffle elements of an array using the Fisher-Yates shuffle algorithm
template <typename T, size_t N>
void	Random::shuffleArray(T (&array[N]))
{
	seed();
	
	size_t	i = N - 1;
	while (i > 0)
	{
		size_t	j = static_cast<size_t>(randomInt(0, static_cast<int>(i + 1)));
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

/*	*!! TOCHECK:
Might work with both arrays and allocated memory...

ex:
int arr[] = {1, 2, 3, 4, 5};
int size = sizeof(arr) / sizeof(arr[0]);
int element = Random::randomElement(arr, size);
*/
// template <typename T>
// T	Random::randomElement(const T *array, size_t size)
// {
// 	seed();
	
// 	return (array[randomInt(0, size)]);
// }

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
std::string	Random::randomPassword(size_t length, bool useLowercase, bool useUppercase, bool useDigits, bool useSymbols);
{
	if (length == 0)
		throw (std::invalid_argument("randomPassword: Length must be greater than 0"));
	
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

	if (charset.empty())
		throw (std::invalid_argument("randomPassword: No character sets selected"));
	

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

// Generates a random procedural name
std::string	Random::randomName(int minLength, int maxLength)
{
	const std::string	consonants = "bcdfghjklmnpqrstvwxyz";
	const std::string	vowels = "aeiou";

	int	length = randomInt(minLength, maxLength);
	std::string	name;

	bool startWithConsonant = randomBool();
	for (int i = 0; i < length; ++i)
	{
		if (startWithConsonant)
			name += consonants[randomInt(0, consonants.size() - 1)];
		else
			name += vowels[randomInt(0, vowels.size() - 1)];
		startWithConsonant = !startWithConsonant;
	}

	name[0] = std::toupper(name[0]); // Capitalize the first letter
	return (name);
}



// Generate a random RGB color
Random::Color	Random::randomColor(void)
{
	seed();
	return (Color{static_cast<unsigned int>(randomInt(0, 256)),
				  static_cast<unsigned int>(randomInt(0, 256)),
				  static_cast<unsigned int>(randomInt(0, 256))});
}

/*
Generates a random color palette

'count' : The number of colors in the palette

Returns a vector of Coolors representing the palette
*/
std::vector<Random::Color>	Random::randomColorPalette(int count)
{
	std::vector<Color>	palette;
	
	int	i = 0;
	while (i < count)
	{
		palette.push_back(randomColor());
		++i;
	}
	return (palette);
}

// Generates a random point in 2D space
Random::Point	Random::randomPoint(int minX, int minY, int maxX, int maxY)
{
	seed();
	return (Point{randomInt(minX, maxX), randomInt(minY, maxY)});
}

Random::Time	Random::randomTime(void)
{
	return (Time{randomInt(0, 23), randomInt(0, 59), randomInt(0, 59)});
}

Random::Date	Random::randomDate(int startYear, int endYear)
{
	int	year = randomInt(startYear, endYear);
	int	month = randomInt(1, 12);
	int	day;

	if (month == 2) // Handle February (no leap year support for simplicity)
		day = randomInt(1, 28);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		day = randomInt(1, 30);
	else
		day = randomInt(1, 31);

	return (Date{year, month, day});
}

int	Random::rollDie(int faces)
{
	if (faces < 1)
		throw (std::logic_error("rollDie: Number of faces must be greater than 0"));
	
	return (randomInt(1, faces));
}

int	Random::rollDice(int faces, int count)
{
	if (faces < 1)
		throw (std::logic_error("rollDice: Number of faces must be greater than 0"));
	if (count < 1)
		throw (std::logic_error("rollDice: Number of dice must be greater than 0"));
	
	int	total = 0;
	int	i = 0;

	while (i < count)
	{
		total += rollDie(faces);
		++i;
	}
	return (total);

}


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

/*	random int:

try
{
	// Normal range
	int	value = Random::randomInt(1, 10);
	std::cout << "Random value between 1 and 10: " << value << std::endl;

	// Edge case: min == max
	value = Random::randomInt(5, 5);
	std::cout << "Random value between 5 and 5: " << value << std::endl;

	// Edge case: min > max
	value = Random::randomInt(10, 5);
}
catch (const std::invalid_argument& e)
{
	std::cerr << e.what() << std::endl;
}
*/

/*	shufflwArray

int		arr[] = {1, 2, 3, 4, 5};
size_t	size = sizeof(arr) / sizeof(arr[0]);

Random::shuffleArray(arr);

std::cout << "Shuffled array: ";
for (size_t i = 0; i < size; ++i)
	std::cout << arr[i] << " ";
std::cout << std::endl;
*/

/*	random element:

try
{
	int		arr[] = {10, 20, 30, 40, 50};
	size_t	size = sizeof(arr) / sizeof(arr[0]);

	// Edge case: Normal usage
	int	element = Random::randomElement(arr, size);
	std::cout << "Random element: " << element << std::endl;

	// Edge case: Empty array
	int	emptyArr[0];
	size = 0;
	element = Random::randomElement(emptyArr, size);
}
catch (const std::out_of_range& e)
{
	std::cerr << e.what() << std::endl;
}
*/

/*	random password:

try
{
	std::string	password = Random::randomPassword(10, true, true, true, true);
	std::cout << "Random password: " << password << std::endl;

	// Edge case: Invalid length
	password = Random::randomPassword(0, true, true, true, true);
	std::cout << "Password of length 0: " << password << std::endl;
}
catch (const std::invalid_argument& e)
{
	std::cerr << e.what() << std::endl;
}
*/

/*	rollDie and rollDice

try
{
	std::cout << "Rolling a 6-sided die: " << Random::rollDie(6) << std::endl;

	// Edge case: Invalid number of faces
	std::cout << "Rolling a die with 0 faces: " << Random::rollDie(0) << std::endl;
}
catch (const std::logic_error& e)
{
	std::cerr << e.what() << std::endl;
}

try
{
	std::cout << "Rolling 3 six-sided dice: " << Random::rollDice(6, 3) << std::endl;

	// Edge case: Invalid number of faces
	std::cout << "Rolling dice with 0 faces: " << Random::rollDice(0, 3) << std::endl;

	// Edge case: Invalid number of dice
	std::cout << "Rolling 0 dice: " << Random::rollDice(6, 0) << std::endl;
}
catch (const std::logic_error& e)
{
	std::cerr << e.what() << std::endl;
}
*/
