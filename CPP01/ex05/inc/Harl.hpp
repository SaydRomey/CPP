/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:32:54 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/15 15:34:30 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Harl
{
	public:
		Harl(void);
		~Harl(void);


	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);		
	
};
