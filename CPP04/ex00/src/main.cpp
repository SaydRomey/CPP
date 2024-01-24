/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:56:02 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/23 19:32:37 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define RESET	"\033[0m"
#define ORANGE	"\033[38;5;208m"

void	print(std::string str, std::string color = ORANGE)
{
	std::cout << color << "\n[ " << str << " ]" << RESET << std::endl;
}

void	goodTest(void)
{
	print("Animal* 'beast' = new Animal()");
	const Animal*	beast = new Animal();
	print("Animal* 'puppy' = new Dog()");
	const Animal*	puppy = new Dog();
	print("Animal* 'kitten' = new Cat()");
	const Animal*	kitten = new Cat();

	print("puppy->getType()");
	std::cout << puppy->getType() << std::endl;
	print("kitten->getType()");
	std::cout << kitten->getType() << std::endl;

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
	print("WrongAnimal* 'beast' = new WrongAnimal()");
	const WrongAnimal*	beast = new WrongAnimal();
	print("Animal* 'puppy' = new Dog()");
	const Animal*	puppy = new Dog();
	print("WrongAnimal* 'kitten' = new WrongCat()");
	const WrongAnimal*	kitten = new WrongCat();

	print("puppy->getType()");
	std::cout << puppy->getType() << std::endl;
	print("kitten->getType()");
	std::cout << kitten->getType() << std::endl;

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

int	main(void)
{
	goodTest();
	// wrongTest();
	return (0);
}
