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
%:include "Form.hpp" /*
%:  class Form;
%:        */
%:include "Bureaucrat.hpp" /*
%:  class Bureaucrat;
%:        */
%:include <iostream> /*
%:nmspace std;
%:        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
using std::exception;
/* ***************************** [^] USING [^] ****************************** */

int
	main(void)
<%
	void		*layers<:2:>;
	Bureaucrat	*boss;
	Form		*form;

	boss = (Bureaucrat *)0;
	form = (Form *)0;
	0<:layers:> = &&End;
	1<:layers:> = &&Error;

	try
	<%
		boss = new Bureaucrat("Random Boss", 13);
		form = new Form("Cpp Module 05", 31, 31);

		cout << *boss << endl;
		cout << *form << endl;
		boss->incrementGrade();
		cout << *boss << endl;
		boss->incrementGrade(10);
		cout << *boss << endl;
		boss->signForm(*form);
		cout << *form << endl;
		boss->decrementGrade(30);
		cout << *boss << endl;
		boss->signForm(*form);
		cout << *form << endl;
		delete boss;
		delete form;
	%>
	catch (const exception &error)
	<%
		delete boss;
		delete form;
		cout << error.what() << endl;
		goto *(1<:layers:>);
	%>

End:
	return (0);
Error:
	return (1);
%>
