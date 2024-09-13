/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wip.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:47:41 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/13 14:26:04 by cdumais          ###   ########.fr       */
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

template <typename Container, typename OtherContainer>
void	setSequence(Container &dst, const OtherContainer &src)
{
	dst.assign(src.begin(), src.end());
}

// idea for a conversion constructor
template <typename Container, typename OtherContainer>
PmergeMe<Container>::PmergeMe(const PmergeMe<OtherContainer> &other)
{
	setSequence(_inputSequence, other.getInputSequence());
	setSequence(_pairs, other._pairs);
	setSequence(_sorted, other._sorted);
	setSequence(_pending, other._pending);
	_sortingTime = other._sortingTime;
	_comparisons = other._comparisons;
}

// and modified assignment operator:
template <typename Container, typename OtherContainer>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe<OtherContainer> &other)
{
	if (reinterpret_cast<void*>(this) != reinterpret_cast<void*>(&other))
	{
		setSequence(_inputSequence, other.getInputSequence());
		setSequence(_pairs, other._pairs);
		setSequence(_sorted, other._sorted);
		setSequence(_pending, other._pending);
		_sortingTime = other._sortingTime;
		_comparisons = other._comparisons;
	}
	return (*this);
}
