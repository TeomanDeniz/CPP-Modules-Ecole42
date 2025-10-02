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
# struct FormMapping;
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

static AForm
	*makeFormTrue(Intern *__this__, unsigned char &index, const string &target)
{
	const FormMapping	mappings[5] =
	{
		{0},
		{"shrubbery creation", &Intern::createShrubberyCreation},
		{"robotomy request", &Intern::createRobotomyRequest},
		{0},
		{"presidential pardon", &Intern::createPresidentialPardon}
	};

	return ((__this__->*mappings[index].creator)(target));
}

static AForm
	*makeFormFalse(
	Intern *__this__,
	unsigned char &index,
	const string &target
)
{
	(void)__this__;
	(void)index;
	(void)target;

	throw (Intern::FormNotFoundException());
	return (0);
}

AForm
	*Intern::makeForm(const string &formName, const string &target)
{
	unsigned char	index;

	index = 0;
	AForm *(*check[5])(Intern*, unsigned char &, const string&) = {
		makeFormFalse,
		makeFormTrue,
		makeFormTrue,
		makeFormTrue,
		makeFormTrue
	};

	index = (formName == "presidential pardon");
	index <<= 1;
	index += (formName == "robotomy request");
	index <<= 1;
	index += (formName == "shrubbery creation");

	return (check[index](this, index, target));
}
