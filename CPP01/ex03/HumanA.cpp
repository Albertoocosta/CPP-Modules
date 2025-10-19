/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:39:51 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/17 22:52:27 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}
HumanA::HumanA(const HumanA &src) : _name(src._name), _weapon(src._weapon)
{
}
HumanA &HumanA::operator = (const HumanA &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return *this;
}
HumanA::~HumanA()
{
}
void HumanA::attack() const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}