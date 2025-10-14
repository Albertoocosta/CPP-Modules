#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contacts.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int index;
public:

	PhoneBook();
	~PhoneBook();

	Contact* getContacts();
	int getIndex();

	void setIndex(int newIndex);

	void addContact(PhoneBook &phoneBook);
	void searchContact(PhoneBook &phoneBook);

	std::string formatField(std::string &field);
};

#endif