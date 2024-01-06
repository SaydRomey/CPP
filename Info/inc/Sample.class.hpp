/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:17:10 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/06 15:01:27 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class	Sample
{
	public:

		Sample(int v);
		~Sample(void);

		int		getValue(void) const;
		int		compare(Sample *other) const;
	
	private:

		int		_privateValue;

};


#endif