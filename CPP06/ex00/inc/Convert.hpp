/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:24:42 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/15 21:58:51 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <cmath>
# include <cctype>
# include <cerrno>
# include <cfloat>
# include <cstdlib>
# include <exception>
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>

# define INVALID_TYPE "\
Invalid scalar type. Accepted values are:\n\
char: single printable character (e.g., 'a')\n\
int: integer values (e.g., 42)\n\
float: floating-point values with 'f' suffix (e.g., 42.0f)\n\
double: floating-point values (e.g., 42.0)\n"



#endif // CONVERT_HPP
