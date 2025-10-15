/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:22 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/15 14:25:30 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
	this->_firstname = "";
	this->_lastname = "";
	this->_nickname = "";
	this->_phonenumber = "";
	this->_darkestsecret = "";
}

Contact::Contact(const Contact &src)
{
	_firstname = src._firstname;
	_lastname = src._lastname;
	_nickname = src._nickname;
	_phonenumber = src._phonenumber;
	_darkestsecret = src._darkestsecret;
}

Contact &Contact::operator=(const Contact &rhs)
{
	if (this != &rhs)
	{
		_firstname = rhs._firstname;
		_lastname = rhs._lastname;
		_nickname = rhs._nickname;
		_phonenumber = rhs._phonenumber;
		_darkestsecret = rhs._darkestsecret;
	}
	return (*this);
}

Contact::~Contact(){}

void Contact::set_firstname(std::string str)
{
	this->_firstname = str;
}

void Contact::set_lastname(std::string str)
{
	this->_lastname = str;

}
void Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

void Contact::set_phonenumber(std::string str)
{
	this->_phonenumber = str;
}

void Contact::set_darkestsecret(std::string str)
{
	this->_darkestsecret = str;
}


std::string Contact::get_firstname(void) const
{
	return (this->_firstname);
}

std::string Contact::get_lastname(void) const
{
	return (this->_lastname);
}
std::string Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string Contact::get_phonenumber(void) const
{
	return (this->_phonenumber);
}
std::string Contact::get_darkestsecret(void) const
{
	return (this->_darkestsecret);
}
