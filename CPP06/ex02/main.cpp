/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:40:33 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/10 01:12:20 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	int i = rand() % 3;

	switch (i)
	{
		case 0:
			std::cout << "Generate A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generate B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generate C" << std::endl;
			return new C();
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		return;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		return;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
		return;
	}
	catch(...){}
	std::cout << "Unknown type" << std::endl;
}

int main()
{
	std::srand(std::time(0));
	std::cout << "--- TEST 1: Pointer Identification ---" << std::endl;
	Base* ptr = generate();
	identify(ptr);

	std::cout << "\n--- TEST 2: Reference Identification ---" << std::endl;
	identify(*ptr);

	delete ptr;

	std::cout << "\n--- TEST 3: Loop Test ---" << std::endl;
	for (int i = 0; i < 5; i++) {
		Base* tmp = generate();
		identify(tmp);
		identify(*tmp);
		delete tmp;
		std::cout << "-----------------" << std::endl;
	}

	return 0;
}
