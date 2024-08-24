/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_time.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:59:33 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/23 15:30:02 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>          // For clock()
#include <sys/time.h>     // For gettimeofday()

// Example function whose execution time you want to measure
void PmergeMe()
{
	// Simulating some work with a delay
	volatile int	i = 0;
	while (i < 1000000)
	{
		i++; // example delay
	}
}

// Measure time using clock()
void	measureUsingClock(void)
{
	std::clock_t	start = std::clock();
	PmergeMe();
	std::clock_t	end = std::clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	
	std::cout << "Time taken using clock(): " << duration << " seconds" << std::endl;
}

// Measure time using gettimeofday()
void measureUsingGettimeofday(void)
{
	struct timeval	start;
	struct timeval	end;
	gettimeofday(&start, NULL);
	PmergeMe();
	gettimeofday(&end, NULL);
	double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
	
	std::cout << "Time taken using gettimeofday(): " << duration << " seconds" << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " [1/2]" << std::endl;
		return (1);
	}
	
	int	choice = std::atoi(argv[1]);
	switch (choice)
	{
		case 1:
			measureUsingClock();
			break ;
		
		case 2:
			measureUsingGettimeofday();
			break ;
		
		default:
			std::cout << "choices are 1 or 2" << std::endl;
	}
	return (0);
}
