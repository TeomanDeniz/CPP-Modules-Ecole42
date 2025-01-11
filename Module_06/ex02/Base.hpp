/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#	define BASE_HPP 202402

/* ***************************** [v] UNION [v] ****************************** */
typedef union s_cast
{
	const char		*ptr;
	unsigned long	integer;
}				t_cast;
/* ***************************** [^] UNION [^] ****************************** */

class Base
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	virtual ~Base(void);
/* ***************************** [^] PUBLIC [^] ***************************** */
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

extern Base	*generate(void);
extern void	identify(Base *p);
extern void	identify(Base &p);

#endif /* BASE_HPP */
