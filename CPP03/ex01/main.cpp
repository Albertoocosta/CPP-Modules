/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:55:40 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/29 12:38:55 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
    std::cout << "First Test: Constructor / Destructor Chain and Scope Blocks" << std::endl;
	{
		ScavTrap crazyGuy("CrazyGuy");
		std::cout << "CrazyGuy created!" << std::endl;
	}
	std::cout << std::endl;

    std::cout << "Second Test: ScavTrap Stats" << std::endl;
	ScavTrap john("John");
	std::cout << "Name: " << john.getName() << std::endl;
	std::cout << "HP: " << john.getHitPoints() << std::endl;
	std::cout << "Energy: " << john.getEnergyPoints() << std::endl;
	std::cout << "Attack: " << john.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Third Test: ScavTrap attack with different message" << std::endl;
	john.attack("Aliens");
	std::cout << std::endl;

	std::cout << "Fourth Test: Inherited Methods" << std::endl;
	john.takeDamage(30);
	john.beRepaired(20);
	std::cout << "HP after damage and repair: " << john.getHitPoints() << std::endl;
	std::cout << std::endl;

    std::cout << "Fifth Test: Special Ability - Guard Gate" << std::endl;
	john.guardGate();
	std::cout << std::endl;

    std::cout << "Sixth Test: Comparison with ClapTrap" << std::endl;
	ClapTrap clap("Clappy");
	ScavTrap scav ("Scavvy");

	std::cout << "\nClapTrap stats:" << std::endl;
	std::cout << "HP: " << clap.getHitPoints()
	<< ", Energy: " << clap.getEnergyPoints()
	<< ", Damage: " << clap.getAttackDamage() << std::endl;
	
	std::cout << "\nScavTrap stats:" << std::endl;
	std::cout << "HP: " << scav.getHitPoints()
	<< ", Energy: " << scav.getEnergyPoints()
	<< ", Damage: " << scav.getAttackDamage() << std::endl;
	
	std::cout << "\nClapTrap attack:" << std::endl;
	clap.attack("AlienCrap");

	std::cout << "\nScavTrap attack:" << std::endl;
	scav.attack("AlienScav");
	std::cout << std::endl;


	std::cout << "Seventh Test: Copy constructor" << std::endl;
	ScavTrap original("Original");
	ScavTrap copy(original);
	std::cout << "Copy name: " << copy.getName() << std::endl;
	std::cout << std::endl;

	std::cout << " #### Destructors #####" << std::endl;
	return 0;	

}