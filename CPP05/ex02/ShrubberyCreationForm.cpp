/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:26:09 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/08 14:12:26 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) :
AForm(src), _target(src._target) 
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeRequired())
		throw AForm::GradeTooLowException();
	
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "    ^^^^^^^    " << std::endl;
        file << "    ^^^^^^^    " << std::endl;
        file << "    ^^^^^^^    " << std::endl;
        file << "    ^^^^^^^    " << std::endl;
        file << "       |       " << std::endl;
        file.close();
	}
}