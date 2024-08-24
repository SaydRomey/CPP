/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:46:56 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/23 18:38:11 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

// Function to generate Jacobsthal numbers up to a given n
/*

*/
std::vector<int> generateJacobsthalSequence(int n)
{
	std::vector<int> jacobsthal;
	
	jacobsthal.push_back(0); // J_0
	if (n > 0)
	{
		jacobsthal.push_back(1); // J_1
	}
	int	i = 2;
	while (jacobsthal.back() < n)
	{
		int nextJacobsthal = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(nextJacobsthal);
		i++;
	}
	return (jacobsthal);
}

std::vector<int> generateJacobsthalSequence2(int n)
{
	std::vector<int>	jacobsthal;

	// Base cases
	if (n <= 0)
		return (jacobsthal);
	jacobsthal.push_back(1); // J_0
	if (n == 1)
		return (jacobsthal);

	jacobsthal.push_back(1); // J_1
	if (n == 2)
		return (jacobsthal);

	// Generate Jacobsthal sequence up to n terms
	int	i = 2;
	while (i < n)
	{
		int	next_value = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next_value);
		i++;
	}

	return (jacobsthal);
}

/*
Starts with the first two terms of the Jacobsthal sequence: 0 and 1
Then, generates subsequent terms using the recurrence relation
J(n) = J(n-1) + 2 * J(n-2)
*/
std::vector<int> generateJacobsthalSequence3(int size)
{
	std::vector<int> jacobsthal;

	if (size < 1)
		return (jacobsthal);

	jacobsthal.push_back(0);
	if (size > 1)
		jacobsthal.push_back(1);
	
	int	n1 = 0;
	int	n2 = 1;
	int	n3;
	
	int	i = 2;
	while (i <= size)
	{
		n3 = n2 + 2 * n1;
		jacobsthal.push_back(n3);

		n1 = n2;
		n2 = n3;
		i++;
	}

	return (jacobsthal);
}

void	printSequence(std::vector<int> &vec, std::string separator=", ")
{
	std::vector<int>::const_iterator	it = vec.begin();
	
	std::cout << "Sequence of " << vec.size() << " values: ";
	while (it != vec.end())
	{
		if (it + 1 == vec.end())
			std::cout << *it;
		else
			std::cout << *it << separator;
		it++;
	}
	std::cout << std::endl;
}

void	testJacobsthal(int n)
{
	std::vector<int> jaco = generateJacobsthalSequence(n);
	std::vector<int> jaco2 = generateJacobsthalSequence2(n);
	std::vector<int> jaco3 = generateJacobsthalSequence3(n);

	printSequence(jaco);
	printSequence(jaco2);
	printSequence(jaco3);
}

int	main(void)
{
	int	n = 20;

	testJacobsthal(n);

	return (0);
}
