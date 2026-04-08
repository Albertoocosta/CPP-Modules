/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:59:01 by cda-fons          #+#    #+#             */
/*   Updated: 2026/04/08 23:26:10 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}
	
	BitcoinExchange btc;

	btc.loadDatabase("data.csv");

	btc.evaluateInput(av[1]);
	
}
 