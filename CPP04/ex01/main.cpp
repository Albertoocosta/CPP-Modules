/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:32:58 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/16 19:01:31 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
	
	std::cout << "----- Test1: Subject Required Test -----" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}

	std::cout << "\n----- Test2: Array of Animals Test (Dogs and Cats) -----" << std::endl;
	{
		const int size = 6;
		Animal* animals[size];
		
		std::cout << "\nCreating Animals:" << std::endl;
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
		std::cout << "\nCleaning up:" << std::endl;
		for (int i = 0; i < size; i++)
		{
			delete animals[i];
		}
	}

	std::cout << " Deep Copy Tests(Dog):" << std::endl;
	{
		std::cout << "\nCreating original Dog and Cat:" << std::endl;
		Dog originalDog;
		
		std::cout << "\nSetting ideas in original Dog's Brain:" << std::endl;
		originalDog.getBrain()->setIdea(0, "Chase the cat");
		originalDog.getBrain()->setIdea(1, "Fetch the ball");

		std::cout << "\nCreating copy of Dog using copy constructor:" << std::endl;
		
		Dog copyDog(originalDog);

		std::cout << "\nOriginal Dog's Brain Ideas:" << std::endl;
		std::cout << "Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << originalDog.getBrain()->getIdea(1) << std::endl;
		
		std::cout << "\nCopy Dog's Brain Ideas:" << std::endl;
		
		std::cout << "Idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << copyDog.getBrain()->getIdea(1) << std::endl;
		std::cout << "\nModifying copy Dog's Brain Ideas:" << std::endl;
		
		copyDog.getBrain()->setIdea(0, "Bark at the mailman");
		copyDog.getBrain()->setIdea(1, "Dig a hole");
		
		std::cout << "\nAfter modification:" << std::endl;
		
		std::cout << "Original Dog's Brain Ideas:" << std::endl;
		std::cout << "Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << originalDog.getBrain()->getIdea(1) << std::endl;

		std::cout << "Copy Dog's Brain Ideas:" << std::endl;
		std::cout << "Idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << copyDog.getBrain()->getIdea(1) << std::endl;
	

		if (originalDog.getBrain() != copyDog.getBrain())
			std::cout << "Brain copies are different." << std::endl;
		else
			std::cout << "Brain copies are the same! Deep copy failed." << std::endl;
	}
	
	std::cout << "\nDeep Copy Tests(Cat):" << std::endl;
	{
		std::cout << " \nCreating original cat: "<< std::endl;
		Cat originalCat;
		originalCat.getBrain()->setIdea(0, "Climb the tree");
		std::cout << "\nCreating copy: " << std::endl;
		Cat copyCat(originalCat);
		std::cout << "\nOriginal Cat's Brain Idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy Cat's Brain Idea 0: " << copyCat.getBrain()->getIdea(0) << std::endl;
		if (originalCat.getBrain() != copyCat.getBrain())
			std::cout << "Brain copies are different." << std::endl;
		else
			std::cout << "Brain copies are the same! Deep copy failed." << std::endl;
	}
	
	std::cout << "\nAssigment Operators" << std::endl;
	{
		Dog dog1;
		Dog dog2;

		dog1.getBrain()->setIdea(0, "Original idea");
		dog2.getBrain()->setIdea(0, "Different idea");

		std::cout << "Dog1 Ideia: " << dog1.getBrain()->getIdea(0) <<std::endl;
		std::cout << "Dog2 Ideia: " << dog2.getBrain()->getIdea(0) <<std::endl;

		dog2 = dog1;

		std::cout << "Dog1 Ideia after assigment: " << dog1.getBrain()->getIdea(0) <<std::endl;
		std::cout << "Dog2 Ideia after assigment: " << dog2.getBrain()->getIdea(0) <<std::endl;

		dog2.getBrain()->setIdea(0, "New ideia");

		std::cout << "Dog1 Ideia after modify: " << dog1.getBrain()->getIdea(0) <<std::endl;
		std::cout << "Dog2 Ideia after modify: " << dog2.getBrain()->getIdea(0) <<std::endl;

		if (dog1.getBrain() != dog2.getBrain())
			std::cout << "Brain copies are different." << std::endl;
		else
			std::cout << "Brain copies are the same! Deep copy failed." << std::endl;
		
	}
	return 0;
}