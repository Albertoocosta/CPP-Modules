/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:30 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/20 17:11:13 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contacts.hpp"

#define MAX_CONTACTS 3

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACTS];
		int		index;		
	public:

		PhoneBook(void);
		~PhoneBook(void);
		
		int 	handle_input(std::istream& input, std::string& content, const std::string& text);
		void add_contact();
		void search_contact();
};

#endif