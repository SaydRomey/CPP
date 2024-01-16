/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:00:41 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/15 23:29:56 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

# define RESET	"\033[0m"
# define ORANGE	"\033[38;5;208m"
# define CYAN	"\033[96m"

# define DEBUG_MSG "\
I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-ketchup burger.\n\
I really do!\n"

# define INFO_MSG "\
I cannot believe adding extra bacon costs more money.\n\
You didn't put enough bacon in my burger!\n\
If you did, I wouldn't be asking for more!\n"

# define WARNING_MSG "\
I think I deserve to have some extra bacon for free.\n\
I've been coming for years whereas you started working here since last month.\n"

# define ERROR_MSG "\
This is unacceptable!\n\
I want to speak to the manager now.\n"

# define DEFAULT_MSG "\
[ Probably complaining about insignificant problems ]\n"


class	Harl
{
	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);

	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		enum	e_levels
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			LVL_COUNT
		};

		std::string	_levels[LVL_COUNT];
		void		(Harl::*HarlFuncPtr[LVL_COUNT])(void);
};


#endif
