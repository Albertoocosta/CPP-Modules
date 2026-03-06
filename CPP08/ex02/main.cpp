/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:03:37 by cda-fons          #+#    #+#             */
/*   Updated: 2026/03/06 16:06:00 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "--- First test: MutantStack  ---" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "\nTop: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "\nSize: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << "\nIterating through MutantStack:" << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n--- Second Test: std::list (to compare the output) ---" << std::endl;
	{
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << "\nTop: " << mlist.back() << std::endl;
		mlist.pop_back(); 
		std::cout << "\nSize: " << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;
		std::cout << "\nIterating through std::list:" << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}