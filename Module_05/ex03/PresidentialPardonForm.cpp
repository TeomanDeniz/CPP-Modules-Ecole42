/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "PresidentialPardonForm.hpp" /*
#nmspace ostream;
#  class PresidentialPardonForm;
#        */
#include "Bureaucrat.hpp" /*
#  class Bureaucrat;
#        */
#include "AForm.hpp" /*
#  class AForm;
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Default Form", 139, 111), \
	  _target("Default Target")
{
	cout << "Default constructor called (PresidentialPardonForm)" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const string target)
	: AForm("Presidential Pardon Form", 139, 111), \
	  _target(target)
{
	cout << "Name parameterized constructor called (PresidentialPardonForm)" \
		<< endl;
}

PresidentialPardonForm::PresidentialPardonForm(\
const PresidentialPardonForm &copy)
	: AForm(copy), \
	  _target(copy.getTarget())
{
	cout << "Copy constructor called (PresidentialPardonForm)" << endl;
	*this = copy;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	cout << "Destructor called (RobotomyRequestForm)" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
PresidentialPardonForm
	&PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{ /* OPERATOR "=" */
	cout << "Assignment operator called (RobotomyRequestForm)" << endl;

	if (this != &other)
		AForm::operator = (other);

	return (*this);
}

ostream
	&operator << (ostream &out, const PresidentialPardonForm &form)
{ /* OPERATOR "<<" */
	out << "------------- Form Info -------------" << endl;
	out << "Form: " << form.getName() << ", Signed: ";

	if (form.getIsSigned())
		out << "Yes" << endl;
	else
		out << "No" << endl;

	out << "Form Target: " << form.getTarget() << endl;
	out << "Grade to sign: " << form.getSignGrade() << endl;
	out << "Grade to execute: " << form.getExecGrade();
	return (out);
}
/* **************************** [^] OPERATOR [^] **************************** */

const string
	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void
	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!getIsSigned())
	{
		cout << "The form can't be executed because ";
		throw AForm::FormNotSignedException();
	}
	else if (bureaucrat.getGrade() > getExecGrade())
	{
		cout << "The form can't be executed because ";
		throw AForm::GradeTooLowException();
	}

	cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" \
		<< endl;
}
