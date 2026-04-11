/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 22:53:32 by cda-fons          #+#    #+#             */
/*   Updated: 2026/04/11 17:03:25 by cda-fons         ###   ########.fr       */
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
		throw std::runtime_error("Error");
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
			throw std::runtime_error("Error");
		result = left / right;
	}

	_stack.push(result);
}

int RPN::calculate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		if (isOperator(token))
			operation(token);
		else
		{
			if (token.length() != 1 || !isdigit(token[0]))
				throw std::runtime_error("Error");
			int num = std::atoi(token.c_str());
			_stack.push(num);
		}
	}
	if(_stack.size() != 1)
		throw std::runtime_error("Error");

	int result = _stack.top();

	_stack.pop();

	return(result);
}