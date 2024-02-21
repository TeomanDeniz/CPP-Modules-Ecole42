/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "AMateria.hpp" /*
#   class AMateria;
# */
# include "ICharacter.hpp" /*
#   class ICharacter;
# */
/* **************************** [^] INCLUDES [^] **************************** */

class Cure : public AMateria
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Cure(void);
	Cure(Cure const &src);
	~Cure(void);
	Cure				&operator = (Cure const &rhs);
	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter &target);
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* CURE_HPP */
