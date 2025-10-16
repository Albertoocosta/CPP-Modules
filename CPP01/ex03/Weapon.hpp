/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:48:35 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/16 17:06:56 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string _type;

public:

	Weapon();
	Weapon(std::string type);
	Weapon(const Weapon &src);
	Weapon &operator = (const Weapon &rhs);
	~Weapon();
	
	const 	std::string& getType() const;
	void	setType(std::string type);	
};

#endif