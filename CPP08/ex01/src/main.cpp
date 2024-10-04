/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:05:06 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/04 16:24:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

/*
creates a 'Span' object with 'numElements' values
either in sequential order or randomized

optionnaly prints the number sequence,
then prints size and shortest/longest span
*/
void	testSpan(unsigned int numElements, bool sequential, bool printSequence = true)
{
	size_t	printLimit = 42;
	
	try
	{
		// creating a vector to generate the number sequence
		std::vector<unsigned int>	numbers;
		fillVector(numbers, numElements, sequential);

		// creating Span object and adding the numbers from the vector
		Span	span(numElements);
		span.addNumbers(numbers.begin(), numbers.end());

		// enabling printNumber flag to output number sequence
		span.setPrintNumbers(printSequence);

		// disabling the printNumbers flag if sequence is too big
		if (span.getNumbers().size() > printLimit)
			span.setPrintNumbers(false);

		std::string	sequenceType(sequential? "(Sequential)" : "(Randomized)");
		print(sequenceType);

		std::string	spanSize(std::to_string(span.getNumbers().size()));
		print(std::string("Span object with " + spanSize + " numbers"), UNDERLINE);
				
		// shortest and longest span printing (optionnal sequence printing handled in operator overload)
		std::cout << span << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*
"Running this code [...] should output:"
2
14
*/
void	pdfTest(void)
{
	print("\nPDF test:", UNDERLINE);

	try
	{
		Span	span = Span(5);
		
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << "\n" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*
optional seting of user input value to numElements
uses default value if:
	- input is negative
	- input is a floating-point value
	- any non-numeric characters were found
	- number is in the range of unsigned int
*/
static void	useArg(const std::string &arg, unsigned int &numElements)
{
	char	*endPtr = nullptr;

	print("Using user input for number of elements");
	print("(Runs much slower with value over 1000000...)");
	
	try
	{
		if (arg[0] == '-')
			throw (std::invalid_argument("Positive integer required"));
	
		unsigned long	tmp = strtoul(arg.c_str(), &endPtr, 10);

		if (*endPtr == '.')
			throw (std::invalid_argument("Floating-point values not allowed, integer required"));

		if (*endPtr != '\0')
		{
			// get string from start of invalid section
			std::string	invalidSection(endPtr);
			// get starting index of problematic part
			size_t		problemIndex = arg.find(invalidSection);
			// get substring until problematic part
			std::string	validPart(std::string(GRAYTALIC + (arg.substr(0, problemIndex) + RESET)));
			
			std::string	problemStr("Non-numeric character found: " + validPart + RED + invalidSection + RESET);
			throw (std::invalid_argument(problemStr));
		}

		if (tmp > std::numeric_limits<unsigned int>::max())
			throw (std::out_of_range("Value exceeds unsigned int limits"));

		numElements = static_cast<unsigned int>(tmp);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Invalid argument: " <<  RESET << e.what() << std::endl;
		print(std::string("Using default value (" + std::to_string(numElements) + ") instead\n"));
	}
}

/*	tmp function to check limits for user input
*/
static void	printDataTypeRange(void)
{
	std::cout << PURPLE << "Data type limits" << RESET << std::endl;
	
	long		intminLimit = std::numeric_limits<int>::min();
	long		intmaxLimit = std::numeric_limits<int>::max();
	std::string	intMinStr(std::to_string(intminLimit));
	std::string	intmaxStr(std::to_string(intmaxLimit));
	std::cout << UNDERLINE << RESET << "int min:\t" << intMinStr << "\nint max:\t" << intmaxStr << std::endl;

	long		uintminLimit = std::numeric_limits<unsigned int>::min();
	long		uintmaxLimit = std::numeric_limits<unsigned int>::max();
	std::string	uintMinStr(std::to_string(uintminLimit));
	std::string	uintmaxStr(std::to_string(uintmaxLimit));
	std::cout << UNDERLINE << RESET << "uint min:\t" << uintMinStr << "\nuint max:\t" << uintmaxStr << std::endl;

	std::cout << std::endl;
}


int	main(int argc, char *argv[])
{
	pdfTest();

	unsigned int	numElements = 10; // default value
	
	// conditionaly using user's choice for size of sequence to test
	if (argc >= 2)
		useArg(argv[1], numElements);

	// flags for sequence type
	bool	sequential = 1;
	bool	randomized = 0;

	testSpan(numElements, sequential);
	testSpan(numElements, randomized);

	// test with large sequence
	testSpan(420000, randomized, false);


	printDataTypeRange(); // tmp

	return (0);
}
