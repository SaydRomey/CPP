/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:59:42 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/27 16:25:40 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	it;
	
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw (std::runtime_error("Value not found in container"));
		// throw (std::runtime_error("Value [" + std::to_string(value) + "] not found in container"));
	}
	return (it);
}

#endif // EASYFIND_HPP
