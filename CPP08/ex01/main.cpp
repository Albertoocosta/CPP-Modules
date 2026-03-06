/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:17:22 by cda-fons          #+#    #+#             */
/*   Updated: 2026/03/05 16:33:03 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	std::cout << "--- Subject test ---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl; // Should be 2
	std::cout << sp.longestSpan() << std::endl;  // Should be 14

	std::cout << "\n--- Stress Test (15.000 numbers) ---" << std::endl;
	Span massiveSpan(15000);
	std::vector<int> randomNumbers;

	std::srand(std::time(0));
	for (int i = 0; i < 15000; i++) {
		randomNumbers.push_back(std::rand());
	}

	try {
		massiveSpan.addRange(randomNumbers.begin(), randomNumbers.end());
		
		std::cout << "Shortest span: " << massiveSpan.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << massiveSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Exceptions tests ---" << std::endl;
	try {
		Span tiny(1);
		tiny.addNumber(42);
		tiny.shortestSpan();
	}
	catch (std::exception &e) {
		std::cout << "Exception!" << e.what() << std::endl;
	}

	return 0;
}