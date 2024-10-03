/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:05:06 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/03 15:49:04 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>



void	printSpan(Span &span)
{
	// std::cout << "\n" << UNDERLINE \
	// << "Span of " << span.getNumbers().size() << " numbers" \
	// << RESET << std::endl;
	// std::cout << "Shortest span:\t" << span.shortestSpan() << std::endl;
	// std::cout << "Longest span:\t" << span.longestSpan() << std::endl;

	std::cout << span << std::endl;
}

/*
helper function to fill a vector with either sequential or random numbers
*/
void	fillVector(std::vector<unsigned int> &vec, unsigned int numElements, bool sequential = true) // or something else to choose random sequence or sequential
{
	vec.clear();

	if (!sequential)
	{
		std::srand(static_cast<unsigned int>(std::time(0)));

		unsigned int	i = 0;
		while (i < numElements)
		{
			vec.push_back(std::rand()); // adding random numbers
			++i;
		}
	}
	else
	{
		unsigned int	i = 0;
		while (i < numElements)
		{
			vec.push_back(i + 1); // adding sequential numbers
			++i;
		}
	}
}

/*
creates a 'Span' object with 'numElements' values
then prints size and shortest/longest span
*/
void	testSpan(unsigned int numElements, bool sequential = true)
{
	try
	{
		Span	span(numElements);
		std::vector<unsigned int>	numbers;
		
		fillVector(numbers, numElements, sequential);

		span.addNumbers(numbers.begin(), numbers.end());
		
		printSpan(span);
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
	std::cout << UNDERLINE << "\nPDF test:" << RESET << std::endl;
	
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

int	main(void)
{
	unsigned int	numElements = 10;

	pdfTest();
	
	// test with sequential numbers
	testSpan(numElements);
	
	// test with randomized numbers
	testSpan(numElements, false);
	
	return (0);
}

//

// class Span
// {
//     // ... other members and functions
//     public:
//         void setPrintNumbers(bool print);
//     private:
//         bool _printNumbers;
// };

// std::ostream& operator<<(std::ostream &out, const Span &param);

// //

// void Span::setPrintNumbers(bool print)
// {
//     _printNumbers = print;
// }

// //

// std::ostream& operator<<(std::ostream &out, const Span &param)
// {
//     if (param._numbers.empty())
//     {
//         out << "Span is empty.\n";
//     }
//     else
//     {
//         if (param._printNumbers)
//         {
//             out << "Span contains " << param._numbers.size() << " numbers:\n";
//             for (size_t i = 0; i < param._numbers.size(); ++i)
//             {
//                 out << param._numbers[i] << " ";
//             }
//             out << "\n";
//         }

//         try
//         {
//             out << "Shortest span: " << param.shortestSpan() << "\n";
//             out << "Longest span: " << param.longestSpan() << "\n";
//         }
//         catch (const std::exception &e)
//         {
//             out << e.what() << "\n";
//         }
//     }
//     return out;
// }

// int main(void)
// {
//     Span span(5);
//     span.addNumber(6);
//     span.addNumber(3);
//     span.addNumber(17);
//     span.addNumber(9);
//     span.addNumber(11);

//     // Control the behavior
//     span.setPrintNumbers(true);
//     std::cout << span; // Will print stored numbers

//     span.setPrintNumbers(false);
//     std::cout << span; // Will not print stored numbers

//     return 0;
// }

// std::ostream& operator<<(std::ostream &out, const Span &param)
// {
//     try
//     {
//         out << "Shortest span: " << param.shortestSpan() << "\n";
//         out << "Longest span: " << param.longestSpan() << "\n";
//     }
//     catch (const std::exception &e)
//     {
//         out << e.what() << "\n";
//     }
//     return out;
// }

// void printNumbers(std::ostream &out, const Span &param)
// {
//     if (param._numbers.empty())
//     {
//         out << "Span is empty.\n";
//     }
//     else
//     {
//         out << "Span contains " << param._numbers.size() << " numbers:\n";
//         for (size_t i = 0; i < param._numbers.size(); ++i)
//         {
//             out << param._numbers[i] << " ";
//         }
//         out << "\n";
//     }
// }

// int main(void)
// {
//     Span span(5);
//     span.addNumber(6);
//     span.addNumber(3);
//     span.addNumber(17);
//     span.addNumber(9);
//     span.addNumber(11);

//     std::cout << span;  // Only prints shortest and longest span
//     printNumbers(std::cout, span);  // Prints stored numbers

//     return 0;
// }

// //
