/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:10:09 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/23 18:10:47 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_templates[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource&	operator=(const MateriaSource& rhs);
		~MateriaSource();
		
		void	learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};

#endif