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
#include "Bureaucrat.hpp" /*
# define MAX_AUTHORITY_POINT
# define MIN_AUTHORITY_POINT
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
using std::exception;
/* ***************************** [^] USING [^] ****************************** */

int
	main(void)
{
	Bureaucrat	*b1;
	Bureaucrat	*b2;
	Bureaucrat	*b3;
	Bureaucrat	*b4;

	b1 = (Bureaucrat *)0;
	b2 = (Bureaucrat *)0;
	b3 = (Bureaucrat *)0;
	b4 = (Bureaucrat *)0;

	try
	{
		b1 = new Bureaucrat("Dallas", MAX_AUTHORITY_POINT);
		b1->decrementGrade();
		cout << *b1 << endl;
		delete b1;
		b1 = 0;

		b2 = new Bureaucrat("Sylwia", MIN_AUTHORITY_POINT);
		b2->incrementGrade();
		cout << *b2 << endl;
		delete b2;
		b2 = 0;

		b3 = new Bureaucrat("Frank", MAX_AUTHORITY_POINT);
		cout << *b3 << endl;
		b3->incrementGrade();
		delete b3;
		b3 = 0;

		b4 = new Bureaucrat("Jasper", MIN_AUTHORITY_POINT);
		b4->decrementGrade();
		delete b4;
		b4 = 0;
	}
	catch (const exception &error)
	{
		cout << error.what() << endl;
		delete b1;
		delete b2;
		delete b3;
		delete b4;
	}

	return (0);
}
