/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:56:02 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 16:55:21 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

using std::string;
using std::cout;
using std::endl;

#define RESET	"\033[0m"
#define BOLD	"\033[1m"
#define PURPLE	"\033[95m"
#define ORANGE	"\033[38;5;208m"

#define PRINT(STR)	cout << BOLD << "\n[ " << STR << " ]" << RESET << endl;

void	print(std::string str, std::string color = ORANGE)
{
	cout << color << "\n[ " << str << " ]" << RESET << endl;
}

/* ************************************************************************** */

void	pdfTest(void)
{
	print("*** PDF TEST ***", PURPLE);

	print("Animal* 'beast' = new Animal()");
	const Animal*	beast = new Animal();
	print("Animal* 'puppy' = new Dog()");
	const Animal*	puppy = new Dog();
	print("Animal* 'kitten' = new Cat()");
	const Animal*	kitten = new Cat();

	print("puppy->getType()");
	cout << puppy->getType() << endl;
	print("kitten->getType()");
	cout << kitten->getType() << endl;

	print("kitten->makeSound()");
	kitten->makeSound();
	print("puppy->makeSound()");
	puppy->makeSound();
	print("beast->makeSound()");
	beast->makeSound();

	print("delete kitten");
	delete kitten;
	print("delete puppy");
	delete puppy;
	print("delete beast");
	delete beast;
}

void	wrongTest(void)
{
	print("*** WRONG TEST ***", PURPLE);

	print("WrongAnimal* 'beast' = new WrongAnimal()");
	const WrongAnimal*	beast = new WrongAnimal();
	print("Animal* 'puppy' = new Dog()");
	const Animal*	puppy = new Dog();
	print("WrongAnimal* 'kitten' = new WrongCat()");
	const WrongAnimal*	kitten = new WrongCat();

	print("puppy->getType()");
	cout << puppy->getType() << endl;
	print("kitten->getType()");
	cout << kitten->getType() << endl;

	print("kitten->makeSound()");
	kitten->makeSound();
	print("puppy->makeSound()");
	puppy->makeSound();
	print("beast->makeSound()");
	beast->makeSound();

	print("delete kitten");
	delete kitten;
	print("delete puppy");
	delete puppy;
	print("delete beast");
	delete beast;
}

void	copyConstructorTest(void)
{
	print("*** COPY TEST ***", PURPLE);

	print("Dog* puppy = new Dog()");
	Dog*	puppy = new Dog();
	print("Dog  fluffyboy(*puppy)");
	Dog		fluffyboy(*puppy);

	print("puppy->getType() + puppy->makeSound()");
	cout << puppy->getType() << ": ";
	puppy->makeSound();
	print("delete puppy");
	delete puppy;

	print("fluffyboy.getType() + fluffyboy.makeSound()");
	cout << fluffyboy.getType() << ": ";
	fluffyboy.makeSound();
}

int	main(void)
{
	pdfTest();

	wrongTest();

	copyConstructorTest();

	PRINT((string)"this is " + (string)"a test");
	return (0);
}
