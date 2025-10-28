/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:16:50 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/20 00:28:03 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
        
		Fixed(const int value);
		Fixed(const float value);
        
		float toFloat(void) const;
		int toInt(void) const;
        
		int getRawBits(void) const;
		void setRawBits(int const raw);
    
        bool operator<(const Fixed& rhs) const;
        bool operator>(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;

        Fixed operator+(const Fixed& rhs) const;
        Fixed operator-(const Fixed& rhs) const;
        Fixed operator*(const Fixed& rhs) const;
        Fixed operator/(const Fixed& rhs) const;

        Fixed& operator++();            // Prefix increment
        Fixed operator++(int);          // Postfix increment
        Fixed& operator--();            // Prefix decrement
        Fixed operator--(int);          // Postfix decrement

        static Fixed& min(Fixed& a, Fixed& b);
        static const  Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};
    
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif