/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:56:11 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/26 13:53:21 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator	easyfind(T &container, int value);

# include "easyfind.tpp"

#endif // EASYFIND_HPP
