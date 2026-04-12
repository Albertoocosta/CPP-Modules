/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:18:05 by cda-fons          #+#    #+#             */
/*   Updated: 2026/04/12 00:40:48 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const& rhs) : _vec(rhs._vec), _deq(rhs._deq) {}
PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{
	if (this != &rhs)
	{
		_vec = rhs._vec;
		_deq = rhs._deq;
	}
	return *this;
}

std::vector<int> PmergeMe::generateSequence(int n)
{
	std::vector<int> seq;
	
	seq.push_back(0);
	seq.push_back(1);

	int last = 1;
	int prev = 0;

	while(true)
	{
		int next = last + 2 * prev;
		seq.push_back(next);
		if (next >= n)
			break;
		prev = last;
		last = next;
	}
	return seq;
}

