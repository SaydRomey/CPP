/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:23:50 by cdumais           #+#    #+#             */
/*   Updated: 2025/01/09 10:35:42 by cdumais          ###   ########.fr       */
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
# include <vector>

// Constants for Linear Congruential Generator (LCG)
# define LCG_MULT	1103515245
# define LCG_INCR	12345
# define LCG_DIV	65536

using std::string;
using std::vector;

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
		
		// template <typename T>
		// static T		randomElement(const T* array, size_t size);

		static string	randomString(size_t length);
		static string	randomPassword(size_t length, bool useLowercase, bool useUppercase, bool useDigits, bool useSymbols);
		static string	randomName(int minLength, int maxLength);
		
		struct Color { unsigned char r, g, b; };
		static Color	randomColor(void);
		static vector<Color>	randomColorPalette(int count);
		
		struct Point { int x, y; };
		static Point	randomPoint(int minX, int minY, int maxX, int maxY);

		struct Time { int hour, minute, second; };
		static Time		randomTime(void);

		struct Date { int year, month, day; };
		static Date		randomDate(int startYear, int endYear);

		static int		rollDie(int faces);
		static int		rollDice(int faces, int count);
};

#endif // RANDOM_HPP
