/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:58:09 by mthea             #+#    #+#             */
/*   Updated: 2023/08/27 13:55:59 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::getfirstname(void) const
{
	return this->_first_name;
}

std::string Contact::getlastname(void) const
{
	return this->_last_name;
}

std::string Contact::getnickname(void) const
{
	return this->_nickname;
}

std::string Contact::getphone_number(void) const
{
	return this->_phone_number;
}

std::string Contact::getdarksecret(void) const
{
	return this->_darksecret;
}

int		Contact::set_All(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string dark_secret)
{
	if (first_name.length() > 10) {
		first_name[9] = '.';
		first_name.erase(first_name.begin()+10, first_name.end());
	}
	this->_first_name = first_name;

	if (last_name.length() > 10) {
		last_name[9] = '.';
		last_name.erase(last_name.begin()+10, last_name.end());
	}
	this->_last_name = last_name;

	if (nickname.length() > 10) {
		nickname[9] = '.';
		nickname.erase(nickname.begin()+10, nickname.end());
	}
	this->_nickname = nickname;

	if (phone_number.length() > 10) {
		phone_number[9] = '.';
		phone_number.erase(phone_number.begin()+10, phone_number.end());
	}
	this->_phone_number = phone_number;

	if (dark_secret.length() > 10) {
		dark_secret[9] = '.';
		dark_secret.erase(dark_secret.begin()+10, dark_secret.end());
	}
	this->_darksecret = dark_secret;
	return (1);
}

int		Contact::Verification_All(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string dark_secret)
{
	if (first_name == "")
		return (0);
	if (last_name == "")
		return (0);
	if (nickname == "")
		return (0);
	if (phone_number == "")
		return (0);
	for (size_t i = 0; i < phone_number.length(); i++){
		if (!isdigit(phone_number[i]))
			return (-1);
	}
	if (dark_secret == "")
		return (0);
	return (1);
}