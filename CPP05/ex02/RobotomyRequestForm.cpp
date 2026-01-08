/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:13:18 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/08 14:28:29 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
AForm(" Robotomy Request Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) :
AForm(src), _target(src._target) 
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeRequired())
		throw AForm::GradeTooLowException();
	
	std::cout << "*STUPID DRILLING NOISES*" << std::endl;
	
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully! " << std::endl;
	else
		std::cout <<  "Robotomy failed on " << _target << std::endl;
}