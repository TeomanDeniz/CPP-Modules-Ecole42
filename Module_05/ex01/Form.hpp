/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%:ifndef FORM_HPP
%:	define FORM_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
%:	include "Bureaucrat.hpp" /*
%:	  class Bureaucrat;
%:	        */
%:	include <iostream> /*
%:	nmspace std;
%:	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
using std::ostream;
using std::exception;
/* ***************************** [^] USING [^] ****************************** */

/* ***************************** [v] MACROS [v] ***************************** */
%:	ifndef MAX_AUTHORITY_POINT
%:		define MAX_AUTHORITY_POINT 1
%:	endif /* MAX_AUTHORITY_POINT */
%:	ifndef MIN_AUTHORITY_POINT
%:		define MIN_AUTHORITY_POINT 150
%:	endif /* MIN_AUTHORITY_POINT */
/* ***************************** [^] MACROS [^] ***************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
class	Bureaucrat;
class	Form;
ostream	&operator << (ostream &out, const Form &form);
/* *************************** [^] PROTOTYPES [^] *************************** */

class Form
<%
public: /* ************************* [v] PUBLIC [v] ************************* */
	Form(void);
	Form(const string name);
	Form(const string name, const int signGrade, const int execGrade);
	Form(const Form &copy);
	~Form(void);
	Form			&operator = (const Form &other);
	void			setName(const string name);
	void			setIsSigned(int isSigned);
	const string	&getName(void) const;
	const int		&getSignGrade(void) const;
	const int		&getExecGrade(void) const;
	const int		&getIsSigned(void) const;
	void			beSigned(const Bureaucrat &bureaucrat);
	class GradeTooHighException : public exception
	<%
	public:
		virtual const char *what() const throw();
	%>;
	class GradeTooLowException : public exception
	<%
	public:
		virtual const char *what() const throw();
	%>;
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	const string	_name;
	const int		_signGrade;
	const int		_execGrade;
	int				_isSigned;
/* **************************** [^] PRIVATE [^] ***************************** */
%>;

%:endif /* FORM_HPP */
