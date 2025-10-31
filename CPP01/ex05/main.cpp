/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 01:40:35 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/31 12:44:26 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
	
	std::cout << "All valid complaints level" << std::endl;
	std::cout << std::endl;

	harl.complain("DEBUG");
	std::cout << std::endl;
	
	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "Testing invalid level" << std::endl;
	harl.complain("INVALID");
	std::cout << std::endl;

	std::cout << "Copy constructor" << std::endl;
	Harl harlCopy(harl);
	harlCopy.complain("WARNING"); 
	std::cout << std::endl;

	std::cout << "Testing assigment operator" << std::endl;
	Harl harl2;
	harl2 = harl;
	harl2.complain("ERROR");

	return 0;
}