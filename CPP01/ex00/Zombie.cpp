/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:35:35 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/31 11:36:28 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : _name(zombieName)
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << " Destroyed" << std::endl;
}

Zombie &Zombie::operator=(const Zombie &rhs) {
    if (this != &rhs) {
		_name = rhs._name;
    }
    return *this;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
	Zombie* zombie = new Zombie(name);
	return zombie;
}
void	randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}