/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "AForm.hpp" /*
# define MAX_AUTHORITY_POINT
# define MIN_AUTHORITY_POINT
#  class AForm;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
using std::string;
using std::ostream;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
AForm::AForm(void)
	: _name("Default AForm"), \
	  _signGrade(MIN_AUTHORITY_POINT), \
	  _execGrade(MIN_AUTHORITY_POINT)
{
	cout << "Default constructor called (AForm)" << endl;
	setIsSigned(0);
}

AForm::AForm(const string name)
	: _name(name), \
	  _signGrade(MIN_AUTHORITY_POINT), \
	  _execGrade(MIN_AUTHORITY_POINT)
{
	cout << "Name parameterized constructor called (AForm)" << endl;
	setIsSigned(0);
}

AForm::AForm(const string name, const int signGrade, const int execGrade)
	: _name(name), \
	  _signGrade(signGrade), \
	  _execGrade(execGrade)
{
	cout << "Multi parameterized constructor called (AForm)" << endl;

	if (signGrade < MAX_AUTHORITY_POINT || execGrade < MAX_AUTHORITY_POINT)
		throw GradeTooHighException();
	else if (signGrade > MIN_AUTHORITY_POINT || execGrade > MIN_AUTHORITY_POINT)
		throw GradeTooLowException();

	setIsSigned(0);
}

AForm::AForm(const AForm &copy)
	: _name(copy.getName()), \
	  _signGrade(copy.getSignGrade()), \
	  _execGrade(copy.getExecGrade())
{
	cout << "Copy constructor called (AForm)" << endl;
	this->_isSigned = copy.getIsSigned();
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
AForm::~AForm(void)
{
	cout << "Destructor called (AForm)" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
AForm
	&AForm::operator = (const AForm &other) /* OPERATOR "=" */
{
	cout << "Copy assignment operator called (AForm)" << endl;

	if (this != &other)
		this->_isSigned = other.getIsSigned();

	return (*this);
}

ostream
	&operator << (ostream &out, const AForm &form) /* OPERATOR "<<" */
{
	out << "------------- Form Info -------------" << endl;
	out << "Form: " << form.getName() << ", Signed: ";

	if (form.getIsSigned())
		out << "Yes" << endl;
	else
		out << "No" << endl;

	out << "Grade to sign: " << form.getSignGrade() << endl;
	out << "Grade to execute: " << form.getExecGrade();
	return (out);
}
/* **************************** [^] OPERATOR [^] **************************** */

/* ************************ [v] THROW EXPECTIONS [v] ************************ */
const char
	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (Form)");
}

const char
	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (Form)");
}

const char
	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form needs to be signed before executing");
}
/* ************************ [^] THROW EXPECTIONS [^] ************************ */

void
	AForm::setIsSigned(int isSigned)
{
	this->_isSigned = isSigned;
}

const string
	&AForm::getName(void) const
{
	return (this->_name);
}

const int
	&AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

const int
	&AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

const int
	&AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void
	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getSignGrade())
		throw GradeTooLowException();

	cout << bureaucrat.getName() << " signed " << getName() << endl;
	setIsSigned(1);
}
