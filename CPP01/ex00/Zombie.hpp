/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:27:38 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/15 18:05:34 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
	
		Zombie(std::string zombieName);
		Zombie(const Zombie &src);
		Zombie &operator=(const Zombie &rhs);
		~Zombie();

		void 	announce(void) const;
	};
	Zombie* newZombie(std::string name);
	void 	randomChump(std::string name);


#endif