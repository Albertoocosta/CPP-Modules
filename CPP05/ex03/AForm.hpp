/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:05:52 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/08 18:02:32 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		const std::string 	_name;
		bool 				_isSigned;
		const int 			_gradeToSign;
		const int 			_gradeRequired;

	public:

		AForm();
		AForm(const std::string name, int gradeToSign, int gradeRequired);
		AForm(AForm const& src);
		AForm& operator=(AForm const& rhs);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeRequired() const;


		virtual void execute(Bureaucrat const& executor) const = 0;
		
		
		void	beSigned(Bureaucrat const& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif
