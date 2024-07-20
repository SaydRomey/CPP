/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:08:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/20 18:10:50 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{
	unsigned int	i = 0;

	while (i < _size)
	{
		_data[i] = 0;
		i++;
	}
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _data(NULL), _size(0)
{
	*this = other; // using assignment operator to perform deep copy
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _data; // freeing dynamically allocated memory
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		// delete current data
		delete[] _data;

		// allocate new memory
		_size = other._size;
		_data = new T[_size];

		// copy elements
		unsigned int	i = 0;
		while (i < _size)
		{
			_data[i] = other._data[i];
			i++;
		}
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of range");
	}
	return (_data[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of range");
	}
	return (_data[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

#endif // ARRAY_TPP
