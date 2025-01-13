/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* **************************** [v] INCLUDES [v] **************************** */
#include "PmergeMe.hpp" /*
#  class PmergeMe;
#        */
#include <vector> /*
#   T <> vector;
#        */
#include <deque> /*
#  class std::deque;
#        */
#include <iostream> /*
#nmspace std;
#        */
#include <sstream> /*
#   T <> istringstream;
#        */
#include <ctime> /*
#typedef clock_t;
#clock_t clock (void);
#        */
#include <iomanip> /*
#   T <> setprecision(int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::vector;
using std::deque;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
/* ***************************** [^] USINGS [^] ***************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
PmergeMe::PmergeMe(void){}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
PmergeMe::~PmergeMe(void){}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
PmergeMe
	&PmergeMe::operator = (const PmergeMe &other) /* OPERATOR "=" */
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}

	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	PmergeMe::printVector(void)
{
	int	i;

	i = 0;
	vector <int>::iterator it = this->_vector.begin();

	while (it < this->_vector.end())
	{
		cout << "[" << *it << "]";

		if (++i > 30)
		{
			cout << " [...]";
			break ;
		}

		++it;
	}

	cout << endl;
}

void
	PmergeMe::printDeque(void)
{
	int	i;

	i = 0;

	for (
		deque<int>::iterator it = this->_deque.begin();
		it != this->_deque.end();
		++it
	)
	{
		cout << "[" << *it << "]";

		if (++i > 30)
		{
			cout << " [...]";
			break ;
		}
	}

	cout << endl;
}

void
	PmergeMe::isalnum(char *arr)
{
	string	str;

	str = arr;

	if (str[0] == '-')
		throw "Error: not a positive number.";

	if (str.length() > 10 || (str.length() == 10 && str > "2147483647"))
		throw "Error: too large a number.";

	while (*arr)
	{
		if (!isdigit(*arr) && !str.empty())
			throw "Error: not a number.";

		++arr;
	}
}

void
	PmergeMe::sort(char **arr)
{
	clock_t	start;
	clock_t	end;
	double	Vtime;
	double	Dtime;
	int		i;
	int		nb;

	nb = 0;

	for (i = 1; arr[i]; i++)
	{
		isalnum(arr[i]);
		istringstream(arr[i]) >> nb;
		this->_vector.push_back(nb);
		this->_deque.push_back(nb);
	}

	cout << "Vector Before :";
	printVector();
	start = clock();
	merge_sort(this->_vector, 0, this->_vector.size() - 1);
	end = clock();
	Vtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	cout << "Deque Before :";
	printDeque();
	start = clock();
	merge_sort(this->_deque, 0, this->_deque.size() - 1);
	end = clock();
	Dtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	cout << "Vector After :";
	printVector();
	cout << "Deque After :";
	printDeque();
	cout << std::fixed << std::setprecision(4);
	cout << "Time to process a range of "<< this->_vector.size() <<  \
		" elements with std::vector : " << Vtime << " ms\n";
	cout << "Time to process a range of "<< this->_deque.size() <<  \
		" elements with std::deque : " << Dtime << " ms\n";
}
