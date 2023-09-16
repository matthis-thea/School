/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:36:25 by mthea             #+#    #+#             */
/*   Updated: 2023/08/27 12:57:18 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK
#define PHONE_BOOK

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	Menu(void);
		void	Search_Contact(void);
		void	Add_Contact();
		void	Exit() const;
		void    Error_message(std::string error) const;

	private:
		Contact		_contact[8];
		size_t		_incr;
};
#endif
