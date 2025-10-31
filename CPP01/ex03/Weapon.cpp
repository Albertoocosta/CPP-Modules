/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:02:47 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/31 11:54:19 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("")
{
}

Weapon::Weapon(std::string type) : _type(type)
{
}
Weapon::Weapon(const Weapon& src)
{
	*this = src;
}

Weapon& Weapon::operator=(const Weapon& rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType() const
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;	
}
