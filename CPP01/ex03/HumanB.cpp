/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:40:30 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/31 12:06:26 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::HumanB(const HumanB& src) : _name(src._name), _weapon(NULL)
{
}

HumanB& HumanB::operator=(const HumanB& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_weapon = rhs._weapon;
	}
	return (*this);
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack() const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with!" << std::endl;
}