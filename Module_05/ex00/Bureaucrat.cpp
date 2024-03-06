/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 09:29:11 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/02 02:07:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Bureaucrat.hpp" /*
#  class Bureaucrat;
#*/
#include <iostream> /*
#namespc std;
#*/
#include <string> /*
#  class std::string;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Bureaucrat::Bureaucrat(const string &name, int grade) \
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) \
	: _name(src._name), _grade(src._grade)
{
	(void)0;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Bureaucrat::~Bureaucrat(void)
{
	(void)0;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Bureaucrat
	&Bureaucrat::operator = (const Bureaucrat &rhs) /* OPERATOR "=" */
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	return (*this);
}

std::ostream
	&operator << (std::ostream &o, const Bureaucrat &rhs) /* OPERATOR "<<" */
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}
/* **************************** [^] OPERATOR [^] **************************** */

string
	Bureaucrat::getName(void) const
{
	return (_name);
}

int
	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void
	Bureaucrat::incrementGrade(void)
{
	if ((_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void
	Bureaucrat::decrementGrade(void)
{
	if ((_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}
