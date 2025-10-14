#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
public:

	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkestSecret();

	void setContact(Contact *contact);
	std::string set_input();
	std::string input_number();
	void displayContact();

	std::string truncate_field(const std::string &field);
	
	Contact();
	~Contact();
};

#endif
