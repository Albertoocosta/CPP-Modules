/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:26:56 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/16 17:38:40 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog Assignment operator called" << std::endl;
	if(this != &rhs)
	{
		Animal::operator= (rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->brain;
}