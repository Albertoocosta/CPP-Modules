/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:32:00 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/08 18:54:10 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(Intern const& src) { (void)src; }
Intern& Intern::operator=(Intern const& rhs) { (void)rhs; return *this; }
Intern::~Intern() {}

//Helpers to return the correct function

static AForm* makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm* (*formCreators[])(const std::string) = {
		&makeShrubbery,
		&makeRobotomy,
		&makePresidential
	};

	for(int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates a " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	
	std::cout << "Intern can't create the form " << formName << " because it doesn't exist in the list of forms" 
	<< std::endl;
	return NULL;
}