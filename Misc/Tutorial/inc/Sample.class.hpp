/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:33:32 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 18:53:38 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

// toadd: fonction membre permettant d'avoir une version sous forme de string
// (serializer une classe vers une string)

#include <iostream>

class	Sample
{
	public:
		Sample(void);
		Sample(int const n);
		Sample(Sample const & src);
		~Sample(void);

		Sample &	operator=(Sample const & rhs);

		int	getValue(void) const;
	
	private:

		int	_value;

};

std::ostream &	operator<<(std::ostream & o, Sample const & i);


#endif
