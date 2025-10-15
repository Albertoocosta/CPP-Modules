/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:21:01 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/15 18:25:36 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete (heapZombie);

	std::cout << std::endl;

	randomChump("StackZombie");

	std::cout << std::endl;

	Zombie* persistent = newZombie("PersistentZombie");
	persistent->announce();
	delete (persistent);

	return (0);
}