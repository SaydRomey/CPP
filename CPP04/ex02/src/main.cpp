/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:54:10 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 18:03:34 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <sstream>

using std::string;
using std::ostringstream;
using std::cout;
using std::endl;

#define RESET	"\033[0m"
#define BOLD	"\033[1m"
#define RED		"\033[91m"
#define GREEN	"\033[32m"
#define PURPLE	"\033[95m"
#define ORANGE	"\033[38;5;208m"

#define ARRAY_SIZE	10

void	title(string str, string color=ORANGE)
{
	cout << color << "\n[ " << str << " ]" << RESET << endl;
}

void	printIndex(string str, int index, string color, bool nl=false)
{
	cout << color << str << "[" << index << "]" << RESET << (nl ? "\n" : " ");
}

void	printIndex(string str, int index, bool nl=false)
{
	cout << BOLD << str << "[" << index << "]" << RESET << (nl ? "\n" : " ");
}

/* ************************************************************************** */

void	AanimalArrayTest(void)
{
	AAnimal*		animals[ARRAY_SIZE]; //array of AAnimal pointers
	int				i;

	ostringstream	arraySizeOut;
	arraySizeOut << ARRAY_SIZE;
	string			arraySizeStr = arraySizeOut.str();

	title("loop to fill 'Aanimal[" + arraySizeStr + "]' array");
	i = 0;
	while (i < ARRAY_SIZE)
	{
		if (i < (ARRAY_SIZE / 2))
		{
			printIndex("animals", i, GREEN, true);
			animals[i] = new Dog();
		}
		else
		{
			printIndex("animals", i, GREEN, true);
			animals[i] = new Cat();
		}
		i++;
	}
	title("Polymorphism demonstration");
	i = 0;
	while (i < ARRAY_SIZE)
	{
		printIndex("animals", i, string(PURPLE));
		animals[i]->makeSound();
		i++;
	}
	title("loop to delete all " + arraySizeStr + " object in the array");
	i = 0;
	while (i < ARRAY_SIZE)
	{
		printIndex("animals", i, RED, true);
		delete animals[i];
		i++;
	}
	
}

int	main(void)
{
	// AAnimal	animal; //uncomment to attempt to instantiate AAnimal directly (should fail)

	AanimalArrayTest();

	return (0);
}
