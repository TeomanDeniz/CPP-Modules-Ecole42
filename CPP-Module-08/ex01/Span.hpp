/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#	define SPAN_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include <iostream> /*
#	nmspace std;
#	        */
#	include <vector> /*
#	  class std::vector;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::vector;
using std::exception;
/* ***************************** [^] USINGS [^] ***************************** */

class Span
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Span(unsigned int N);
	Span(const Span &copy);
	~Span(void);
	Span				&operator = (const Span &other);
	void				increment(void);
	const unsigned int	&size(void) const;
	const unsigned int	&count(void) const;
	const vector <int>	&getArray(void) const;
	int					randomizer(void) const;
	void				addNumber(const int number);
	int					swap(int *a, int *b);
	void				bubbleSort(vector <int> &arr);
	int					shortestSpan(void);
	int					longestSpan(void);
	class FullArrayException : public exception
	{
	public:
		virtual const char *what() const throw();
	};
	class SmallSizeException : public exception
	{
	public:
		virtual const char *what() const throw();
	};
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	unsigned int		_N;
	unsigned int		_count;
	vector <int>		_arr;
	Span(void);
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* SPAN_HPP */
