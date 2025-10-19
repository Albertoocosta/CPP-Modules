/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:25 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/18 20:26:27 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook() : index(0)
{
}
PhoneBook::~PhoneBook()
{
}
std::string truncate_field(const std::string &field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	else
		return (field);
}

void PhoneBook::add_contact()
{
	std::string firstname, lastname, nickname, phonenumber, darkestsecret;
	std::cout << "First name: " << std::endl;
	std::getline(std::cin, firstname);
	if (std::cin.eof())
    {
        std::cout << "\nEOF detected. Exiting contact creation." << std::endl;
        std::cin.clear();
        return;
    }
	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, lastname);
	if (std::cin.eof())
    {
        std::cout << "\nEOF detected. Exiting contact creation." << std::endl;
        std::cin.clear();
        return;
    }
	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, nickname);
	if (std::cin.eof())
    {
        std::cout << "\nEOF detected. Exiting contact creation." << std::endl;
        std::cin.clear();
        return;
    }
	bool valid = false;
	while (!valid)
	{
		std::cout << "Phone Number: " << std::endl;
		std::getline(std::cin, phonenumber);
		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting contact creation." << std::endl;
			std::cin.clear();
			return;
		}
		if (phonenumber.empty())
			break;    
		valid = true;
		for (size_t i = 0; i < phonenumber.length(); i++)
		{
			if (!std::isdigit(phonenumber[i]))
			{
				std::cout << "Phone number must contain only digits." << std::endl;
				valid = false;
				break;
			}
		}
	}
	
	std::cout << "Darkest Secret: " << std::endl;
	std::getline(std::cin, darkestsecret);
	if (std::cin.eof())
    {
        std::cout << "\nEOF detected. Exiting contact creation." << std::endl;
        std::cin.clear();
        return;
    }
	if (firstname.empty() || lastname.empty() || nickname.empty() || phonenumber.empty() || darkestsecret.empty())
	{
		std::cout << "All fields are required." << std::endl;
		return;
	}

	this->contacts[index % 8].set_firstname(firstname);
	this->contacts[index % 8].set_lastname(lastname);
	this->contacts[index % 8].set_nickname(nickname);
	this->contacts[index % 8].set_phonenumber(phonenumber);
	this->contacts[index % 8].set_darkestsecret(darkestsecret);
	std::cout << index << std::endl;
	index++;
}

void PhoneBook::search_contact()
{
	int index;

	if (this->index == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < this->index; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1
				  << "|" << std::setw(10) << truncate_field(contacts[i].get_firstname())
				  << "|" << std::setw(10) << truncate_field(contacts[i].get_lastname())
				  << "|" << std::setw(10) << truncate_field(contacts[i].get_nickname())
				  << "|" << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;

	std::cout << "Enter the index of the contact to view details: ";
	std::cin >> index;
    if (std::cin.eof())
    {
        std::cout << "\nEOF detected." << std::endl;
        std::cin.clear();
        return;
    }
	std::cin.ignore();
	if (std::cin.fail() || index < 1 || index > this->index)
	{
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index." << std::endl;
		return;
	}
	else
	{
		std::cout << "First Name: " << this->contacts[index - 1].get_firstname() << std::endl;
		std::cout << "Last Name: " << this->contacts[index - 1].get_lastname() << std::endl;
		std::cout << "Nickname: " << this->contacts[index - 1].get_nickname() << std::endl;
		std::cout << "Phone Number: " << this->contacts[index - 1].get_phonenumber() << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[index - 1].get_darkestsecret() << std::endl;
	}
}
