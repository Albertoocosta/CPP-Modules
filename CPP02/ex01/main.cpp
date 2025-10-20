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

int	main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is -> " << a << std::endl;
	std::cout << "b is -> " << b << std::endl;
	std::cout << "c is -> " << c << std::endl;
	std::cout << "d is -> " << d << std::endl;

	std::cout << "a is -> " << a.toInt() << " as Int"<< std::endl;
	std::cout << "b is -> " << b.toInt() << " as Int" << std::endl;
	std::cout << "c is -> " << c.toInt() << " as Int" << std::endl;
	std::cout << "d is -> " << d.toInt() << " as Int" << std::endl;

	return 0;
}