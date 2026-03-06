/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:35:33 by cda-fons          #+#    #+#             */
/*   Updated: 2026/03/05 16:43:37 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <exception>
# include <algorithm>
# include <numeric>

class Span 
{
	private:
		unsigned int		_maxNumbers;
		std::vector<int>	_range;
		
	public:
		Span();
		Span(unsigned int maxNumbers);
		Span(Span const& rhs);
		Span& operator=(const Span& rhs);
		~Span();

		void				addNumber(int nbr);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
		template <typename GHOST>
		void	addRange(GHOST begin, GHOST end)
		{
			if (std::distance(begin, end) + _range.size() > _maxNumbers)
				throw outOfBoundsException();
			_range.insert(_range.end(), begin, end);
		}
		
		class shortSpanException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

		class outOfBoundsException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
};


#endif