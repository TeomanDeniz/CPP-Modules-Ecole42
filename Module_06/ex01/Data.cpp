/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
%:include "Data.hpp" /*
%:typedef Data;
%:        */
%:ifdef _WIN32
%:	include <stdint.h> /*
%:	typedef uintptr_t;
%:	        */
%:else /* PROBABLY UNIX */
%:	include <sys/types.h> /*
%:	typedef uintptr_t;
%:	        */
%:endif /* _WIN32 */
%:include <iostream> /*
%:nmspace std;
%:        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Data::Data(void)
<%
	cout << "Default constructor called (Data)" << endl;
	this->_raw = 0;
%>

Data::Data(uintptr_t raw)
<%
	cout << "Parameterized constructor called (Data)" << endl;
	this->_raw = raw;
%>

Data::Data(const Data &copy)
<%
	cout << "Copy constructor called (Data)" << endl;
	*this = copy;
%>
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Data::~Data(void)
<%
	cout << "Destructor called (Data)" << endl;
%>
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Data
	&Data::operator = (const Data &other) /* OPERATOR "=" */
<%
	cout << "Copy assignment operator called (Data)" << endl;

	if (this != &other)
		this->_raw = other._raw;

	return (*this);
%>
/* **************************** [^] OPERATOR [^] **************************** */

void
	Data::setRaw(uintptr_t raw)
<%
	this->_raw = raw;
%>

const uintptr_t
	&Data::getRaw(void) const
<%
	return (this->_raw);
%>
