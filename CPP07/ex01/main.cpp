/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:34:52 by cda-fons          #+#    #+#             */
/*   Updated: 2026/02/04 21:47:09 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void printElement(const T& element)
{
	std::cout << element << " " << std::endl;
}

void increment (int& n)
{
	n++;
}


int main()
{
	std::cout << "--- Test1: Int array (increment) ---" << std::endl;
	int arrayInt[] = {0, 1, 2, 3, 4};
	size_t lenInt = 5;

	std::cout << "Original : " << std::endl;
	::iter(arrayInt, lenInt, printElement<int>);
	std::cout << std::endl;
	
	std::cout << "Incrementing..." << std::endl;
	::iter(arrayInt, lenInt, increment);
	std::cout << std::endl;

	std::cout << "Modified : " << std::endl;
	::iter(arrayInt, lenInt, printElement<int>);
	std::cout << std::endl;

	std::cout << "--- Test2: Const float array ---" << std::endl;
	const float arrayFloat[] = {1.1f, 2.2f, 3.3f};
	size_t lenFloat = 3;

	std::cout << "Values : " << std::endl;
	::iter(arrayFloat, lenFloat, printElement<const float>);
	std::cout << std::endl;
	
	// #################### If uncomment it, the compiler doesn't compile. ##########################################
	// std::cout << "Incrementing..." << std::endl;
	// ::iter(arrayFloat, lenFloat, increment);
	// std::cout << std::endl;
	// ################### The template respect the const type #####################################################

	std::cout << "--- Test3: String array ---" << std::endl;
	std::string arrayStr[] = {"Hello", "42er", "How's", "it", "going?"};
	size_t lenStr = 5;
	
	::iter(arrayStr, lenStr, printElement<std::string>);
	std::cout << std::endl;
	
}