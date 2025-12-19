/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:33:39 by cda-fons          #+#    #+#             */
/*   Updated: 2025/12/19 17:43:59 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		increment();
		void		decrement();

		class GradeTooHighException
		{
			public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException
		{
			public:
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);

#endif