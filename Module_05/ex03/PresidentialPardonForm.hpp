/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#	define PRESIDENTIALPARDONFORM_HPP 202402

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
class	PresidentialPardonForm;
ostream	&operator << (ostream &out, const PresidentialPardonForm &form);
/* *************************** [^] PROTOTYPES [^] *************************** */

class PresidentialPardonForm : public AForm
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	PresidentialPardonForm(const string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm(void);
	PresidentialPardonForm	&operator = (const PresidentialPardonForm &other);
	const string			&getTarget(void) const;
	void					execute(Bureaucrat const &executor) const;
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	const string	_target;
	PresidentialPardonForm(void);
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
