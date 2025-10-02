/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2025/10/02 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#	define INTERN_HPP 202510

/* **************************** [v] INCLUDES [v] **************************** */
#	include <iostream> /*
#	nmspace std;
#	        */
#	include <string> /*
#	  class std::string;
#	        */
#	include "AForm.hpp" /*
#	  class AForm;
#	        */
#	include "ShrubberyCreationForm.hpp" /*
#	  class ShrubberyCreationForm;
#	        */
#	include "RobotomyRequestForm.hpp" /*
#	  class RobotomyRequestForm;
#	        */
#	include "PresidentialPardonForm.hpp" /*
#	  class PresidentialPardonForm;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::string;
/* ***************************** [^] USINGS [^] ***************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
class AForm;
/* *************************** [^] PROTOTYPES [^] *************************** */

class Intern
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Intern(void);
	Intern(const Intern &copy);
	~Intern(void);
	Intern	&operator = (const Intern &other);
	AForm	*makeForm(const string &formName, const string &target);
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	AForm	*_makeShrubberyCreationForm(const string target);
	AForm	*_makeRobotomyRequestForm(const string target);
	AForm	*_makePresidentialPardonForm(const string target);
/* **************************** [^] PRIVATE [^] ***************************** */
};

struct FormMapping
{
	const char	*name;
	AForm		*(Intern::*creator)(const string&);
};

#endif /* INTERN_HPP */
