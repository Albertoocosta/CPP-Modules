/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:46:04 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/23 17:51:59 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
	public:
		Character();
		Character(std::string const & name);
		Character(const Character& src );
		Character &	operator=( Character const& rhs );
		~Character();


		std::string const &	getName() const;
		void	equip(AMateria* m);
		void	unequip(int index);
		void	use(int index, ICharacter& target);
};

#endif