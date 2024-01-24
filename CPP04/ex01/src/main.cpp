/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:54:10 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 18:00:15 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

#define RESET	"\033[0m"
#define PURPLE	"\033[95m"
#define ORANGE	"\033[38;5;208m"

void	print(std::string str, std::string color = ORANGE)
{
	cout << color << "\n[ " << str << " ]" << RESET << endl;
}

void	printIndex(int index, bool nl=false)
{
	cout << PURPLE << "[" << index << "] " << RESET << (nl? "\n" : " ");
}

void	printIndex(int index, string str, bool nl=false)
{
	cout << str << PURPLE << "[" << index << "] " << RESET << (nl? "\n" : " ");
}

/* ************************************************************************** */

void	testFromPdf(void)
{
	print("*** PDF TEST ***", PURPLE);

	print("Animal* puppy = new Dog()");
	const Animal*	puppy = new Dog();
	print("Animal* puppy = new Cat()");
	const Animal*	kitten = new Cat();

	print("puppy->getType() + puppy->makeSound()");
	cout << puppy->getType() << ": ";
	puppy->makeSound();

	print("kitten->getType() + kitten->makeSound()");
	cout << kitten->getType() << ": ";
	kitten->makeSound();

	print("delete puppy");
	delete puppy;
	print("delete kitten");
	delete kitten;
}

void	animalArrayTest(void)
{
	print("*** ARRAY TEST ***", PURPLE);

	Animal*	animals[10]; //array of 10 Animal pointers

	int	i = 0;
	print("loop to fill 'animal[10] array with pointers to new objects");
	while (i < 10)
	{
		if (i < 5)
		{
			printIndex(i, true);
			animals[i] = new Dog();
		}
		else
		{
			printIndex(i, true);
			animals[i] = new Cat();
		}
		i++;
	}
	print("call 'makeSound()' function on each object");
	i = 0;
	while (i < 10)
	{
		printIndex(i, string("animal"));
		animals[i]->makeSound();
		i++;
	}

	i = 0;
	print("loop to delete each object in the array");
	while (i < 10)
	{
		printIndex(i, true);
		delete animals[i];
		i++;
	}
	
}

void	setAndGetIdeaTest(void)
{
	print("*** IDEA SET AND GET TEST ***\n(also copy constructor)", PURPLE);

	print("Dog* puppy = new Dog()");
	Dog*	puppy = new Dog();

	print("setIdea(\"Random thought\", 42)");
	puppy->setIdea("Random thought", 42);

	print("puppy->getIdea(42)");
	cout << puppy->getIdea(42) << endl;
	print("puppy->getIdea(41) (empty idea)");
	cout << puppy->getIdea(41) << endl;

	print("Dog fluffyboy(*puppy)");
	Dog	fluffyboy(*puppy);

	print("delete puppy");
	delete puppy;

	print("fluffyboy.getIdea(42)");
	cout << fluffyboy.getIdea(42) << endl << endl;
}

int	main(void)
{
	testFromPdf();

	animalArrayTest();

	setAndGetIdeaTest();

	return (0);
}
