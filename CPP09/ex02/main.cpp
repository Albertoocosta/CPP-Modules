/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:19:17 by cda-fons          #+#    #+#             */
/*   Updated: 2026/04/13 21:04:17 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
		return 1;
	}

	PmergeMe sorter;
	
	sorter.execute(ac, av);
	
	return 0;
}