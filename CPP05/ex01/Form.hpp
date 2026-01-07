/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:05:52 by cda-fons          #+#    #+#             */
/*   Updated: 2026/01/07 17:13:11 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;
class Form
{
	private:

		const std::string 	_name;
		bool 				_isSigned;
		const int 			_gradeToSign;
		const int 			_gradeRequired;

	public:

		Form();
		Form(const std::string name, int gradeToSign, int gradeRequired);
		Form(Form const& src);
		Form& operator=(Form const& rhs);
		~Form();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeRequired() const;

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
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif
