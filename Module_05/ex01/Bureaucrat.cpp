/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
%:include "Bureaucrat.hpp" /*
%: define MAX_AUTHORITY_POINT
%: define MIN_AUTHORITY_POINT
%:  class Bureaucrat;
%:        */
%:include <iostream> /*
%:nmspace std;
%:        */
%:include <sstream>  /*
%:explici std::ostringstream;
%:        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
using std::string;
using std::ostream;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Bureaucrat::Bureaucrat(void)
	: _name("Default")
<%
	cout << "Default constructor called (Bureaucrat)" << endl;
	setGrade(MIN_AUTHORITY_POINT);
%>

Bureaucrat::Bureaucrat(const string name, const int grade)
	: _name(name)
<%
	cout << "Parameterized constructor called (Bureaucrat)" << endl;

	if (grade < MAX_AUTHORITY_POINT)
		throw GradeTooHighException();
	else if (grade > MIN_AUTHORITY_POINT)
		throw GradeTooLowException();

	setGrade(grade);
%>

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: _name(copy.getName())
<%
	cout << "Copy constructor called (Bureaucrat)" << endl;
	*this = copy;
%>
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Bureaucrat::~Bureaucrat(void)
<%
	cout << "Destructor called (Bureaucrat)" << endl;
%>
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Bureaucrat
	&Bureaucrat::operator = (const Bureaucrat &other) /* OPERATOR "=" */
<%
	cout << "Assignation operator called (Bureaucrat)" << endl;

	if (this != &other)
		this->_grade = other.getGrade();

	return (*this);
%>

ostream
	&operator << (ostream &out, const Bureaucrat &b) /* OPERATOR "<<" */
<%
	std::ostringstream	oss;

	oss << b.getGrade();
	out << b.getName();
	out << ", bureaucrat grade ";
	out << oss.str();
	out << ".";
	return (out);
%>
/* **************************** [^] OPERATOR [^] **************************** */

/* ************************ [v] THROW EXPECTIONS [v] ************************ */
const char
	*Bureaucrat::GradeTooHighException::what() const throw()
<%
	return ("Grade is too high");
%>

const char
	*Bureaucrat::GradeTooLowException::what() const throw()
<%
	return ("Grade is too low");
%>
/* ************************ [^] THROW EXPECTIONS [^] ************************ */

void
	Bureaucrat::setGrade(const int grade)
<%
	if (grade < MAX_AUTHORITY_POINT)
		throw GradeTooHighException();
	else if (grade > MIN_AUTHORITY_POINT)
		throw GradeTooLowException();

	this->_grade = grade;
%>

const string
	&Bureaucrat::getName(void) const
<%
	return (this->_name);
%>

const int
	&Bureaucrat::getGrade(void) const
<%
	return (this->_grade);
%>

void
	Bureaucrat::incrementGrade(void)
<%
	if (getGrade() - 1 < MAX_AUTHORITY_POINT)
		throw GradeTooHighException();

	setGrade(getGrade() - 1);
%>

void
	Bureaucrat::incrementGrade(const unsigned int amount)
<%
	if (getGrade() - amount < MAX_AUTHORITY_POINT)
		throw GradeTooHighException();

	setGrade(getGrade() - amount);
%>

void
	Bureaucrat::decrementGrade(void)
<%
	if (getGrade() + 1 > MIN_AUTHORITY_POINT)
		throw GradeTooLowException();

	setGrade(getGrade() + 1);
%>

void
	Bureaucrat::decrementGrade(const unsigned int amount)
<%
	if (getGrade() + amount > MIN_AUTHORITY_POINT)
		throw GradeTooLowException();

	setGrade(getGrade() + amount);
%>

void
	Bureaucrat::signForm(Form &form)
<%
	form.beSigned(*this);
%>
