/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:21:43 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/19 17:14:02 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class	Harl {
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error (void) const;
	public:
		Harl();
		Harl(const Harl &src);
		Harl& operator=(const Harl& src);
		~Harl();

		void complain(std::string level);
		void filter(std::string level);
};

#endif