/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:52:46 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 11:11:00 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Student
{
	private:
		std::string	_login;
	
	public:
		Student(void) : _login("ldefault")
		{
			std::cout << "Student " << this->_login << " is born" << std::endl;
		}
		
		~Student(void)
		{
			std::cout << "Student " << this->_login << " died" << std::endl;
		}
		
};

int	main(void)
{
	Student	*students = new Student[42];

	// Do some stuff here

	delete [] students;
	
	
	return (0); //bob is destroyed
}
