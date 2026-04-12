/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:19:15 by cda-fons          #+#    #+#             */
/*   Updated: 2026/04/11 22:20:58 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <cmath>

class PmergeMe
{
	private:
		std::vector<int>_vec;
		std::deque<int>_deq;

		void sortVector(std::vector<int>& arr);
		void insertVector(std::vector<int&> mainChain, std::vector<int>& pend);

		void sortDeque(std::deque<int>& arr);
		void insertDeque(std::deque<int&> mainChain, std::deque<int>& pend);

		std::vector<int> generateSequence(int n);
	public:

		PmergeMe();
		PmergeMe(PmergeMe const& rhs);
		PmergeMe& operator=(PmergeMe const& rhs);
		~PmergeMe();

		void	execute(int ac, char **av);

};

#endif