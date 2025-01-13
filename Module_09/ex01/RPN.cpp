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
#include <sstream> /*
#   T <> stringstream;
#        */
#include <stack> /*
#  class std::stack;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::string;
using std::cout;
using std::endl;
using std::stringstream;
using std::stack;
/* ***************************** [^] USINGS [^] ***************************** */

static int
	numSize(string arg)
{
	int	size;
	int	i;

	size = 0;

	for (i = 0; arg[i]; i++)
		if ('0' <= arg[i] && arg[i] <= '9')
			++size;

	return (size);
}

static int
	operatorSize(string arg)
{
	int	size;
	int	i;

	size = 0;

	for (i = 0; arg[i]; i++)
		if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
			++size;

	return (size);
}

static void
	check_RPN_format(string arg)
{
	int	i;

	if (arg.length() == 0)
		throw std::runtime_error("Error");

	if (arg.find_first_not_of("0123456789-+*/ \r\n\t") != string::npos)
		throw std::runtime_error("Error");

	if (numSize(arg) - operatorSize(arg) != 1)
		throw std::runtime_error("Error");

	if (numSize(arg) + operatorSize(arg) < 2)
		throw std::runtime_error("Error");

	for (i = 0; i < (int)arg.length(); i++)
	{
		if (isalnum(arg.c_str()[i]) && !!arg.c_str()[i + 1] && \
			!isspace(arg.c_str()[i + 1]))
			throw std::runtime_error("Error");
		else if (!isalnum(arg.c_str()[i]) && !isspace(arg.c_str()[i]) \
			&& !!arg.c_str()[i + 1] && !isspace(arg.c_str()[i + 1]))
			throw std::runtime_error("Error");
	}
}

static int
	my_stoi(const string &str)
{
	std::istringstream	iss(str);
	int					result;

	if (!(iss >> result))
		throw std::invalid_argument("Invalid argument");

	return (result);
}

void
	RPN_calculator(string arg)
{
	check_RPN_format(arg);

	stack <int>		numbers;
	stringstream	ss(arg);
	string			token;

	while (ss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			int	n1;
			int	n2;
			int	result;

			if (numbers.size() < 2)
				throw std::invalid_argument("Error");

			n1 = numbers.top();
			numbers.pop();
			n2 = numbers.top();
			numbers.pop();

			if (token == "+")
				result = n1 + n2;
			else if (token == "-")
				result = n1 - n2;
			else if (token == "*")
				result = n1 * n2;
			else if (token == "/")
			{
				if (n2 == 0)
					throw std::runtime_error("Error");

				result = n1 / n2;
			}

			numbers.push(result);
		}
		else
		{
			int num = my_stoi(token);
			numbers.push(num);
		}
	}

	cout << numbers.top() << endl;
}
