/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:52:46 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 11:04:56 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Student
{
	private:
		std::string	_login;
	
	public:
		Student(std::string login) : _login(login)
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
	Student	bob = Student("bubbles");
	Student	*jim = new Student("jimbles");

	// Do some stuff here

	delete jim; //jim is destroyed
	
	
	return (0); //bob is destroyed
}
