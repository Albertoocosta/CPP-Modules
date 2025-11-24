/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:23:59 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/23 22:27:32 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._templates[i])
			this->_templates[i] = src._templates[i]->clone();
		else
			this->_templates[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_templates[i])
				delete this->_templates[i];
			if (rhs._templates[i])
				this->_templates[i] = rhs._templates[i]->clone();
			else
				this->_templates[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i])
			delete this->_templates[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] == NULL)
		{
			this->_templates[i] = m->clone();
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] && this->_templates[i]->getType() == type)
			return this->_templates[i]->clone();
	}
	return NULL;
}