/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:35 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/14 20:48:36 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestsecret;
public:

	Contact();
	~Contact();

	std::string get_firstname(void) const;
	std::string get_lastname(void) const;
	std::string get_nickname(void) const;
	std::string get_phonenumber(void) const;
	std::string get_darkestsecret(void) const;

	void		set_firstname(std::string);
	void		set_lastname(std::string);
	void		set_nickname(std::string);
	void		set_phonenumber(std::string);
	void		set_darkestsecret(std::string);

	
};

#endif
