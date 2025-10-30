/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:55:57 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/29 22:20:22 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"	
#include "../ex01/ScavTrap.hpp"

int main(void)
{
	    std::cout << "First Test: Constructor / Destructor Chain and Scope Blocks" << std::endl;
	{
		FragTrap crazyGuy("CrazyGuyFrag");
		std::cout << "CrazyGuyFrag created!" << std::endl;
	}
	std::cout << std::endl;

    std::cout << "Second Test: FragTrap Stats" << std::endl;
	FragTrap johnny("Johnny");
	std::cout << "Name: " << johnny.getName() << std::endl;
	std::cout << "HP: " << johnny.getHitPoints() << std::endl;
	std::cout << "Energy: " << johnny.getEnergyPoints() << std::endl;
	std::cout << "Attack: " << johnny.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Third Test: FragTrap attack (Using ClapTrap version)" << std::endl;
	johnny.attack("Aliens");
	std::cout << std::endl;

	std::cout << "Fourth Test: Inherited Methods" << std::endl;
	johnny.takeDamage(40);
	johnny.beRepaired(25);
	std::cout << "HP after damage and repair: " << johnny.getHitPoints() << std::endl;
	std::cout << std::endl;

    std::cout << "Fifth Test: Special Ability - High Guard Guys" << std::endl;
	johnny.highFiveGuys();
	std::cout << std::endl;

    std::cout << "Sixth Test: Comparison of all three Classes" << std::endl;
	ClapTrap clap("Clappy");
	ScavTrap scav ("Scavvy");
	FragTrap frag("Fraggy");

	std::cout << "\nClapTrap stats:" << std::endl;
	std::cout << "HP: " << clap.getHitPoints()
	<< ", Energy: " << clap.getEnergyPoints()
	<< ", Damage: " << clap.getAttackDamage() << std::endl;
	
	std::cout << "\nScavTrap stats:" << std::endl;
	std::cout << "HP: " << scav.getHitPoints()
	<< ", Energy: " << scav.getEnergyPoints()
	<< ", Damage: " << scav.getAttackDamage() << std::endl;
	
	std::cout << "\nFragTrap stats:" << std::endl;
	std::cout << "HP: " << frag.getHitPoints()
	<< ", Energy: " << frag.getEnergyPoints()
	<< ", Damage: " << frag.getAttackDamage() << std::endl;
	

	std::cout << "Attack comparison:" << std::endl; 
	std::cout << "\nClapTrap attack:" << std::endl;
	clap.attack("AlienCrap");

	std::cout << "\nScavTrap attack:" << std::endl;
	scav.attack("AlienScav");
	
	std::cout << "\nFragTrap attack:" << std::endl;
	frag.attack("AlienFrag");
	std::cout << std::endl;

	std::cout << "Test Special Abilities:"<< std::endl;
	scav.guardGate();
	frag.highFiveGuys();
	std::cout << std::endl;


	std::cout << "Seventh Test: Copy constructor" << std::endl;
	FragTrap original("Original");
	FragTrap copy(original);
	std::cout << "Copy name: " << copy.getName() << std::endl;
	std::cout << "Copy HP: " << copy.getHitPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "Seventh Test: Assigment Operator" << std::endl;
	FragTrap adam("Adam");
	FragTrap eve("Eve");
	eve = adam;
	std::cout << "Eve's name after assigment: " << eve.getName() << std::endl;
	std::cout << std::endl;

	
	std::cout << " #### Destructors #####" << std::endl;
	return 0;
}