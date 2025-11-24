/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:14:19 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/23 17:12:54 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& src) : _type(src._type)
{
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	if (this != &rhs)
	{
		(void)rhs;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return(this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}