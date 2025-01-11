/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#	define ITER_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

template <typename T>
void
	swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void
	iter(T *array, int size, void (*f)(T &))
{
	int	i;

	for (i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void
	print(T &s)
{
	cout << "{" << &s << "} ~> " << "[" << s << "]" << endl;
}

#endif /* ITER_HPP */
