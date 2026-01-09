/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:09:21 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/09 14:31:44 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <iomanip>

class ScalarConverter 
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& src);
		ScalarConverter& operator=(ScalarConverter const& rhs);
		~ScalarConverter();
	public:
		static void converter(const std::string& literal);
};

#endif