/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 22:53:32 by cda-fons          #+#    #+#             */
/*   Updated: 2026/04/09 23:26:02 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(RPN const& rhs) : _stack(rhs._stack){}
RPN& RPN::operator=(RPN const& rhs)
{
	if(this != &rhs)
		this->_stack = rhs._stack;
	return *this;
}
RPN::~RPN(){}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void	RPN::operation(const std::string& op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Stack too small");
	int right = _stack.top();
	_stack.pop();
	int left = _stack.top();
	_stack.pop();

	int result = 0;

	if (op == "+")
		result = left + right;
	else if (op == "-")
		result = left - right;
	else if (op == "*")
		result = left * right;
	else if (op == "/")
	{
		if (right == 0)
			throw std::runtime_error("Division by zero");
		result = left / right;
	}

	_stack.push(result);
}

