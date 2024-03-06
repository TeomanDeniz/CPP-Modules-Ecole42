/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 09:29:11 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/02 02:07:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include <iostream> /*
# namespc std;
# */
# include <string> /*
#   class std::string;
# */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
/* ***************************** [^] USING [^] ****************************** */

class Bureaucrat
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Bureaucrat(const string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);
	Bureaucrat &operator = (const Bureaucrat &rhs);
	string	getName(void) const;
	int		getGrade(void) const;
	void	incrementGrade(void);
	void	decrementGrade(void);

/* ----------------------- [v] EXCEPTION CLASSES [v] ------------------------ */
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what(void) const throw()
			{
				return ("Grade too high");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what(void) const throw()
			{
				return ("Grade too low");
			}
	};
/* ----------------------- [^] EXCEPTION CLASSES [^] ------------------------ */
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	Bureaucrat(void);
	const string	_name;
	int				_grade;
/* **************************** [^] PRIVATE [^] ***************************** */
};

std::ostream	&operator << (std::ostream &o, const Bureaucrat &rhs);

#endif /* BUREAUCRAT_HPP */
