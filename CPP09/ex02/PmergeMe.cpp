/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:18:05 by cda-fons          #+#    #+#             */
/*   Updated: 2026/04/14 00:49:29 by cda-fons         ###   ########.fr       */
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

void	PmergeMe::sortVector(std::vector<int>& arr)
{
	if(arr.size() < 2)
		return;
	bool hasRemaining = arr.size() % 2 != 0;
	int remaining = -1;
	if (hasRemaining)
	{
		remaining = arr.back();
		arr.pop_back();
	}
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	for (size_t i = 0;i < pairs.size(); i++)
	{
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i].first > pairs[j].first)
				std::swap(pairs[i], pairs[j]);
		}
	}
	std::vector<int> mainChain;
	std::vector<int> pend;

	for(size_t i =0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	mainChain.insert(mainChain.begin(), pend[0]);
	insertVector(mainChain, pend);
	if (hasRemaining)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), remaining);
		mainChain.insert(it, remaining);
	}

	arr = mainChain;
}

void	PmergeMe::insertVector(std::vector<int>& mainChain, std::vector<int>& pend)
{
	if (pend.size() <= 1)
		return;
	std::vector<int> jacobSeq = generateSequence(pend.size());
	
	int lastInsertIndex = 0;

	for(size_t i = 2; i< jacobSeq.size(); i++)
	{
		int jacobIndex = jacobSeq[i];
		if (jacobIndex > (int)pend.size() - 1)
			jacobIndex = pend.size() - 1;

		int currentIndex = jacobIndex;
		while(currentIndex > lastInsertIndex)
		{
			int valueToInsert = pend[currentIndex];
			
			std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
			mainChain.insert(it, valueToInsert);
			
			currentIndex --;
		}
		lastInsertIndex = jacobIndex;
	}
}

void	PmergeMe::sortDeque(std::deque<int>& arr)
{
	if(arr.size() < 2)
		return;
	bool hasRemaining = arr.size() % 2 != 0;
	int remaining = -1;
	if (hasRemaining)
	{
		remaining = arr.back();
		arr.pop_back();
	}

	std::deque<std::pair<int, int>> pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i].first > pairs[j].first)
				std::swap(pairs[i], pairs[j]);
		}
	}

	std::deque<int> mainChain;
	std::deque<int> pend;

	for(size_t i =0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	mainChain.insert(mainChain.begin(), pend[0]);
	insertDeque(mainChain, pend);

	if (hasRemaining)
	{
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), remaining);
		mainChain.insert(it, remaining);
	}
	
	arr = mainChain;
}

void	PmergeMe::insertDeque(std::deque<int>& mainChain, std::deque<int>& pend)
{
	if (pend.size() <= 1)
		return;
	std::vector<int> TempjacobSeq = generateSequence(pend.size());
	std::deque<int> jacobSeq(TempjacobSeq.begin(), TempjacobSeq.end());
	
	int lastInsertIndex = 0;

	for(size_t i = 2; i< jacobSeq.size(); i++)
	{
		int jacobIndex = jacobSeq[i];
		if (jacobIndex > (int)pend.size() - 1)
			jacobIndex = pend.size() - 1;

		int currentIndex = jacobIndex;
		while(currentIndex > lastInsertIndex)
		{
			int valueToInsert = pend[currentIndex];
			
			std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
			mainChain.insert(it, valueToInsert);
			
			currentIndex --;
		}
		lastInsertIndex = jacobIndex;
	}
}


void	PmergeMe::execute(int ac, char **av)
{
	if (ac < 2)
		throw std::runtime_error("Error: No numbers provided.");
	try
	{
		for (int i = 1; i < ac; i++)
		{
			std::string arg = av[i];
			for (size_t j = 0; j< arg.length(); j++)
			{
				if (!isdigit(arg[j]))
					throw std::runtime_error("Error: One of params is not a number");
			}
			long val = std::atol(arg.c_str());
			if (val < 0 || val > INT_MAX)
				throw std::runtime_error("Error: Negative numbers or bigger than int max");
			_vec.push_back(static_cast<int>(val));
			_deq.push_back(static_cast<int>(val));
		}

		for (size_t i = 0; i < _vec.size(); i++)
			std::cout << _vec[i] << " ";
		std::cout << std::endl;

		struct timeval start, end;
		gettimeofday(&start, NULL);
		sortVector(_vec);
		gettimeofday(&end, NULL);
		double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

		gettimeofday(&start, NULL);
		sortDeque(_deq);
		gettimeofday(&end, NULL);
		double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

		// std::cout << "After sort: " << std::endl;
		// for (size_t i = 0; i < _vec.size(); i++)
		// {
		// 	std::cout << _vec[i] << " ";
		// 	std::cout << std::endl;
		// }

		std::cout << "Time to process a range of " << _vec.size() 
				<< " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << _deq.size() 
				<< " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}