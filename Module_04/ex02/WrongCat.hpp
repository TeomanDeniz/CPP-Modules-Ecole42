/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "WrongAnimal.hpp" /*
#   class WrongAnimal;
# */
/* **************************** [^] INCLUDES [^] **************************** */

class WrongCat : public WrongAnimal
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	WrongCat(void);
	~WrongCat(void);
	void	makeSound(void) const;
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* WRONGCAT_HPP */
