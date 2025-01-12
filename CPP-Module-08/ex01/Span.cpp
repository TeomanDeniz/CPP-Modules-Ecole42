/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Span.hpp" /*
#  class Span;
#        */
#include <iostream> /*
#nmspace std;
#        */
#include <vector> /*
#  class std::vector;
#        */
#include <ctime> /*
# time_t time(time_t *);
#typedef time_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::cout;
using std::endl;
using std::vector;
using std::srand;
/* ***************************** [^] USINGS [^] ***************************** */

Span::Span(void)
{
	cout << "Default constructor called (Span)" << endl;
	_N = 0;
	_count = 0;
}

Span::Span(const unsigned int N)
{
	cout << "Parameterized constructor called (Span)" << endl;
	this->_N = N;
	this->_count = 0;
}

Span::Span(const Span &copy)
{
	cout << "Copy constructor called (Span)" << endl;
	*this = copy;
}

Span::~Span(void)
{
	cout << "Destructor called (Span)" << endl;
}

Span
	&Span::operator=(const Span &other)
{
	cout << "Copy assignment operator called (Span)" << endl;

	if (this != &other)
	{
		this->_N = other.size();
		this->_count = other._count;
		this->_arr = other.getArray();
	}

	return (*this);
}

void
	Span::increment(void)
{
	this->_count++;
}

const unsigned int
	&Span::size(void) const
{
	return (this->_N);
}

const unsigned int
	&Span::count(void) const
{
	return (this->_count);
}

const vector <int>
	&Span::getArray(void) const
{
	return (this->_arr);
}

int
	Span::randomizer(void) const
{
	srand(time((time_t *)0));

	if (rand() % 2 == 0)
		return ((rand() % 12345 + 123) * 456);
	else
		return ((rand() % 12345 + 123) / 456);
}

void
	Span::addNumber(const int number)
{
	if (count() == size())
		throw FullArrayException();

	this->_arr.push_back(number);
	increment();
}

int
	Span::swap(int *a, int *b)
{
	long	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return (1);
}

void	Span::bubbleSort(vector<int> &arr)
{
	int	is_swap;
	int	i;

	is_swap = 1;

	while (is_swap)
	{
		is_swap = 0;

		for (i = 0; i < arr.size(); i++)
			if (arr[i] > arr[i + 1])
				is_swap = swap(&arr[i], &arr[i + 1]);
	}
}

int
	Span::shortestSpan(void)
{
	int	diff;
	int	i;

	if (count() < 2)
		throw SmallSizeException();

	vector <int>	copy(getArray());

	diff = copy[1] - copy[0];
	bubbleSort(copy);

	for (i = 0; i < copy.size(); i++)
		if (copy[i + 1] - copy[i] < diff)
			diff = copy[i + 1] - copy[i];

	return (diff);
}

int
	Span::longestSpan(void)
{
	if (count() < 2)
		throw SmallSizeException();

	vector <int>	copy(getArray());

	bubbleSort(copy);
	return (copy[copy.size() - 1] - copy[0]);
}

const char
	*Span::FullArrayException::what() const throw()
{
	return ("Array is full");
}

const char
	*Span::SmallSizeException::what() const throw()
{
	return ("Array is too small");
}
