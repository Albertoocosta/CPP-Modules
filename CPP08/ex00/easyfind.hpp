/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:03:57 by cda-fons          #+#    #+#             */
/*   Updated: 2026/03/04 17:36:27 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <list>
# include <deque>
# include <vector>
# include <algorithm>

template <typename T>
void		easyfind(T& data, int nbr)
{
	typename T::iterator it = std::find(data.begin(), data.end(), nbr);
	if (it == data.end())
		throw std::exception();
	std::cout << "FOUND IT!" << std::endl;
}

#endif