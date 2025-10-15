/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:30 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/14 20:48:31 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contacts.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		index;
	public:

		PhoneBook(void);
		~PhoneBook(void);

		void add_contact();
		void search_contact();
};

#endif