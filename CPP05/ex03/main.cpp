/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:10:10 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/08 18:54:53 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    AForm* rrf = NULL;

    std::cout << "--- TEST 1: Valid Form(Robotomy) ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        
        delete rrf; 
        rrf = NULL;
    }

    std::cout << "\n--- TEST 2: Invalid Form ---" << std::endl;
    rrf = someRandomIntern.makeForm("unpaid overtime request", "Employee");

    if (rrf) {
        std::cout << "This message can't appears." << std::endl;
        delete rrf;
    }

    std::cout << "\n--- TEST 3: Creation loop (Shrubbery) ---" << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    return 0;
}