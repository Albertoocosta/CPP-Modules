/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:27:38 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/16 14:57:33 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string _name;
	public:

		Zombie();
		Zombie(const Zombie &src);
		Zombie &operator=(const Zombie &rhs);
		~Zombie();

		void  	setName(std::string zombieName);
		void 	announce(void) const;
};

Zombie* zombieHorde(int n, std::string name);

#endif