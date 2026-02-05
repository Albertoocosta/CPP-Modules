/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:12:03 by cda-fons          #+#    #+#             */
/*   Updated: 2026/02/05 17:52:45 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ()
{
	std::cout << " --- Test1 : Simple Int Array---" << std::endl;
	Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << "--- TEST 2: Deep Copy Check ---" << std::endl;
	Array<int> copy = numbers;
	
	std::cout << "Original[0] before:	" << numbers[0] << std::endl;
	std::cout << "Copy[0] before:		" << copy[0] << std::endl;

	copy[0] = 999;

	std::cout << "Original[0] after:  " << numbers[0] << " (Should be 0)" << std::endl;
	std::cout << "Copy[0] after:      " << copy[0] << " (Should be 999)" << std::endl;

	if (numbers[0] != copy[0])
		std::cout << "SUCCESS: Deep copy worked!" << std::endl;
	else
		std::cout << "FAILURE: Shallow copy detected!" << std::endl;

	std::cout << "\n--- TEST 3: Out of Bounds Exception ---" << std::endl;
	try {
		std::cout << "Accessing index 100..." << std::endl;
		std::cout << numbers[100] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "SUCCESS: Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4: Empty Array ---" << std::endl;
	Array<int> empty;
	std::cout << "Size of empty: " << empty.size() << std::endl;
	try {
		empty[0] = 1;
	} 
	catch (std::exception& e) {
		std::cout << "SUCCESS: Caught access to empty array." << std::endl;
	}

	return 0;
}