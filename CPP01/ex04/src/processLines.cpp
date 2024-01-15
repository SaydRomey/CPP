/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processLines.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:21:20 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/15 15:10:02 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

std::string	replaceInString(const std::string& str, \
							const std::string& from, const std::string& to)
{
	std::string	result;
	size_t		index = 0;
	size_t		from_len = from.length();

	while (true)
	{
		size_t	found = str.find(from, index);

		if (found != std::string::npos)
		{
			result.append(str, index, found - index);
			result.append(to);
			index = found + from_len;
		}
		else
		{
			result.append(str, index, str.length() - index);
			break;
		}
	}
	return (result);	
}

void	processLines(std::ifstream& inFile, std::ofstream& outStream, \
				const std::string& s1, const std::string& s2)
{
	std::string	line;
	
	while (getline(inFile, line))
	{
		outStream << replaceInString(line, s1, s2);
		if (!inFile.eof())
			outStream << std::endl;
	}
}
