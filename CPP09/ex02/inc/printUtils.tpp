/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printUtils.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:05:56 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/27 17:17:36 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTUTILS_TPP
# define PRINTUTILS_TPP

# include <fstream>
# include <iostream>
# include <stdexcept>

# define RESET		"\033[0m"
# define GRAYTALIC	"\033[3;90m"

# define OUT_FILE "out.txt" // output file to store full versions of truncated sequences
# define SEQUENCE_TRUNCATION_THRESHOLD 10 // sequence size limit before being truncated
# define ENABLE_SEQUENCE_TRUNCATION true

/*
Overites pre-existing OUT_FILE's content when called for the first time,
will append following lines in successive calls during the same execution
*/
inline void	clearOutputFile(void)
{
	static bool	fileCleared = false;
	
	if (!fileCleared)
	{
		std::ofstream	outFile(OUT_FILE);
		if (!outFile)
		{
			throw (std::runtime_error("could not open file: " + std::string(OUT_FILE)));
		}
		outFile.close();
		fileCleared = true;
	}
}

template <typename Container>
void	printFirstN(const Container &container, int N)
{
	typename Container::const_iterator	it = container.begin();
	int	count = 0;
	while (count < N && it != container.end())
	{
		std::cout << *it << " ";
		++it;
		++count;
	}
}

template <typename Container>
void	printLastN(const Container &container, int N)
{
	typename Container::const_iterator	it = container.end();
	
	std::advance(it, -N);
	
	// int	count = 0;
	// while (count < N)
	// {
	// 	--it;
	// 	++count;
	// }
	
	int	count = 0;
	while (count < N)
	{
		std::cout << *it;
		if (count < N - 1)
		{
			std::cout << " ";
		}
		++it;
		++count;
	}
}

template <typename Container>
void	printFullSequenceToFile(const Container &container, const std::string &str)
{
	clearOutputFile();
	std::ofstream	outFile(OUT_FILE, std::ios::app);
	
	if (!outFile)
		throw (std::runtime_error("could not open file: " + std::string(OUT_FILE)));
	
	outFile << str;
	std::ostream_iterator<int>	outIt(outFile, " ");
	std::copy(container.begin(), container.end(), outIt);
	
	// outFile << str;
	// typename Container::const_iterator	it = container.begin();
	// while (it != container.end())
	// {
	// 	outFile << *it << " ";
	// 	++it;
	// }
	
	outFile << std::endl;
	outFile.close();
}

/*
*/
template <typename Container>
void	printSequence(const Container &container, const std::string &str, bool shouldPrint)
{
	if (!shouldPrint)
		return ;

	int	size = container.size();
	int	threshold = SEQUENCE_TRUNCATION_THRESHOLD;

	if (size > threshold && ENABLE_SEQUENCE_TRUNCATION)
	{
		int	printN = std::min((threshold / 2), (size - 1) / 2);

		printFullSequenceToFile(container, str);
		
		std::cout << str;
		printFirstN(container, printN);
		std::cout << "[...] ";
		printLastN(container, printN);
		std::cout << GRAYTALIC << " (Full sequence written in " << OUT_FILE << ")" << RESET;
	}
	else
	{
		std::cout << str;
		std::ostream_iterator<int>	outIt(std::cout, " ");
		std::copy(container.begin(), container.end(), outIt);
	}
	std::cout << std::endl;
}

/* ************************************************************************** */

template <typename PairContainer>
void	printPairs(const PairContainer &pairs, const std::string &str, bool shouldPrint)
{
	if (!shouldPrint)
		return ;

	std::cout << GRAYTALIC << str << RESET << std::endl;
	
	typename PairContainer::const_iterator	it = pairs.begin();
	
	while (it != pairs.end())
	{
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
		++it;
	}
}
/* ************************************************************************** */

#endif // PRINTUTILS_TPP
