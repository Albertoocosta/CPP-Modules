/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:55:57 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/30 16:52:13 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "First Test: Constructor / Destructor Chain and Scope Blocks" << std::endl;
	{
		DiamondTrap diamond("DiamondGuy");
		std::cout << "DiamondGuy created!" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Second Test: DiamondTrap Stats" << std::endl;
	DiamondTrap flea("Flea");
	std::cout << "Name: " << flea.getName() << std::endl;
	std::cout << "HP: " << flea.getHitPoints() << "(from FragTrap)"<< std::endl;
	std::cout << "Energy: " << flea.getEnergyPoints() << "(from FragTrap)" << std::endl;
	std::cout << "Attack: " << flea.getAttackDamage() << "(from ScavTrap)" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Third Test: whoAmI() - Two Names" << std::endl;
	flea.whoAmI();
	std::cout << std::endl;

	std::cout << "Fourth Test: attack(using ScavTrap version)" << std::endl;
	flea.attack("Frusciante");
	std::cout << std::endl;

	std::cout << "Fifth Test: Inherited Methods" << std::endl;
	flea.takeDamage(50);
	flea.beRepaired(30);
	std::cout << std::endl;

	std::cout << "Sixth Test Special Abilities from Both Parents:"<< std::endl;
	flea.guardGate();
	flea.highFiveGuys();
	std::cout << std::endl;
	
	std::cout << "Seventh Test: Comparison of all three Classes" << std::endl;
	ClapTrap clap("Clappy");
	ScavTrap scav ("Scavvy");
	FragTrap frag("Fraggy");
	DiamondTrap diamond("Diamondy");

	std::cout << "\n Stats Comparison:" << std::endl;
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
	
	std::cout << "\nDiamondTrap stats:" << std::endl;
	std::cout << "HP: " << diamond.getHitPoints()
	<< ", Energy: " << diamond.getEnergyPoints()
	<< ", Damage: " << diamond.getAttackDamage() << std::endl;
	std::cout << std::endl;

	std::cout << "Attack comparison:" << std::endl; 
	std::cout << "\nClapTrap attack:" << std::endl;
	clap.attack("AlienCrap");

	std::cout << "\nScavTrap attack:" << std::endl;
	scav.attack("AlienScav");
	
	std::cout << "\nFragTrap attack:" << std::endl;
	frag.attack("AlienFrag");
	std::cout << std::endl;

	std::cout << "\nDiamondTrap attack:" << std::endl;
	diamond.attack("AlienDiamond");
	std::cout << std::endl;

	std::cout << "\nSpecial abilities:" << std::endl;
	scav.guardGate();
	frag.highFiveGuys();
	diamond.whoAmI();
	std::cout << std::endl;

	std::cout << "Eighth Test: Copy constructor" << std::endl;
	DiamondTrap original("Original");
	DiamondTrap copy(original);
	std::cout << "Copy name: " << copy.getName() << std::endl;
	std::cout << "Copy HP: " << copy.getHitPoints() << std::endl;
	copy.whoAmI();
	std::cout << std::endl;
	
	std::cout << " #### Destructors #####" << std::endl;
	return 0;
}