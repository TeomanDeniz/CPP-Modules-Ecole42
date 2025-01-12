/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
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
#include <ctime> /*
# time_t time(time_t *);
#typedef time_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::cout;
using std::endl;
using std::cerr;
using std::exception;
/* ***************************** [^] USINGS [^] ***************************** */

int
	main(void)
{
	int	i;

	try
	{
		Span s(5);

		for (i = 0; i < 5; i++)
		{
			s.addNumber(s.randomizer());
			std::cin.ignore();
		}

		cout << "shortest span: " << s.shortestSpan() << endl;
		cout << "longest span : " << s.longestSpan() << endl;
	}
	catch (const exception &e)
	{
		cerr << "EXCEPTION: " << e.what() << endl;
	}

	cout << endl;

	try
	{
		Span s(1);

		s.addNumber(s.randomizer());
		s.addNumber(s.randomizer());
		cout << "shortest span: " << s.shortestSpan() << endl;
		cout << "longest span : " << s.longestSpan() << endl;
	}
	catch (const exception &e)
	{
		cerr << "EXCEPTION: " << e.what() << endl;
	}

	try
	{
		Span s(1);

		s.addNumber(2);
		cout << "shortest span: " << s.shortestSpan() << endl;
		cout << "longest span : " << s.longestSpan() << endl;
	}
	catch (const exception &e)
	{
		cerr << "EXCEPTION: " << e.what() << endl;
	}

	cout << endl;

	try
	{
		Span s(10000);

		for (i = 0; i < 10000 * 10000; i++)
			if (i % 10000 == 0)
				s.addNumber(s.randomizer());

		cout << "shortest span: " << s.shortestSpan() << endl;
		cout << "longest span : " << s.longestSpan() << endl;
	}
	catch (const exception &e)
	{
		cerr << "EXCEPTION: " << e.what() << endl;
	}

	return (0);
}
