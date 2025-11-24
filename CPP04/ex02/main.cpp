/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:32:58 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/22 18:27:44 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "=== Test 1: Cannot Instantiate Animal (Abstract) ===" << std::endl;
    //Animal* animal = new Animal();  // Compilation Error 
    std::cout << "Animal cannot be instantiated (it's abstract)" << std::endl;
    std::cout << std::endl;
    
    std::cout << "=== Test 2: Dog and Cat Still Work ===" << std::endl;
    {
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        
        std::cout << "\nTypes:" << std::endl;
        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;
        
        std::cout << "\nSounds:" << std::endl;
        dog->makeSound();
        cat->makeSound();
        
        std::cout << "\nDeletion:" << std::endl;
        delete dog;
        delete cat;
    }
    
    std::cout << "\n=== Test 3: Array of Animals ===" << std::endl;
    {
        const int size = 4;
        Animal* animals[size];
        
        std::cout << "\nCreating animals:" << std::endl;
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();
        
        std::cout << "\nAll animals make sound:" << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << i << ": ";
            animals[i]->makeSound();
        }
        
        std::cout << "\nDeleting all:" << std::endl;
        for (int i = 0; i < size; i++)
        {
            delete animals[i];
        }
    }
    
    std::cout << "\n=== Test 4: Deep Copy Still Works ===" << std::endl;
    {
        Dog original;
        original.getBrain()->setIdea(0, "Original idea");
        
        Dog copy(original);
        copy.getBrain()->setIdea(0, "Copy idea");
        
        std::cout << "\nOriginal idea: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl;
        
        if (original.getBrain() != copy.getBrain())
            std::cout << "Deep copy still working!" << std::endl;
        else
            std::cout << "Shallow copy!" << std::endl;
    }
    
    std::cout << "\n=== Test 5: Polymorphism Still Works ===" << std::endl;
    {
        Animal* animals[2];
        animals[0] = new Dog();
        animals[1] = new Cat();
        
        std::cout << "\nPolymorphic calls:" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
            animals[i]->makeSound();
        }
        
        for (int i = 0; i < 2; i++)
        {
            delete animals[i];
        }
    }
    
    std::cout << "\n=== Test 6: Direct Dog/Cat Instantiation ===" << std::endl;
    {
        Dog dog;  // Dog isn't abstract
        Cat cat;  // Cat isn't abstract
        
        std::cout << "Direct instantiation works!" << std::endl;
        dog.makeSound();
        cat.makeSound();
    }
    
    return 0;
}