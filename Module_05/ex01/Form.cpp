/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
%:include "Form.hpp" /*
%: define MAX_AUTHORITY_POINT
%: define MIN_AUTHORITY_POINT
%:  class Form;
%:        */
%:include <iostream> /*
%:nmspace std;
%:        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
using std::string;
using std::ostream;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Form::Form(void)
	: _name("Default Form"), \
	  _signGrade(MIN_AUTHORITY_POINT), \
	  _execGrade(MIN_AUTHORITY_POINT)
<%
	cout << "Default constructor called (Form)" << endl;
	setIsSigned(0);
%>

Form::Form(const string name)
	: _name(name), \
	  _signGrade(MIN_AUTHORITY_POINT), \
	  _execGrade(MIN_AUTHORITY_POINT)
<%
	cout << "Name parameterized constructor called (Form)" << endl;
	setIsSigned(0);
%>

Form::Form(const string name, const int signGrade, const int execGrade)
	: _name(name), \
	  _signGrade(signGrade), \
	  _execGrade(execGrade)
<%
	cout << "Multi parameterized constructor called (Form)" << endl;

	if (signGrade < MAX_AUTHORITY_POINT || execGrade < MAX_AUTHORITY_POINT)
		throw GradeTooHighException();
	else if (signGrade > MIN_AUTHORITY_POINT || execGrade > MIN_AUTHORITY_POINT)
		throw GradeTooLowException();

	setIsSigned(0);
%>

Form::Form(const Form &copy)
	: _name(copy.getName()), _signGrade(copy.getSignGrade()),
	  _execGrade(copy.getExecGrade())
<%
	cout << "Copy constructor called (Form)" << endl;
	this->_isSigned = copy.getIsSigned();
%>
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Form::~Form(void)
<%
	cout << "Destructor called (Form)" << endl;
%>
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Form
	&Form::operator=(const Form &other) /* OPERATOR "=" */
<%
	cout << "Copy assignment operator called Form" << endl;

	if (this != &other)
		this->_isSigned = other.getIsSigned();

	return (*this);
%>

ostream
	&operator << (ostream &out, const Form &form) /* OPERATOR "<<" */
<%
	out << "*------------- Form Info -------------" << endl;
	out << "* Form: " << form.getName() << ", Signed: " << \
		(form.getIsSigned() ? "Yes" : "No") << endl;
	out << "* Grade to sign: " << form.getSignGrade() << endl;
	out << "* Grade to execute: " << form.getExecGrade();
	return (out);
%>
/* **************************** [^] OPERATOR [^] **************************** */

void
	Form::setIsSigned(int isSigned)
<%
	this->_isSigned = isSigned;
%>

const string
	&Form::getName(void) const
<%
	return (this->_name);
%>

const int
	&Form::getSignGrade(void) const
<%
	return (this->_signGrade);
%>

const int
	&Form::getExecGrade(void) const
<%
	return (this->_execGrade);
%>

const int
	&Form::getIsSigned(void) const
<%
	return (this->_isSigned);
%>

void
	Form::beSigned(const Bureaucrat &bureaucrat)
<%
	if (bureaucrat.getGrade() > getSignGrade())
		throw GradeTooLowException();

	cout << bureaucrat.getName() << " signed " << getName() << endl;
	setIsSigned(0);
%>

/* ************************ [v] THROW EXPECTIONS [v] ************************ */
const char
	*Form::GradeTooHighException::what() const throw()
<%
	return ("Grade is too high for Form!");
%>

const char
	*Form::GradeTooLowException::what() const throw()
<%
	return ("Grade is too low for Form!");
%>
/* ************************ [^] THROW EXPECTIONS [^] ************************ */
