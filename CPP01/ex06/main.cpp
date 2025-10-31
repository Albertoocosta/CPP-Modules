/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 02:29:18 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/31 12:45:35 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		std::cerr << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	Harl harl;
	std::string level = argv[1];
	harl.filter(level);
	return 0;
}