/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:37:10 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/20 17:00:53 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

/*
params:
'T' -> the address of an array (pointer to the array of type T)
'length' -> length of the array
'f' -> pointer to a function (takes a reference to 'T' and returns void)
	that will be applied to each element of the array
*/
template <typename T>
void	iter(T *array, size_t length, void (*f)(T &))
{
	size_t i = 0;

	while (i < length)
	{
		f(array[i]);
		i++;
	}
}

template <typename T>
void	printElement(T &elem)
{
	std::cout << elem << " ";
}

template <typename T>
void	addFortyTwo(T &elem)
{
	elem += 42;
}

template <typename T>
void	doubleElement(T &elem)
{
	elem += elem;
}

#endif // ITER_HPP
