/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:48:09 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/22 19:56:40 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const & type);

		AMateria(const AMateria &src);
		AMateria& operator=(const AMateria& rhs);
		virtual ~AMateria();

		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0; //Pure Abstract
		virtual void use(ICharacter& target); 
};

#endif