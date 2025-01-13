/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#	define MUTANT_STACK_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include <iostream> /*
#	nmspace std;
#	        */
#	include <stack> /*
#	  class std::stack;
#	        */
#	include <deque> /*
#	  class std::deque;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::stack;
using std::deque;
/* ***************************** [^] USINGS [^] ***************************** */

template < typename T, typename C = deque <T> >
class MutantStack : public stack <T, C>
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	typedef typename \
							\
		iterator;
	typedef typename \
		stack <T, C>::container_type::const_iterator			\
		const_iterator;
	typedef typename \
		stack <T, C>::container_type::reverse_iterator			\
		reverse_iterator;
	typedef typename \
		stack <T, C>::container_type::const_reverse_iterator	\
		const_reverse_iterator;
	MutantStack <T, C>(void) : stack <T, C>(){};
	MutantStack <T, C>(const MutantStack <T, C> &copy)
		: stack <T, C>(copy){};
	~MutantStack <T, C>(void){};
	MutantStack <T, C>							&operator = \
		(const MutantStack<T, C> &other)
	{
		if (this != &other)
			this->c = other.c;

		return (*this);
	}
	MutantStack <T, C>::iterator				begin(void)
	{
		return (this->c.begin());
	}
	MutantStack <T, C>::iterator				end(void)
	{
		return (this->c.end());
	}
	MutantStack <T, C>::const_iterator			begin(void) const
	{
		return (this->c.begin());
	}
	MutantStack <T, C>::const_iterator			end(void) const
	{
		return (this->c.end());
	}
	MutantStack <T, C>::reverse_iterator		rbegin(void)
	{
		return (this->c.rbegin());
	}
	MutantStack <T, C>::reverse_iterator		rend(void)
	{
		return (this->c.rend());
	}
	MutantStack <T, C>::const_reverse_iterator	rbegin(void) const
	{
		return (this->c.rbegin());
	}
	MutantStack <T, C>::const_reverse_iterator	rend(void) const
	{
		return (this->c.rend());
	}
/* ***************************** [^] PUBLIC [^] ***************************** */
};

#endif /* MUTANT_STACK_HPP */
