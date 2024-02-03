/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "Contact.hpp" /*
#   class Contact;
# */
/* **************************** [^] INCLUDES [^] **************************** */

class PhoneBook
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	PhoneBook();
	~PhoneBook();
	void	addContact(void);
	void	printContacts(void) const;
	void	search(void) const;
	void	welcome(void) const;
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	Contact	_contacts[8];
	int		_readInput(void) const;
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* PHONEBOOK_HPP */