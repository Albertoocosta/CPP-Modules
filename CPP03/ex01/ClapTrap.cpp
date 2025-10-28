/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:43:24 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/28 18:23:59 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("RobotDefault"), 
	_hitPoints(10), _energyPoints(10), _attackDamage(10) 
{
	std::cout << "ClapTrap RobotDefault constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), 
	_hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to attack" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack" << std::endl;
		return ;
	}
	this->_energyPoints --;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage and is destroyed!" << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage! (" << this->_hitPoints << " HP Left)" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to repair!" << std::endl;
		return;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot repair!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " HP (" << this->_hitPoints << " HP total)" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}