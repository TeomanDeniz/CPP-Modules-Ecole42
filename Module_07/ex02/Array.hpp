/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#	define ARRAY_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include <iostream> /*
#	nmspace std;
#	        */
#include "Array.tpp"
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::ostream;
using std::exception;
/* ***************************** [^] USINGS [^] ***************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
class Array;
template<typename T>
ostream	&operator << (ostream &out, Array <T> &arr);
/* *************************** [^] PROTOTYPES [^] *************************** */

template <typename T>
class Array
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Array(void);
	Array(unsigned int n);
	Array(const Array &copy);
	~Array(void);
	Array			&operator = (const Array &other);
	T				&operator [] (const unsigned int index);
	const size_t	&size(void) const;

	class OutOfBoundsException : public exception
	{
		virtual const char* what() const throw();
	};
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	T*		_array;
	size_t	_size;
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* ARRAY_HPP */
