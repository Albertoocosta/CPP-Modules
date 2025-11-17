/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:39:56 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/16 17:06:32 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{

	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& src);
		Brain& operator=(const Brain& rhs);
		~Brain();

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;

};

#endif