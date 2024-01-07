/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:17:10 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/07 16:15:45 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class	Sample
{
	public:

		Sample(void);
		~Sample(void);
		
		static int	getNbInst(void);		
	
	private:

		static int		_nbInst;

};


#endif