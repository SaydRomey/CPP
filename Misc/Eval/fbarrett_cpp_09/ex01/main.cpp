/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:06:29 by fbarrett          #+#    #+#             */
/*   Updated: 2024/05/08 13:25:05 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Invalid amound of argument. Please provide 1 argument." << endl;
		return (1);
	}
	std::string equation(argv[1]);
	try {
		RPN	something(equation);
		cout << something.calculate() << endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << endl;
	}
	return (0);
}
