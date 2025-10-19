/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 02:44:38 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/18 03:04:56 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main ()
{
	{
		Weapon club = Weapon("Glock G5 .40");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Knife");
		bob.attack();
	}
	{
		Weapon club = Weapon("Knife");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("Bazooka");
		jim.attack();
	}
	return 0;
}