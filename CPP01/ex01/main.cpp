/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:21:01 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/16 15:05:20 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int		hordeSize = 5;
	std::cout << "Creating a horde of " << hordeSize << " zombies named 'Zombie'" << std::endl;
	Zombie* horde = zombieHorde(hordeSize, "Zombie");
	
	std::cout << "Zombie scream: " << std::endl;
	for (int i = 0; i < hordeSize; i++)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}
	
	std::cout << "Here is where the horde is destroyed:" << std::endl;
	delete[] horde;

	hordeSize = 4;
	std::cout << "One more time, creating a horde with different hordeSize with zombies called CarloZombie" << std::endl;
	Zombie* horde2 = zombieHorde(hordeSize, "CarloZombie");
	
	for (int i = 0; i < hordeSize; i++)
	{
		std::cout << i << ": ";
		horde2[i].announce();
	}

	std::cout << "Here the horde of CarloZombie will be destroyed :" << std::endl;
	delete[] horde2;
	
	return (0);
}