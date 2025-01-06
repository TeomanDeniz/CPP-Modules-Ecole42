/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#	define BUREAUCRAT_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include "AForm.hpp" /*
#	  class AForm;
#	        */
#	include <iostream> /*
#	nmspace std;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
using std::ostream;
using std::exception;
/* ***************************** [^] USING [^] ****************************** */

/* ***************************** [v] MACROS [v] ***************************** */
#	define MAX_AUTHORITY_POINT 1
#	define MIN_AUTHORITY_POINT 150
/* ***************************** [^] MACROS [^] ***************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
class	AForm;
class	Bureaucrat;
ostream	&operator << (ostream &out, const Bureaucrat &bureaucrat);
/* *************************** [^] PROTOTYPES [^] *************************** */

class Bureaucrat
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Bureaucrat(void);
	Bureaucrat(const string name, const int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat(void);
	Bureaucrat		&operator = (const Bureaucrat &other);
	void			setGrade(const int grade);
	const int		&getGrade(void) const;
	const string	&getName(void) const;
	void			incrementGrade(void);
	void			incrementGrade(const unsigned int amount);
	void			decrementGrade(void);
	void			decrementGrade(const unsigned int amount);
	void			signForm(AForm &form);
	void			executeForm(AForm const &form) const;
	class GradeTooHighException : public exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public exception
	{
	public:
		virtual const char *what() const throw();
	};
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	const string	_name;
	int				_grade;
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* BUREAUCRAT_HPP */
