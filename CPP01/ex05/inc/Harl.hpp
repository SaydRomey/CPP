/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:32:54 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 11:48:01 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

# define RESET	"\033[0m"
# define ORANGE	"\033[38;5;208m"
# define CYAN	"\033[96m"

/*'DEBUG' level: Contextual information.
Mostly used for problem diagnosis.*/
# define DEBUG_MSG "\
I love having extra bacon for my\n\
7XL-double-cheese-triple-pickle-special-ketchup burger.\n\
I really do!\n"

/*'INFO' level: Contains extensive information.
Helpful for tracing program execution in a production environment.*/
# define INFO_MSG "\
I cannot believe adding extra bacon costs more money.\n\
You didn't put enough bacon in my burger!\n\
If you did, I wouldn't be asking for more!\n"

/*'WARNING' level: Indicates a potential issue in the system.
However, it can be handled or ignored.*/
# define WARNING_MSG "\
I think I deserve to have some extra bacon for free.\n\
I've been coming for years whereas you started working here since last month.\n"

/*'ERROR' level: Indicates that an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.*/
# define ERROR_MSG "\
This is unacceptable!\n\
I want to speak to the manager now.\n"


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

		typedef void (Harl::*HarlFuncPtr)(void);	
};


#endif
