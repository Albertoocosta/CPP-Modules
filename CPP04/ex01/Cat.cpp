/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:39:19 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/16 18:00:48 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}
	
Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat Assigment operator called" << std::endl;
	if(this != &rhs)
	{
		Animal::operator= (rhs);
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meoow! Meoow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}