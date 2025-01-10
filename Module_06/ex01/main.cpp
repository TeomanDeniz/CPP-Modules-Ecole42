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
%:  class Data;
%:        */
%:include <iostream> /*
%:nmspace std;
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
		Data			*ptr;
		unsigned int *raw;
		unsigned int *raw2;

		ptr = (Data *)0;
		raw = (unsigned int *)0;
		raw2 = (unsigned int *)0;

		raw = reinterpret_cast<unsigned int *>((Data <:1:>)<%30%>);
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
}
