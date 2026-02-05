/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:59:03 by cda-fons          #+#    #+#             */
/*   Updated: 2026/02/05 17:51:13 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

class outOfBoundsException : public std::exception
{
	private:
		std::string message;
	public:
		outOfBoundsException(const std::string msg) {this->message = msg; }
		
		virtual const char* what() const throw() { return message.c_str(); }

		virtual ~outOfBoundsException() throw () {}
};

template <typename T>
class Array
{
	private:
		T*				_elements;
		unsigned int	_size;
	public:
		Array() : _elements(NULL), _size(0) {}
		
		Array(unsigned int n) : _elements(new T[n]()), _size(n) {}
		
		Array(Array const& rhs) : _elements(NULL), _size(0) { *this = rhs; }
		
		Array& operator=(Array const& rhs)
		{
			if (_elements)
				delete [] _elements;
			_size = rhs._size;
			if (_size > 0)
			{
				_elements = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = rhs._elements[i];
			}
			else
				_elements = NULL;
			return *this;
		}
		
		~Array(){
			if (_elements)
				delete[] _elements;
		}

		T& operator[](unsigned int index){
			if(index >=_size)
				throw outOfBoundsException("Index out of bounds");
			return _elements[index];
		}
		
		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw outOfBoundsException("Index out of bounds");
			return _elements[index];
		}
		
		unsigned int size() const
		{
			return _size;
		}
};

#endif