/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:32:58 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/16 13:45:16 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	
	std::cout << "----- Test1: Subject Required Test -----" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\nType Tests:" << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " "  << std::endl;

		std::cout << "\nSound Tests:" << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << "\nCleanup :" << std::endl;
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n----- Test2: WrongAnimal Test (Without using Polymorphism) -----" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << "\nType Tests:" << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << "\nSound Tests:" << std::endl;
		i->makeSound();
		meta->makeSound();

		std::cout << "\nCleanup :" << std::endl;
		delete meta;
		delete i;
	}

	std::cout << " Direct Instantiation Tests:" << std::endl;
	{
		std::cout << "\nDirect Dog:" << std::endl;
		Dog dog;
		dog.makeSound();
		std::cout << "\nType:" << dog.getType() << std::endl << std::endl;

		std::cout << "\nDirect Cat:" << std::endl;
		Cat cat;
		cat.makeSound();
		std::cout << "\nType:" << cat.getType() << std::endl << std::endl;
	}
	
	std::cout << "\nArray of Animals Tests:" << std::endl;
	{
		const int size = 4;
		Animal* animals[size];

		for (int i = 0; i < size; i++) 
		{
			if (i % 2 == 0) 
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << "\nMaking Sounds:" << std::endl;
		for (int i = 0; i < size; i++) 
		{
			animals[i]->makeSound();
		}

		std::cout << "\nCleanup:" << std::endl;
		for (int i = 0; i < size; i++) 
		{
			delete animals[i];
		}
	}

	std::cout << "\nPolymorphism Test: " << std::endl;
	{
		std::cout << "\nWith virtual:" << std::endl;
		Animal* animal = new Cat();

		animal->makeSound();

		delete animal;

		std::cout << "\nWithout virtual:" << std::endl;
		WrongAnimal* wrong_cat = new WrongCat();
		wrong_cat->makeSound();
		delete wrong_cat;
	}
	
	std::cout << "Copy constructors" << std::endl;
	{
		Dog original;
		Dog copy(original);

		std::cout << "\nOriginal and copy: " << std::endl;
		original.makeSound();
		copy.makeSound();
	}
	
	return 0;
}