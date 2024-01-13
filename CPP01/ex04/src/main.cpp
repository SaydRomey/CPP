/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:59:38 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/12 21:13:02 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceInString(const std::string& str, const std::string& from, const std::string& to)
{
	std::string result;
	size_t pos = 0;
	size_t from_len = from.length();

	while (true)
	{
		size_t found = str.find(from, pos);

		if (found != std::string::npos)
		{
			result.append(str, pos, found - pos);
			result.append(to);
			pos = found + from_len;
		}
		else
		{
			result.append(str, pos, str.length() - pos);
			break;
		}
	}
	return result;
}

void processFile(const char* filename, const std::string& s1, const std::string& s2)
{
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}

	std::string outFile = std::string(filename) + ".replace";
	std::ofstream outStream(outFile.c_str());
	if (!outStream.is_open())
	{
		std::cerr << "Error creating file: " << outFile << std::endl;
		return;
	}

	std::string line;
	while (getline(inFile, line))
	{
		outStream << replaceInString(line, s1, s2);
		if (!inFile.eof())
		{
			outStream << std::endl;
		}
	}

	inFile.close();
	outStream.close();
}


int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return 1;
	}

	processFile(argv[1], argv[2], argv[3]);
	return 0;
}
