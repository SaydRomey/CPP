/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:18:05 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/19 17:06:26 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
// # include <cstdint>
# include <stdint.h>

# define RESET		"\033[0m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define PURPLE		"\033[95m"
# define ORANGE		"\033[38;5;208m"
# define GRAYTALIC	"\033[3;90m"

struct Data
{
	int			id;
	std::string	name;
	double		value;

	Data(int id, const std::string &name, double value);
	void	display(void) const;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif // DATA_HPP
