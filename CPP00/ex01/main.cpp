/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:18 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/15 14:49:57 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main (void)
{
	PhoneBook phonebook;
	std::string command;

	std::cout << "Welcome to your PhoneBook!" << std::endl;

	while (true)
	{
		std::cout << "Please enter a command (ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add" || command == "Add")
			phonebook.add_contact();
		else if (command == "SEARCH" || command == "search" || command == "Search")
			phonebook.search_contact();
		else if (command == "EXIT" || command == "exit" || command == "Exit" || std::cin.eof())
			break ;
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
			std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
		}
	}
	return (0);
}