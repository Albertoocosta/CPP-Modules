/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:51:44 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/20 00:57:44 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << "\n=== Operators Tests ===" << std::endl;

    Fixed x(10);
    Fixed y(3);

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;  
    std::cout << "x - y = " << (x - y) << std::endl;  
    std::cout << "x * y = " << (x * y) << std::endl;  
    std::cout << "x / y = " << (x / y) << std::endl;

    std::cout << "\n=== Comparisons ===" << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;   
    std::cout << "x < y: " << (x < y) << std::endl;   
    std::cout << "x == y: " << (x == y) << std::endl; 

    std::cout << "\n=== Min/Max ===" << std::endl;

    std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;  
    std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl; 
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;
    
    return 0;
}
