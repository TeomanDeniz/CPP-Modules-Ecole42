/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#	define SHRUBBERYCREATIONFORM_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include "AForm.hpp" /*
#	  class AForm;
#	        */
#	include "Bureaucrat.hpp" /*
#	  class Bureaucrat;
#	        */
#	include <fstream> /*
#	nmspace ostream;
#	        */
#	include <iostream> /*
#	nmspace std;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
using std::ostream;
/* ***************************** [^] USING [^] ****************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
class	Bureaucrat;
class	AForm;
class	ShrubberyCreationForm;
ostream	&operator << (ostream &out, const ShrubberyCreationForm &form);
/* *************************** [^] PROTOTYPES [^] *************************** */

class ShrubberyCreationForm : public AForm
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	ShrubberyCreationForm(const string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm	&operator = \
		(const ShrubberyCreationForm &other);
	void					execute(Bureaucrat const &executor) const;
	const string			&getTarget(void) const;
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	const string	_target;
	ShrubberyCreationForm(void);
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
