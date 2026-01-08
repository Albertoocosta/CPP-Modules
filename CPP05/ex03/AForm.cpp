/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:05:47 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/08 18:16:14 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeRequired(100), _gradeToSign(150)
{
}

AForm::AForm(const std::string name, int gradeToSign, int gradeRequired) : 
	_name (name), _isSigned(false), _gradeToSign(gradeToSign), _gradeRequired(gradeRequired)
{
	if (gradeRequired < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeRequired > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

const std::string& AForm::getName() const { return (this->_name); }
bool	AForm::getIsSigned() const { return (this->_isSigned); }
int		AForm::getGradeToSign() const { return(this->_gradeToSign); }
int		AForm::getGradeRequired() const { return (this->_gradeRequired); }

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed yet.");
}

AForm::AForm(AForm const& src) : 
	_name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), 
	_gradeRequired(src._gradeRequired) 
{}

AForm& AForm::operator=(AForm const& rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

void AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream& out, AForm const& obj)
{
	out << "Form " << obj.getName() << ", is signed: (" << (obj.getIsSigned() ? "yes" : "no") <<
	"), the grade to sign is: " << obj.getGradeToSign() << " and the grade to validate it is: " <<
	obj.getGradeRequired() << "." << std::endl;
	return out;
}
