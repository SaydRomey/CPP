/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:18:26 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/15 15:09:54 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDISFORLOSERS_HPP
# define SEDISFORLOSERS_HPP

#include <iostream>
#include <fstream>
#include <string>

# ifndef SUFFIX
#  define SUFFIX	".replace"
# endif

# define USAGE		" <filename> <string to replace> <replacement string>"

void	processLines(std::ifstream& inFile, std::ofstream& outStream, \
				const std::string& s1, const std::string& s2);

#endif