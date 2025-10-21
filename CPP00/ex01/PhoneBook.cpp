/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:25 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/20 15:46:05 by cda-fons         ###   ########.fr       */
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

int PhoneBook::handle_input(std::istream& input, std::string& content, const std::string& text)
{
    std::cout << text << std::endl;
    std::getline(input, content);
    if (input.eof())
    {
        input.clear();
        return 1;
    }
	return 0;
}

void PhoneBook::add_contact()
{
	std::string firstname, lastname, nickname, phonenumber, darkestsecret;
	
	if (handle_input(std::cin, firstname, "First name: "))
		return;
	if (handle_input(std::cin, lastname, "Last name: "))
		return;
	if (handle_input(std::cin, nickname, "Nickname: "))
		return;
	bool valid = false;
	while (!valid)
	{
		std::cout << "Phone Number: " << std::endl;
		std::getline(std::cin, phonenumber);
		if (std::cin.eof())
		{
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
	if (handle_input(std::cin, darkestsecret, "Darkest Secret: "))
		return;
	if (firstname.empty() || lastname.empty() || nickname.empty() || phonenumber.empty() || darkestsecret.empty())
	{
		std::cout << "All fields are required." << std::endl;
		return;
	}

	this->contacts[index % MAX_CONTACTS].set_firstname(firstname);
	this->contacts[index % MAX_CONTACTS].set_lastname(lastname);
	this->contacts[index % MAX_CONTACTS].set_nickname(nickname);
	this->contacts[index % MAX_CONTACTS].set_phonenumber(phonenumber);
	this->contacts[index % MAX_CONTACTS].set_darkestsecret(darkestsecret);
	index++;
}

void PhoneBook::search_contact()
{
	int idx;
	int total_contacts;
	
	if (this->index < MAX_CONTACTS) 
		total_contacts = this->index;
	else
		total_contacts = MAX_CONTACTS;
		
	if (this->index == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < total_contacts; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1
				  << "|" << std::setw(10) << truncate_field(contacts[i].get_firstname())
				  << "|" << std::setw(10) << truncate_field(contacts[i].get_lastname())
				  << "|" << std::setw(10) << truncate_field(contacts[i].get_nickname())
				  << "|" << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;

	std::cout << "Enter the index of the contact to view details: ";
	std::cin >> idx;
    if (std::cin.eof())
    {
        std::cin.clear();
        return;
    }
	std::cin.ignore();
	if (std::cin.fail() || idx < 1 || idx > this->index)
	{
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index." << std::endl;
		return;
	}
	else
	{
		std::cout << "First Name: " << this->contacts[idx - 1].get_firstname() << std::endl;
		std::cout << "Last Name: " << this->contacts[idx - 1].get_lastname() << std::endl;
		std::cout << "Nickname: " << this->contacts[idx - 1].get_nickname() << std::endl;
		std::cout << "Phone Number: " << this->contacts[idx - 1].get_phonenumber() << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[idx - 1].get_darkestsecret() << std::endl;
	}
}
