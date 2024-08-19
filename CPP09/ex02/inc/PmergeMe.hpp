/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:01 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/18 20:56:02 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

# define RESET		"\033[0m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define PURPLE		"\033[95m"
# define ORANGE		"\033[38;5;208m"
# define GRAYTALIC	"\033[3;90m"

class PmergeMe
{
	private:
		// Attributes
	
	public:
		// Constructors / Destructors
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);

		// Getters / Setters

		// Functions / Methods

		// Operators
		PmergeMe&	operator=(const PmergeMe &other);

		// Exceptions
};

// std::ostream&	operator<<(std::ostream &out, const PmergeMe &param);

#endif // PMERGEME_HPP
