/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:10:10 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/07 17:10:11 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n--- TEST 1: ---" << std::endl;
    
    try {
        std::cout << "Try to create a form with gradeToSign 0..." << std::endl;
        Form f1("InvalidForm", 0, 50);
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "Try to create a form with gradeRequired 151..." << std::endl;
        Form f2("InvalidForm2", 50, 151);
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form f3("ValidForm", 50, 100);
        std::cout << "Sucess: " << f3 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: ---" << std::endl;
    
    try {
        Bureaucrat junior("Junior", 100);
        Form importantForm("Important Contract", 50, 100);

        std::cout << "Initial state: " << importantForm << std::endl;
                junior.signForm(importantForm);

        std::cout << "Final state: " << importantForm << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Erro na criação: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: ---" << std::endl;

    try {
        Bureaucrat senior("Senior", 40);
        Form standardForm("Standard Paperwork", 50, 100);

        std::cout << "Initial state: " << standardForm << std::endl;

        senior.signForm(standardForm);

        std::cout << "Final state: " << standardForm << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Create error: " << e.what() << std::endl;
    }

    return 0;
}