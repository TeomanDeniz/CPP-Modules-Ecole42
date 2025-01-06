/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#	define AFORM_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include "Bureaucrat.hpp" /*
#	 define MAX_AUTHORITY_POINT
#	 define MIN_AUTHORITY_POINT
#	  class Bureaucrat;
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
#	ifndef MAX_AUTHORITY_POINT
#		define MAX_AUTHORITY_POINT 1
#	endif /* MAX_AUTHORITY_POINT */
#	ifndef MIN_AUTHORITY_POINT
#		define MIN_AUTHORITY_POINT 150
#	endif /* MIN_AUTHORITY_POINT */
/* ***************************** [^] MACROS [^] ***************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
class	Bureaucrat;
class	AForm;
ostream	&operator << (ostream &out, const AForm &form);
/* *************************** [^] PROTOTYPES [^] *************************** */
class AForm
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	AForm(void);
	AForm(const string name);
	AForm(const string name, const int signGrade, const int execGrade);
	AForm(const AForm &copy);
	virtual ~AForm(void);
	AForm			&operator = (const AForm &other);
	void			setIsSigned(int isSigned);
	const string	&getName(void) const;
	const int		&getSignGrade(void) const;
	const int		&getExecGrade(void) const;
	const int		&getIsSigned(void) const;
	void			beSigned(const Bureaucrat &bureaucrat);
	virtual void	execute(Bureaucrat const &executor) const = 0;
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
	class FormNotSignedException : public exception
	{
	public:
		virtual const char *what() const throw();
	};
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	const string	_name;
	const int		_signGrade;
	const int		_execGrade;
	int				_isSigned;
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* AFORM_HPP */
