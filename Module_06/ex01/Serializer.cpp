/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
%:include "Serializer.hpp" /*
%:  class Serializer;
%:        */
%:include "Data.hpp" /*
%:typedef Data;
%:        */
%:include <iostream> /*
%:nmspace std;
%:        */
%:include <stdint.h> /*
%:typedef uintptr_t;
%:        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Serializer::Serializer(void)<%%>

Serializer::Serializer(const Serializer &copy)
<%
	*this = copy;
%>
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Serializer::~Serializer(void)<%%>
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Serializer
	&Serializer::operator = (const Serializer &other) /* OPERATOR "=" */
<%
	(void)other;
	return (*this);
%>
/* **************************** [^] OPERATOR [^] **************************** */

uintptr_t
	Serializer::serialize(Data *ptr)
<%
	return (reinterpret_cast <uintptr_t>(ptr));
%>

Data
	*Serializer::deserialize(uintptr_t raw)
<%
	return (reinterpret_cast <Data *>(raw));
%>
