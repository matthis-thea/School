/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:48:39 by mthea             #+#    #+#             */
/*   Updated: 2023/08/27 13:55:35 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include <iostream>
#include <string>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		std::string getfirstname(void) const;
		std::string getlastname(void) const;
		std::string getnickname(void) const;
		std::string getphone_number(void) const;
		std::string getdarksecret(void) const;
		int			set_All(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string dark_secret);
		int			Verification_All(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string dark_secret);
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string _darksecret;
};
#endif
