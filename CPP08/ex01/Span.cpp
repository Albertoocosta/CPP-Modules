/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:34:28 by cda-fons          #+#    #+#             */
/*   Updated: 2026/03/05 16:44:04 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxNumbers(0) {};
Span::Span(unsigned int maxNumbers) : _maxNumbers(maxNumbers) {};
Span::Span(Span const& rhs) : _maxNumbers(rhs._maxNumbers), _range(rhs._range) {}
Span& Span::operator=(Span const& rhs) 
{
	this->_maxNumbers = rhs._maxNumbers;
	this->_range = rhs._range;
	return *this;
}
Span::~Span(){}

const char *Span::shortSpanException::what() const throw()
{
	return ("Span is too short");
}

const char *Span::outOfBoundsException::what() const throw()
{
	return ("Out of range!");
}

void	Span::addNumber(int nbr)
{
	if (_range.size() >= _maxNumbers)
		throw outOfBoundsException();
	_range.push_back(nbr);
}

unsigned int Span::shortestSpan()
{
	if (_range.size() <= 1)
		throw shortSpanException();
	std::vector<int> sorted = _range;
	std::sort(sorted.begin(), sorted.end());
	std::adjacent_difference(sorted.begin(), sorted.end(), sorted.begin());
	return (*std::min_element(sorted.begin() + 1, sorted.end()));
	
}

unsigned int Span::longestSpan()
{
	int min = *std::min_element(_range.begin(), _range.end());
	int max = *std::max_element(_range.begin(), _range.end());
	return (static_cast<unsigned int>(max - min));
}