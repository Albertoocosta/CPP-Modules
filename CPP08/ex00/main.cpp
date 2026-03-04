/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:03:54 by cda-fons          #+#    #+#             */
/*   Updated: 2026/03/04 17:41:09 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::cout << "\n----------VECTOR TEST --------------" << std::endl;
	std::vector<int> vect;
	
	vect.push_back(5);
	vect.push_back(4);
	vect.push_back(3);
	vect.push_back(2);
	vect.push_back(10);
	
	try
	{
		easyfind(vect, 5);
		easyfind(vect, 4);
		easyfind(vect, 3);
		easyfind(vect, 7);
		easyfind(vect, 1); // not attached
		
	}
	catch (std::exception &e)
	{
		(void)e;
		std::cerr << "IT DOESN'T EXIST IN THIS RANGE!" << std::endl;
	}

	std::cout << "\n----------LIST TEST --------------" << std::endl;
	std::list<int> lixt;
	
	lixt.push_back(5);
	lixt.push_back(4);
	lixt.push_back(3);
	lixt.push_back(2);
	lixt.push_back(10);
	
	try
	{
		easyfind(lixt, 5);
		easyfind(lixt, 4);
		easyfind(lixt, 3);
		easyfind(lixt, 7);
		easyfind(lixt, 1);// not attached
		
	}
	catch (std::exception &e)
	{
		(void)e;
		std::cerr << "IT DOESN'T EXIST IN THIS RANGE!" << std::endl;
	}

	std::cout << "\n----------DEQUE TEST --------------" << std::endl;
	std::deque<int> dqueue;
	
	dqueue.push_back(5);
	dqueue.push_back(4);
	dqueue.push_back(3);
	dqueue.push_back(2);
	dqueue.push_back(10);
	
	try
	{
		easyfind(dqueue, 5);
		easyfind(dqueue, 4);
		easyfind(dqueue, 3);
		easyfind(dqueue, 7);
		easyfind(dqueue, 1);// not attached
		
	}
	catch (std::exception &e)
	{
		(void)e;
		std::cerr << "IT DOESN'T EXIST IN THIS RANGE!" << std::endl;
	}
}