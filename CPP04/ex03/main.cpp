/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:30:42 by cda-fons          #+#    #+#             */
/*   Updated: 2025/11/24 21:03:18 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "Tests from subject" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	
	std::cout << "\n=== Test 2: More Complex Scenario ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        
        std::cout << "Learning materias..." << std::endl;
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());  // Duplicate OK
        
        ICharacter* hero = new Character("Hero");
        ICharacter* enemy = new Character("Enemy");
        
        std::cout << "\nEquipping Hero..." << std::endl;
        AMateria* tmp;
        tmp = src->createMateria("ice");
        hero->equip(tmp);
        tmp = src->createMateria("cure");
        hero->equip(tmp);
        tmp = src->createMateria("ice");
        hero->equip(tmp);
        tmp = src->createMateria("cure");
        hero->equip(tmp);
        
        std::cout << "\nTrying to equip 5th materia (should do nothing)..." << std::endl;
        tmp = src->createMateria("ice");
        hero->equip(tmp);  // Inventory full!
        delete tmp;  // Must delete since it wasn't equipped
        
        std::cout << "\nUsing materias..." << std::endl;
        hero->use(0, *enemy);  // Ice
        hero->use(1, *enemy);  // Cure
        hero->use(2, *enemy);  // Ice
        hero->use(3, *enemy);  // Cure
        hero->use(4, *enemy);  // Nothing (out of bounds)
        
        std::cout << "\nUnequipping and re-equipping..." << std::endl;
        AMateria* saved = src->createMateria("cure");
        hero->unequip(0);  // Remove ice from slot 0
        hero->equip(saved);  // Add cure to slot 0
        hero->use(0, *enemy);  // Should be cure now
        
        delete enemy;
        delete hero;
        delete src;
    }
    
    std::cout << "\n=== Test 3: Deep Copy Test ===" << std::endl;
    {
        Character original("Original");
        
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        
        AMateria* ice1 = src->createMateria("ice");
        AMateria* ice2 = src->createMateria("ice");
        original.equip(ice1);
        original.equip(ice2);
        
        std::cout << "\nCopying character..." << std::endl;
        Character copy(original);
        
        std::cout << "\nOriginal uses materia:" << std::endl;
        Character dummy("Dummy");
        original.use(0, dummy);
        
        std::cout << "\nCopy uses materia:" << std::endl;
        copy.use(0, dummy);
        
        delete src;
    }
    
    std::cout << "\n=== Test 4: Unknown Materia Type ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        
        AMateria* unknown = src->createMateria("fire");  // Unknown type
        if (unknown == NULL)
            std::cout << "Correctly returned NULL for unknown type" << std::endl;
        else
            std::cout << "Should have returned NULL" << std::endl;
        
        delete src;
    }


	return 0;
}