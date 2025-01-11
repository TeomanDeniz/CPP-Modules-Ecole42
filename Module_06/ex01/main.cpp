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
%:include "Serializer.hpp" /*
%:  class Serializer;
%:        */
%:include "Data.hpp" /*
%:typedef Data;
%:typedef uintptr_t;
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
using std::cerr;
using std::exception;
/* ***************************** [^] USINGS [^] ***************************** */

int
	main(void)
<%
	<%
		Data		*ptr;
		Data		*ptr2;
		uintptr_t	raw;

		ptr = (Data *)0;
		ptr2 = (Data *)0;
		raw = (uintptr_t)0;

		try
		<%
			ptr = new Data(65);
			raw = Serializer::serialize(ptr);
			ptr2 = Serializer::deserialize(raw);
			cout << "************************" << endl;
			cout << ptr->getRaw() << endl;
			cout << ptr2->getRaw() << endl;
			cout << raw << endl;
			cout << Serializer::serialize(ptr2) << endl;
			cout << "************************" << endl;
			delete ptr;
		%>
		catch(const exception &error)
		<%
			cerr << error.what() << endl;
		%>
	%>

	<%
		Data		*ptr;
		uintptr_t	raw;
		uintptr_t	raw2;

		ptr = (Data *)0;
		raw = (uintptr_t)0;
		raw2 = (uintptr_t)0;

		raw = reinterpret_cast<uintptr_t>((Data <:1:>)<%30%>);
		ptr = Serializer::deserialize(raw);
		raw2 = Serializer::serialize(ptr);
		cout << "************************" << endl;
		cout << ptr->getRaw() << endl;
		cout << Serializer::deserialize(raw2)->getRaw() << endl;
		cout << raw << endl;
		cout << raw2 << endl;
		cout << "************************" << endl;
	%>

	return (0);
%>
