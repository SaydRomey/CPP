/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:59:38 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/15 13:47:38 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#define SUFFIX	".replace"

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

std::string	replaceInString(const std::string& str, const std::string& from, const std::string& to)
{
	std::string	result;
	size_t		index = 0;
	size_t		from_len = from.length();

	while (true)
	{
		size_t	found = str.find(from, index);

		if (found != std::string::npos)
		{
			result.append(str, index, found - index);
			result.append(to);
			index = found + from_len;
		}
		else
		{
			result.append(str, index, str.length() - index);
			break;
		}
	}
	return (result);	
}

void	processLines(std::ifstream& inFile, std::ofstream& outStream, const std::string& s1, const std::string& s2)
{
	std::string	line;
	bool		isFirstLine = true;
	
	while (getline(inFile, line))
	{
		if (!isFirstLine)
			outStream << std::endl;
		outStream << replaceInString(line, s1, s2);
		isFirstLine = false;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

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
