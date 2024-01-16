/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:59:38 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 14:20:06 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: handle empty string as 's1' argument

#include "SedIsForLosers.hpp"

void	openInputFile(std::ifstream& inFile, const std::string& filename)
{
	inFile.open(filename.c_str());
	if (!inFile.is_open())
		std::cerr << "Error opening file: " << filename << std::endl;
}

void	openOutputFile(std::ofstream& outStream, const std::string& filename)
{
	std::string	outFile = filename + SUFFIX;
	outStream.open(outFile.c_str());
	if (!outStream.is_open())
		std::cerr << "Error creating file: " << outFile << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << USAGE << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Invalid argument : " << argv[2] << std::endl;
		return (1);
	}

	std::ifstream	inFile;
	openInputFile(inFile, filename);
	if (!inFile.is_open())
		return (1);

	std::ofstream	outStream;
	openOutputFile(outStream, filename);
	if (!outStream.is_open())
		return (1);

	processLines(inFile, outStream, s1, s2);

	inFile.close();
	outStream.close();	

	return (0);
}
