/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#	define ROBOTOMYREQUESTFORM_HPP 202402

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

/* ***************************** [v] UNION [v] ****************************** */
typedef union s_cast
{
	const char		*ptr;
	unsigned long	integer;
}				t_cast;
/* ***************************** [^] UNION [^] ****************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
class	Bureaucrat;
class	AForm;
class	RobotomyRequestForm;
ostream	&operator << (ostream &out, const RobotomyRequestForm &form);
/* *************************** [^] PROTOTYPES [^] *************************** */

class RobotomyRequestForm : public AForm
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	RobotomyRequestForm(const string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm(void);
	RobotomyRequestForm	&operator = (const RobotomyRequestForm &other);
	const string		&getTarget(void) const;
	void				execute(Bureaucrat const &executor) const;
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	const string	_target;
	RobotomyRequestForm(void);
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
