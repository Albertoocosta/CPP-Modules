/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:35:35 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/16 15:01:04 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{
}
Zombie::Zombie(const Zombie &src) : _name(src._name) {
}

Zombie &Zombie::operator=(const Zombie &rhs) {
    if (this != &rhs) {
        _name = rhs._name;
    }
    return *this;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " Destroyed" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string zombieName)
{
	this->_name = zombieName;
}

