/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:05:47 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/07 17:17:39 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeRequired(100), _gradeToSign(150)
{
}

Form::Form(const std::string name, int gradeToSign, int gradeRequired) : 
	_name (name), _isSigned(false), _gradeToSign(gradeToSign), _gradeRequired(gradeRequired)
{
	if (gradeRequired < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeRequired > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

const std::string& Form::getName() const { return (this->_name); }
bool	Form::getIsSigned() const { return (this->_isSigned); }
int		Form::getGradeToSign() const { return(this->_gradeToSign); }
int		Form::getGradeRequired() const { return (this->_gradeRequired); }

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

Form::Form(Form const& src) : 
	_name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), 
	_gradeRequired(src._gradeRequired) 
{}

Form& Form::operator=(Form const& rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

void Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

Form::~Form() {}

std::ostream& operator<<(std::ostream& out, Form const& obj)
{
	out << "Form " << obj.getName() << ", is signed: (" << (obj.getIsSigned() ? "yes" : "no") <<
	"), the grade to sign is: " << obj.getGradeToSign() << " and the grade to validate it is: " <<
	obj.getGradeRequired() << "." << std::endl;
	return out;
}
