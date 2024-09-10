/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wip.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:47:41 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/08 18:05:45 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Container>
void PmergeMe::FordJohnson(Container &container, double &duration)
{
	std::clock_t start = std::clock();
	setSequence(container, getInputSequence());

	if (is_vector<Container>::value)
	{
		print("\nProcessing std::vector\n", ORANGE);
		
		// Pre-allocate space for vector to reduce reallocations
		std::vector<std::pair<int, int> > pairs;
		pairs.reserve(container.size() / 2);

		std::vector<int> pending;
		pending.reserve(container.size() / 2);  // Reserve space based on worst case

		std::vector<int> sorted;
		sorted.reserve(container.size());

		process(container, pairs, pending, sorted);
	}
	else if (is_deque<Container>::value)
	{
		print("\nProcessing std::deque\n", ORANGE);
		// No need to reserve for deque, handle pending more flexibly
		std::deque<std::pair<int, int> > pairs;
		std::deque<int> pending;
		std::deque<int> sorted;

		process(container, pairs, pending, sorted);
	}
	else
	{
		std::cout << "Handling other container type" << std::endl;
	}

	std::clock_t end = std::clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}
