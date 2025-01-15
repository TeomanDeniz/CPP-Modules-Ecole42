/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <iostream> /*
#nmspace std;
#        */
#include <stack> /*
#  class std::stack;
#        */
#include "RPN.hpp" /*
#  class RPN;
#        */
#include <sstream> /*
#  class std::istringstream;
#        */
#include <cstdlib> /*
#    int std::atoi(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::string;
using std::cout;
using std::endl;
using std::stack;
/* ***************************** [^] USINGS [^] ***************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
RPN::~RPN() {}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
RPN
	&RPN::operator = (const RPN &other)
{
	if (this != &other)
		this->_stack = other._stack;

	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

int
	RPN::checkInput(string str)
{
	int		i;
	string	operators = "+-*/";

	for (i = 0; i < (int)str.length(); i++)
	{
		if (str[i] == ' ')
			continue ;

		if (isdigit(str[i]) == 0 && operators.find(str[i]) == std::string::npos)
			return (0);
	}

	return (1);
}

void
	RPN::calculate(std::string str)
{
	stack<int>			stack;
	const string		operators = "+-*/";
	std::istringstream	iss(str);
	string				token;

	if (!checkInput(str))
		throw std::runtime_error("Invalid RPN expression");
	while (iss >> token)
	{
		if (token.size() == 1 && operators.find(token) != std::string::npos)
		{
			if (stack.size() < 2)
				throw std::runtime_error("Invalid RPN expression");

			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			if (token == "+")
				stack.push(a + b);
			else if (token == "-")
				stack.push(a - b);
			else if (token == "*")
				stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Division by zero");
				stack.push(a / b);
			}
		}
		else if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1])))
		{
			stack.push(std::atoi(token.c_str()));
		}
		else
		{
			throw std::runtime_error("Invalid token in RPN expression");
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Invalid RPN expression");

	std::cout << "Result: " << stack.top() << std::endl;
}
