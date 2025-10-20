/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:18 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/20 17:16:40 by cda-fons         ###   ########.fr       */
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
		if (phonebook.handle_input(std::cin, command, "Please enter a command (ADD, SEARCH, EXIT): "))
			break;
		if (command == "ADD" || command == "add" || command == "Add")
		{
			phonebook.add_contact();
			if (std::cin.eof())
				return 1;
		}
		else if (command == "SEARCH" || command == "search" || command == "Search")
		{
			phonebook.search_contact();
			if (std::cin.eof())
				return 1;
		}	
		
		else if (command == "EXIT" || command == "exit" || command == "Exit" || std::cin.eof())
		{
			if (std::cin.eof())
			{
				std::cout << "\nEOF detected. Exiting PhoneBook." << std::endl;
				break;
			}	
			break ;
		}	
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
			std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
		}
	}
	return (0);
}