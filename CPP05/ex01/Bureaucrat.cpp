/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:32:58 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/06 21:12:14 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : name (name),  grade(grade)
{
		if (grade > 150)
			throw GradeTooLowException();
		else if (grade < 1)
			throw GradeTooHighException();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		this->grade = rhs.grade;
	return (*this);
}

int Bureaucrat::getGrade() const { return this->grade; }
std::string Bureaucrat::getName() const { return this->name; }

void	Bureaucrat::increment()
{
	if ((getGrade() - 1) <= 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void	Bureaucrat::decrement()
{
	if ((getGrade() + 1) >= 150)
		throw GradeTooLowException();
	else
		this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

Bureaucrat::~Bureaucrat() {}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (os);
}