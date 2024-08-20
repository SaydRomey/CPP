/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:55:56 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/20 01:23:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
You must create a program with these constraints:

• The name of the program is PmergeMe.
• Your program must be able to use a positive integer sequence as argument.
• Your program must use the merge-insert sort algorithm to sort the positive integer sequence.

To clarify, yes, you need to use the Ford-Johnson algorithm.

• If an error occurs during program execution,
an error message should be displayed on the standard output.

You must use at least two different containers in your code to validate this exercise.
Your program must be able to handle at least 3000 different integers.

It is strongly advised to implement your algorithm for each container
and thus to avoid using a generic function.

Here are some additional guidelines on the information you should display line by line on the standard output:
• On the first line you must display an explicit text
	followed by the unsorted positive integer sequence.
• On the second line you must display an explicit text
	followed by the sorted positive integer sequence.
• On the third line you must display an explicit text indicating the time used by your algorithm
	by specifying the first container used to sort the positive integer sequence.
• On the last line you must display an explicit text indicating the time used by your algorithm
	by specifying the second container used to sort the positive integer sequence.

The format for the display of the time used to carry out your sorting is free
but the precision chosen must allow to clearly see the difference between the two containers used.

Here is an example of a standard use:

$> ./PmergeMe 3 5 9 7 4
Before: 35974
After: 34579
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>

The indication of the time is deliberately strange in this example.
Of course you have to indicate the time used to perform all your operations,
both the sorting part and the data management part.

Warning: The container(s) you used in the previous exercises are forbidden here.

The management of errors related to duplicates is left to your discretion.
*/

#include "PmergeMe.hpp"

void	testJacobsthal(int num)
{
	std::vector<int> jacobsthalOrder = generateJacobsthalOrder<int, std::vector<int> >(num);
	std::vector<int>::const_iterator	it = jacobsthalOrder.begin();
	
	std::cout << "jacobstal of size " << num << ": ";
	while (it != jacobsthalOrder.end())
	{
		if (it + 1 == jacobsthalOrder.end())
			std::cout << *it;
		else
			std::cout << *it << ", ";
		it++;
	}
	std::cout << std::endl;
}

int	main(int argc, char *argv[])
{	
	if (argc < 2)
	{
		std::cout << "Error: No input sequence provided" << std::endl;
		return (1);
	}

	std::vector<int>	inputSequence;
	try
	{
		inputSequence = parseInput(argc, argv);

		PmergeMe	sorter;
		sorter.setSequence(inputSequence);

		std::vector<int>	vectorSequence = inputSequence;
		std::deque<int>		dequeSequence(inputSequence.begin(), inputSequence.end());

		sorter.mergeInsertSort(vectorSequence);
		sorter.mergeInsertSort(dequeSequence);
		sorter.displayResults();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

//
/*
we have trouble with 300 values...

*/
