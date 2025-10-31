/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:53:51 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/31 12:06:33 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP


# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;

	public:

		HumanB(std::string name);
		HumanB(const HumanB &src);
		HumanB &operator = (const HumanB &rhs);
		~HumanB();

		void setWeapon(Weapon& weapon);
		void attack() const;
};

#endif