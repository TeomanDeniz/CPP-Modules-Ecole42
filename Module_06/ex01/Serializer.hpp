/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%:ifndef SERIALIZER_HPP
%:	define SERIALIZER_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
%:	include "Data.hpp" /*
%:	typedef Data;
%:	        */
%:include <stdint.h> /*
%:typedef uintptr_t;
%:        */
/* **************************** [^] INCLUDES [^] **************************** */

class Serializer
<%
public: /* ************************* [v] PUBLIC [v] ************************* */
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	Serializer(void);
	Serializer(const Serializer &copy);
	~Serializer(void);
	Serializer	&operator = (const Serializer &other);
/* **************************** [^] PRIVATE [^] ***************************** */
%>;

%:endif /* SERIALIZER_HPP */
