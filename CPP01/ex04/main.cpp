/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:16:46 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/18 20:59:44 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

std::string replace_it(std::string content, const std::string& word1, const std::string& word2)
{
	std::string result;
	int pos = 0;
	std::string::size_type found;

	if (word1.empty())
		return content;
	while ((found = content.find(word1, pos)) != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result.append(word2);
		pos = found + word1.length();
	}
	result.append(content, pos, content.length() - pos);
	return result;
}
int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		std::cerr << "Usage: ./Replace_it <filename> <Oringinal_word> <Word_to_replace>" << std::endl;
		return 1;
	}
	
	std::string file = argv[1];
	std::string word1 = argv[2];
	std::string word2 = argv[3];

	std::ifstream inputFile(file.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file. '" << file << "'" << std::endl;
		return 1;
	}
	
	std::string content;
	std::string line;
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof())
			content += "\n";
	}
	inputFile.close();

	std::string result = replace_it(content, word1, word2);

	std::string outFilename = file + ".replace";
	std::ofstream outputFile(outFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not open file. '" << file << "'" << std::endl;
		return 1;
	}
	outputFile << result;
	outputFile.close();

	std::cout << "File created: " << outFilename << std::endl;
	return 0;
}