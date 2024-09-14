/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wip.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:47:41 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/14 00:50:35 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
optimisations:
	vector : pre-allocate to reduce reallocations (using ::reserve)
	deque : during insertions, use deque's push_back/insert
		pos = binarySearchPos(sorted, pending[jacOrder[i]])
			if (pos == 0 || pos == sorted.size())
				sorted.push_back(pending[jacOrder[i]])
			else
				sorted.insert(sorted.begin() + pos, pending[jacOrder[i]])
*/

