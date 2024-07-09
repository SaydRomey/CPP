/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:23:50 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/07 18:25:01 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_HPP
# define RANDOM_HPP

/*
utility class consisting of static methods
to avoid the need for object instantiation
[more info to come...]
*/

# include <cstdlib> // for srand and rand
# include <ctime>   // for time
# include <string>  // for std::string

// Constants for Linear Congruential Generator (LCG)
# define LCG_MULT	1103515245
# define LCG_INCR	12345
# define LCG_DIV	65536

using std::string

class Random
{
	private:

		static unsigned long	_seed;
	
	public:

		static void		seed(void);
		static void		trueSeed(void);
		static int		randomInt(int min, int max);
		static bool		chance(int percentage);
		static bool		randomBool(void);
		static float	randomFloat(void);

		template <typename T, size_t N>
		static void		shuffleArray(T (&array)[N]);

		template <typename T, size_t N>
		static T		randomElement(const T (&array[N]));

		static string	randomString(size_t length);
		static string	randomPassword(size_t length, bool useLowercase, bool useUppercase, bool useDigits, bool useSymbols);
		
		struct Color { unsigned char r, g, b; };
		static Color	randomColor(void);
		
		struct Point { int x, y; };
		static Point	randomPoint(int minX, int minY, int maxX, int maxY);
};

#endif // RANDOM_HPP
