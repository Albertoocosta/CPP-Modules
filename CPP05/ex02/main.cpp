/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:10:10 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/08 17:53:01 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>   

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(std::time(0));
    
    Bureaucrat boss("Boss", 1);
    Bureaucrat manager("Manager", 45); 
    Bureaucrat intern("Intern", 150);

    std::cout << "--- TEST1 : Shrubbery" << std::endl;
    
    try {
        ShrubberyCreationForm shrub("Home");
        
        std::cout << "-> Try to execute without sign:" << std::endl;
        boss.executeForm(shrub);

        std::cout << "\n-> Signing the form:" << std::endl;
        intern.signForm(shrub);
        boss.signForm(shrub);   

        std::cout << "\n-> Executing (Creating file from Shrubbery)" << std::endl;
        intern.executeForm(shrub); 
        manager.executeForm(shrub);
    }
    catch (std::exception &e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "--- TEST2 : Robotomy" << std::endl;

    try {
        RobotomyRequestForm robot("Bender");

        std::cout << "-> Signing:" << std::endl;
        manager.signForm(robot);

        std::cout << "\n-> Testing 50% of rating:" << std::endl;
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
    }
    catch (std::exception &e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }


    try {
        PresidentialPardonForm pardon("Arthur");

        std::cout << "-> Manager try to sign:" << std::endl;
        manager.signForm(pardon);   
        manager.executeForm(pardon);

        std::cout << "\n-> Boss resolve it:" << std::endl;
        boss.signForm(pardon);      
        boss.executeForm(pardon);       }
    catch (std::exception &e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}