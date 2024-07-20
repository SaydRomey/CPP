/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:17:54 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/19 22:14:30 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>

class Base
{
	public:
		virtual ~Base(void) {}
};

class A : public Base
{
	// 
};

class B : public Base
{
	// 
};

class C : public Base
{
	// 
};

Base*	generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif // BASE_HPP
