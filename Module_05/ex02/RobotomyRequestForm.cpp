/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "RobotomyRequestForm.hpp" /*
#typedef t_cast;
#nmspace ostream;
#  class RobotomyRequestForm;
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

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Default Form", 55, 13), \
	  _target("Default Target")
{
	cout << "Default constructor called (RobotomyRequestForm)" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const string target)
	: AForm("Robotomy Request Form", 55, 13), \
	  _target(target)
{
	cout << "Name parameterized constructor called (RobotomyRequestForm)" \
		<< endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), \
	  _target(copy.getTarget())
{
	cout << "Copy constructor called (RobotomyRequestForm)" << endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	cout << "Destructor called (RobotomyRequestForm)" << endl;
}

/* **************************** [v] OPERATOR [v] **************************** */
RobotomyRequestForm
	&RobotomyRequestForm::operator = (const RobotomyRequestForm &other)
{ /* OPERATOR "=" */
	cout << "Assignment operator called (RobotomyRequestForm)" << endl;

	if (this != &other)
		AForm::operator = (other);

	return (*this);
}

ostream
	&operator << (ostream &out, const RobotomyRequestForm &form)
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
	&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

static int
	ft_rand(int min, int max)
{
	static unsigned long	address;
	static int				seed;
	char					pointer[8192];
	t_cast					cast;

	seed = seed + 0;

	if (!seed)
	{
		cast.ptr = &pointer[seed];
		address = cast.integer + \
			((unsigned long)__TIME__[0] \
			* (unsigned long)__TIME__[1] \
			+ (unsigned long)__TIME__[3] \
			* (unsigned long)__TIME__[4] \
			+ (unsigned long)__TIME__[6]) \
			* (unsigned long)__TIME__[7];
	}

	address = (address * 1103515245 + 12345) & 0x7fffffff;
	seed++;
	return (min + (int)((double)address / (0x7fffffff / (max - min + 1))));
}

void
	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!(this->getIsSigned()))
	{
		cout << "The form can't be executed because ";
		throw AForm::FormNotSignedException();
	}
	else if (executor.getGrade() > this->getExecGrade())
	{
		cout << "The form can't be executed because ";
		throw AForm::GradeTooLowException();
	}

	cout << "* some drilling noises *" << endl;

	if (ft_rand(1, 10000) % 2 == 0)
		cout << getTarget() << " has been robotomized succesfully" << endl;
	else
		cout << "Failed to robotomized " << getTarget() << endl;
}
