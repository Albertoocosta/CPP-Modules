/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:44:00 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/09 19:58:37 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	Data myData;
	myData.name = "Top Secret";
	myData.value = 42;
	myData.price = 99.99;

	std::cout << "Original Pointer: " << &myData << std::endl;
	std::cout << "Original Data:    " << myData.name << " | " << myData.value << std::endl;

	uintptr_t raw = Serializer::serialize(&myData);

	std::cout << "Serialized (raw): " << raw << " (decimal)" << std::endl;

	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Deserialized Ptr: " << ptr << std::endl;

	if (ptr == &myData) {
		std::cout << "SUCCESS: Pointers match!" << std::endl;
		std::cout << "Restored Data:    " << ptr->name << " | " << ptr->value << std::endl;
	} else {
		std::cout << "FAILURE: Pointers do not match." << std::endl;
	}
	return 0;
}
