/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:23:33 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/16 17:20:29 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
	
class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog& rhs);
		~Dog();

		void makeSound() const;
		
		Brain* getBrain() const;
};

#endif