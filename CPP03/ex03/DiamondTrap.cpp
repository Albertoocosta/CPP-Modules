/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamontTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:41:05 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/30 16:41:29 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
    ClapTrap("Default_clap_name"), 
    ScavTrap(), 
    FragTrap(),
    _name("DiamondDefault")
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = FragTrap::_energyPoints;
    this->_attackDamage = ScavTrap::_attackDamage;

    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
    ClapTrap(name + "_clap_name"), 
    ScavTrap(name), 
    FragTrap(name), 
    _name(name)
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = FragTrap::_energyPoints;
    this->_attackDamage = ScavTrap::_attackDamage;

    std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    std::cout << "DiamondTrap operator assigment called" << std::endl;
    if(this != &rhs)
    {
        ClapTrap::operator=(rhs);
        FragTrap::operator=(rhs);
        ScavTrap::operator=(rhs);
        this->_name = rhs._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "Hello I am DiamondTrap " << this->_name << " and the ClapTrap name is: " << ClapTrap::_name << std::endl;
}