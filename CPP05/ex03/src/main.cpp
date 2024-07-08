/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:50:20 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/07 22:28:33 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::string;
using std::exception;

void	print(string str, string color = YELLOW)
{
	cout << color << "\n" << str << RESET << endl;
}

void	printFormCreation(const AForm &form, string color = GREEN)
{
	cout << color \
	<< "Created form: " << form.getName() \
	<< " for " << form.getTarget() << RESET << endl;
}

void	internTest(void)
{
	print("[ ** Testing intern **]", ORANGE);

	Intern	someRandomIntern;

	try
	{		
		AForm	*ppf = someRandomIntern.makeForm("presidential pardon", "Ian Carmil");
		printFormCreation(*ppf);
		delete ppf;
		cout << "\n";

		AForm	*rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		printFormCreation(*rrf);
		delete rrf;
		cout << "\n";

		AForm	*scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
		printFormCreation(*scf);
		delete scf;
		cout << "\n";

		AForm	*invalid_form = someRandomIntern.makeForm("<what is this piece of paper", "an intruder");
		printFormCreation(*invalid_form);
		delete invalid_form;
		cout << "\n";
	}
	// catch (const Intern::FormNotFoundException &e)
	catch (exception &e)
	{
		cout << RED << e.what() << RESET << endl;
	}
}

int	main(void)
{
	internTest();
	
	return (0);
}
