/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:54:10 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 14:58:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define RESET	"\033[0m"
#define PURPLE	"\033[95m"
#define ORANGE	"\033[38;5;208m"

void	print(std::string str, std::string color = ORANGE)
{
	std::cout << color << "\n[ " << str << " ]" << RESET << std::endl;
}

void	printIndex(int index, bool nl=false)
{
	std::cout << PURPLE << "[" << index << "] " << RESET << (nl? "\n" : " ");
}

/* ************************************************************************** */

void	testFromPdf(void)
{
	print("Animal* puppy = new Dog()");
	const Animal*	puppy = new Dog();
	print("Animal* puppy = new Cat()");
	const Animal*	kitten = new Cat();

	print("delete puppy");
	delete puppy; //should not create a leak
	print("delete kitten");
	delete kitten;
	// ...
}

void	animalArrayTest(void)
{
	Animal*	animals[10]; //array of 10 Animal pointers

	int	i = 0;
	print("loop to fill 'animal[10] array");
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
	print("animal[10] now has 5 'Dog' objects and 5 'Cat' objects");

	print("tests with this array... (implement getters and setters for ideas ? )");
	i = 0;
	while (i < 10)
	{
		printIndex(i);
		animals[i]->makeSound(); //tmp if we use ideas instead..
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

int	main(void)
{
	testFromPdf();

	animalArrayTest();

	return (0);
}

/*

Files to turn in : Files from previous exercise + *.cpp, *.{h, hpp}

Constructors and destructors of each class must display specific messages.
Implement a Brain class.
It contains an array of 100 std::string called ideas.
This way, Dog and Cat will have a private Brain* attribute.
Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain.
In your main function, create and fill an array of Animal objects.
Half of it will be Dog objects and the other half will be Cat objects.
At the end of your program execution, loop over this array and delete every Animal.
You must delete directly dogs and cats as Animals.
The appropriate destructors must be called in the expected order.
Don’t forget to check for memory leaks.
A copy of a Dog or a Cat mustn’t be shallow.
Thus, you have to test that your copies are deep copies!

*/