/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:17:10 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/04 14:28:10 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class	Sample
{
	public:

		Sample(void);
		~Sample(void);

		int		getValue(void) const;
		void	setValue(int v);
	
	private:

		int		_privateValue;

};


#endif