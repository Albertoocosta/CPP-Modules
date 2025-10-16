/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:33:09 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/16 16:29:37 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* brainPTR = &brain;
	std::string& brainREF = brain;

	std::cout << "variable brain address: "<< &brain << std::endl;
	std::cout << "Adress in brainPTR: " << brainPTR << std::endl;
	std::cout << "brain variable Reference in brainREF: " << &brainREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value in brain variable: " << brain << std::endl;
	std::cout << "Value in brain variable from brainPTR: " << *brainPTR << std::endl;
	std::cout << "Value in brain variable from brainREF: " << brainREF << std::endl;
}