/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:07:32 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/20 17:44:36 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CPP
# define ARRAY_CPP

# include <stdexcept>

template <typename T>
class Array
{
	private:
		T				*_data; // pointer to dynamically allocated array
		unsigned int	_size; // size of the array
	
	public:
		// Constructors
		Array(void);
		explicit Array(unsigned int n);
		Array(const Array<T> &other);

		// Destructor
		~Array(void);
	
		// Assignment operator
		Array<T> &operator=(const Array<T> &other);

		// Access operators
		T &operator[](unsigned int index); // subscript operator
		const T &operator[](unsigned int index) const; // subscript operator for const objects

		// Member function
		unsigned int	size(void) const;
};

# include "Array.tpp"

#endif // ARRAY_CPP