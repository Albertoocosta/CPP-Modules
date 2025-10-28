/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:29:01 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/28 00:12:28 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	std::cout << "## First Test : Basic creation ##" << std::endl;
	ClapTrap robot("RobotZ");
	std::cout << std::endl;

	std::cout << "## Second Test: Attack ##" << std::endl;
	robot.attack("Enemy");
	std::cout << "Energy Left: " << robot.getEnergyPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "## Third Test : Take Damage ##" << std::endl;
	robot.takeDamage(3);
	std::cout << "HP Left :" << robot.getHitPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "## Fourth Test : Be Repaired ##" << std::endl;
	robot.beRepaired(5);
	std::cout << "HP after repair: " << robot.getHitPoints() << std::endl;
	std::cout << "Energy Left: " << robot.getEnergyPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "## Fifth Test : Multiple attacks ##" << std::endl;
	ClapTrap alien("Alien");
	for (int i = 0; i < N_ITER; i++)
	{
		std::cout << "Attack " << (i + 1) << ": ";
		alien.attack("Human");
	}
	std::cout << std::endl;
	
	std::cout << "## Sixth Test : Death ##" << std::endl;
	ClapTrap charlie("Charlie");
	charlie.takeDamage(10);
	charlie.attack("Dark Lord");
	charlie.beRepaired(5);
	std::cout << std::endl;
	
	std::cout << "## Seventh Test : Copy Constructor ##" << std::endl;
	ClapTrap src("Source");
	ClapTrap copy(src);
	std::cout << "Copy name: " << copy.getName() << std::endl;
	std::cout << std::endl;
	
	std::cout << "## Eighth Test : Assignment Operator ##" << std::endl;
	ClapTrap adam("Adam");
	ClapTrap eve("Eve");
	eve = adam;
	std::cout << "Eve's name after assigment: " << eve.getName() << std::endl;
	std::cout << std::endl;

	std::cout << "## Destructors ##" << std::endl;
	return 0;
}