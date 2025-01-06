/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Intern.hpp" /*
#  class AForm;
#  class Intern;
#        */
#include <iostream> /*
#nmspace std;
#        */
#include <string> /*
#  class std::string;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::string;
using std::cout;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Intern::Intern(void)
{
	cout << "Default constructor called (Intern)" << endl;
}

Intern::Intern(const Intern &copy)
{
	cout << "Copy constructor called (Intern)" << endl;
	*this = copy;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Intern::~Intern(void)
{
	cout << "Destructor called (Intern)" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Intern
	&Intern::operator = (const Intern &other) /* OPERATOR "=" */
{
	cout << "Assignment operator called (Intern)" << endl;

	if (this != &other)
		return (*this);

	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

AForm
	*Intern::_makeShrubberyCreationForm(const string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm
	*Intern::_makeRobotomyRequestForm(const string target)
{
	return (new RobotomyRequestForm(target));
}

AForm
	*Intern::_makePresidentialPardonForm(const string target)
{
	return (new PresidentialPardonForm(target));
}

AForm
	*Intern::makeForm(const string formName, const string target)
{
	int		index;
	AForm	*(Intern::*formArray[3])(const string target) =
	{
		&Intern::_makeShrubberyCreationForm,
		&Intern::_makeRobotomyRequestForm,
		&Intern::_makePresidentialPardonForm
	};
	string	formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (index = 0; index < 3; index++)
	{
		if (formName == formNames[index])
		{
			cout << "Intern creates " << formName << endl;
			return ((this->*(formArray[index]))(target));
		}
	}

	cout << "Intern could not create " << formName << endl;
	return (0);
}
