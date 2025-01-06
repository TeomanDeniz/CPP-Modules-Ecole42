/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "ShrubberyCreationForm.hpp" /*
#nmspace ostream;
#  class ShrubberyCreationForm;
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::ofstream;
using std::string;
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Default Form", 92, 11), \
	  _target("Default Target")
{
	cout << "Default constructor called (ShrubberyCreationForm)" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const string target)
	: AForm("Shrubbery Creation Form", 92, 11), \
	  _target(target)
{
	cout << "Name parameterized constructor called (ShrubberyCreationForm)" \
		<< endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy), \
	  _target(copy.getTarget())
{
	cout << "Copy constructor called (ShrubberyCreationForm)" << endl;
	*this = copy;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	cout << "Destructor called (ShrubberyCreationForm)" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
ostream
	&operator<<(ostream &out, const ShrubberyCreationForm &form)
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

ShrubberyCreationForm
	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{ /* OPERATOR "=" */
	cout << "Assignment operator called (ShrubberyCreationForm)" << endl;

	if (this != &other)
		AForm::operator=(other);

	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

const string
	&ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void
	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	ofstream	out;

	if (executor.getGrade() > getExecGrade())
	{
		cout << "The form can't be executed because ";
		throw AForm::GradeTooLowException();
	}
	else if (!getIsSigned())
	{
		cout << "The form can't be executed because ";
		throw AForm::FormNotSignedException();
	}

	out.open((getTarget() + "_shrubbery").c_str(), \
		ofstream::in | ofstream::trunc);
	out << "            ,@@@@@@@," << endl;
	out << "    ,,,.   ,@@@@@@/@@,  .oo8888o." << endl;
	out << " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << endl;
	out << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << endl;
	out << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << endl;
	out << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << endl;
	out << "`&%\\ ` /%&'    |.|        \\ '|8'" << endl;
	out << "    |o|        | |         | |" << endl;
	out << "    |.|        | |         | |" << endl;
	out << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << endl;
	out.close();
}
