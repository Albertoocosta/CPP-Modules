/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:01:20 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/31 13:21:48 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal Construtor default called" << std::endl;
}

Animal::Animal(const Animal& src) : _type(src._type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Operator assigment called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes a generic sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}