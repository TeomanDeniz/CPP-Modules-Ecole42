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
#  class Bureaucrat;
#        */
#include "Intern.hpp" /*
#  class Intern;
#        */
#include "AForm.hpp" /*
#  class AForm;
#        */
#include "RobotomyRequestForm.hpp"/*
#  class RobotomyRequestForm;
#        */
#include "PresidentialPardonForm.hpp"/*
#  class PresidentialPardonForm;
#        */
#include "ShrubberyCreationForm.hpp"/*
#  class ShrubberyCreationForm;
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::cerr;
using std::endl;
using std::cout;
/* ***************************** [^] USINGS [^] ***************************** */

int
	main(void)
{
	Intern	someRandomIntern;
	AForm	*rrf;
	AForm	*ppf;
	AForm	*scf;
	AForm	*unknown;

	rrf = 0;
	ppf = 0;
	scf = 0;
	unknown = 0;

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		unknown = someRandomIntern.makeForm("unknown", "Bender");

		cout << *dynamic_cast <RobotomyRequestForm *>(rrf) << endl;
		cout << *dynamic_cast <PresidentialPardonForm *>(ppf) << endl;
		cout << *dynamic_cast <ShrubberyCreationForm *>(scf) << endl;

		delete rrf;
		delete ppf;
		delete scf;
		delete unknown;
	}
	catch(const exception &error)
	{
		cerr << error.what() << endl;
		delete rrf;
		delete ppf;
		delete scf;
		delete unknown;
	}

	return (0);
}
