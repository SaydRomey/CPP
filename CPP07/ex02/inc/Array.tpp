/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:08:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/20 17:23:06 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

/*
"Construction with no parameter: Creates an empty array."
*/
template <typename T>
Array<T>::Array(void) : _data(new T[0]), _size(0) {}

/*
"Construction with an unsigned int n as a parameter:
	Creates an array of n elements initialized by default.

"You MUST use the operator new[] to allocate memory."
"*/
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{
	unsigned int	i = 0;

	while (i < _size)
	{
		_data[i] = T();
		i++;
	}
}

/*
"Construction by copy and assignment operator. In both cases,
modifying either the original array or its copy after copying
musn’t affect the other array.
*/
template <typename T>
Array<T>::Array(const Array<T> &other) : _data(new T[other._size]), _size(other._size)
{
	unsigned int	i = 0;
	while (i < _size)
	{
		_data[i] = other._data[i]; // deep copy
		i++;
	}
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
		if (_size != other._size)
		{
			delete[] _data;
			_data = new T[other._size];
			_size = other._size;
		}
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
