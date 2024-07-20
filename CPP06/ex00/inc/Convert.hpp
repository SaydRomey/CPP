/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:24:42 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/20 14:30:42 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <cmath>
# include <cctype>
# include <cerrno>
# include <cfloat>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>

# define INVALID_TYPE "\
Invalid scalar type. Accepted values are:\n\
char:\tsingle printable character (e.g., 'a')\n\
int:\tinteger values (e.g., 42)\n\
float:\tfloating-point values with 'f' suffix (e.g., 42.0f)\n\
double:\tfloating-point values (e.g., 42.0)"

bool	isValidScalarType(const std::string &literal);
void	convert(const std::string &literal);

#endif // CONVERT_HPP
