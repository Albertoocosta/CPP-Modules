/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:10:48 by cda-fons          #+#    #+#             */
/*   Updated: 2025/10/19 23:05:55 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "\n=== Teste com setRawBits ===" << std::endl;
	Fixed d;
	d.setRawBits(128);  // Representa 1.0 (256 / 256)
	std::cout << "d raw bits: " << d.getRawBits() << std::endl;

	Fixed e;
	e.setRawBits(512);  // Representa 2.0 (512 / 256)
	std::cout << "e raw bits: " << e.getRawBits() << std::endl;

	return 0;
}