#include "PhoneBook.hpp"

Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::~Contact(){}

std::string Contact::input_number()
{
	std::string input;
	bool isValid;

	while (true)
	{
		isValid = true;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (input.empty())
		{
			std::cout << "Input cannot be empty. Please try again: ";
			continue;
		}
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != ' ')
			{
				isValid = false;
				break;
			}
		}
		if (!isValid)
			std::cout << "Invalid phone number. Please enter digits, spaces, '+' or '-': ";
		else
			break;
	}
	return input;
}

std::string Contact::set_input()
{
	std::string input;

	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (input.empty())
			std::cout << "Input cannot be empty. Please try again: ";
		else
			break;
	}
	return input;
}

std::string truncate_field(const std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void Contact::setContact(Contact *contact)
{
	std::cout << "Enter First Name: ";
	this->_firstName = contact->set_input();
	std::cout << "Enter Last Name: ";
	this->_lastName = contact->set_input();
	std::cout << "Enter Nickname: ";
	this->_nickname = contact->set_input();
	std::cout << "Enter Phone Number: ";
	this->_phoneNumber = contact->input_number();
	std::cout << "Enter Darkest Secret: ";
	this->_darkestSecret = contact->set_input();
}


std::string Contact::getFirstName()
{
	return truncate_field(this->_firstName);
}
std::string Contact::getLastName()
{
	return truncate_field(this->_lastName);
}
std::string Contact::getNickname()
{
	return truncate_field(this->_nickname);
}

std::string Contact::getPhoneNumber()
{
	return truncate_field(this->_phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return truncate_field(this->_darkestSecret);
}


void Contact::displayContact ()
{
	std::cout << "First Name: " << this->getFirstName() << std::endl;
	std::cout << "Last Name: " << this->getLastName() << std::endl;
	std::cout << "Nickname: " << this->getNickname() << std::endl;
	std::cout << "Phone Number: " << this->getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->getDarkestSecret() << std::endl;
}