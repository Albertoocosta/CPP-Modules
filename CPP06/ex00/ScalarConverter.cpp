/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:37:52 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/09 15:03:56 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& src) { (void)src; }

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs){  (void)rhs; return *this; }

ScalarConverter::~ScalarConverter() {}



void ScalarConverter::converter(const std::string& literal)
{
	double	value = 0.0;
	char *endptr = NULL;

	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else 
	{
		value = std::strtod(literal.c_str(), &endptr);

		if (*endptr != '\0' && std::string(endptr) != "f")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	if ( std::isnan(value) || std::isinf(value)|| value < std::numeric_limits<char>::min() || 
		value > std::numeric_limits<char>::max() )
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	if ( std::isnan(value) || std::isinf(value)|| value < std::numeric_limits<int>::min() || 
		value > std::numeric_limits<int>::max() )
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " <<std::fixed << std::setprecision(1) << value << std::endl; 
}