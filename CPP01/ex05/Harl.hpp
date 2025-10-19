/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:21:43 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/19 00:41:25 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
};