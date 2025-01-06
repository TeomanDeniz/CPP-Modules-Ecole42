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
#include "ShrubberyCreationForm.hpp" /*
#  class ShrubberyCreationForm;
#        */
#include "RobotomyRequestForm.hpp" /*
#  class RobotomyRequestForm;
#        */
#include "PresidentialPardonForm.hpp" /*
#  class PresidentialPardonForm;
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
using std::exception;
/* ***************************** [^] USING [^] ****************************** */

int
	main(void)
{
	try
	{
		Bureaucrat				bureaucrat("Test", 2); // error -> (200)
		ShrubberyCreationForm	form1("Shrubbery");
		RobotomyRequestForm		form2("Robotomy");
		PresidentialPardonForm	form3("President");

		cout << "\n--------------- Form 1 (Shrubbery) ---------------" \
			<< endl;
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
		cout << "\n--------------- Form 2 (Robotomy) ---------------" \
			<< endl;
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		cout << "\n--------------- Form 3 (President) ---------------" \
			<< endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	}
	catch (exception &error)
	{
		cout << error.what() << endl;
	}

	return (0);
}
