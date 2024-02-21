/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "AMateria.hpp" /*
#   class AMateria;
# */
# include "ICharacter.hpp" /*
#   class ICharacter;
# */
/* **************************** [^] INCLUDES [^] **************************** */

class Ice : public AMateria
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Ice(void);
	Ice(Ice const &src);
	~Ice(void);
	Ice					&operator = (Ice const &rhs);
	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter &target);
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* ICE_HPP */
