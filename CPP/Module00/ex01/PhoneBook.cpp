/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:02:57 by mthea             #+#    #+#             */
/*   Updated: 2023/08/29 11:13:07 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
PhoneBook::PhoneBook(void)
{
	this->_incr = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::Menu(void)
{
	std::string prompt;

	std::cout << "+---------PhoneBook----------+" << std::endl;
	std::cout << "|1. ADD                      |" << std::endl;
	std::cout << "|2. SEARCH                   |" << std::endl;
	std::cout << "|3. EXIT                     |" << std::endl;
	std::cout << "+----------------------------+" << std::endl;
}

void	PhoneBook::Search_Contact(void)
{
	char		index[3];
	int			nb_index;
	std::cout << std::endl  << std::endl  << std::endl;
	std::cout   << "+--------------PhoneBook_Contact------------+" << std::endl;
	std::cout << "|  Index   |First name|Last name |Nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << '|' << std::setw(10) << i;
		std::cout << '|' << std::setw(10) << _contact[i].getfirstname();
		std::cout << '|' << std::setw(10) << _contact[i].getlastname();
		std::cout << '|' << std::setw(10) << _contact[i].getnickname() << '|';
		std::cout << std::endl;
	}
	std::cout   << "+-------------------------------------------+" << std::endl;
	std::cout << "Enter the index for print the contact :" << std::endl;
	std::cin >> index;
	if (isdigit(index[0]) && (atoi(index) >= 0 && atoi(index) <= 7)  && !index[1])
	{
		nb_index = atoi(index);
		std::cout << "Index : ";
		std::cout << std::setw(10) << nb_index << std::endl;
		std::cout << "First Name: ";
		std::cout << std::setw(10) << _contact[nb_index].getfirstname() << std::endl;
		std::cout << "Last name: ";
		std::cout << std::setw(10) << _contact[nb_index].getlastname() << std::endl;
		std::cout << "Nickname: ";
		std::cout << std::setw(10) << _contact[nb_index].getnickname() << std::endl;
		std::cout << "Phone Number: ";
		std::cout << std::setw(10) << _contact[nb_index].getphone_number() << std::endl;
		std::cout << "Dark Secret: ";
		std::cout << std::setw(10) << _contact[nb_index].getdarksecret() << std::endl;
		std::cout << std::endl;
	}
	else
		std::cout << RED "Please enter an index between 0 and 7" NC<< std::endl;
	std::cout << std::endl  << std::endl  << std::endl;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}

void 	PhoneBook::Add_Contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darksecret;
	std::cout << std::endl  << std::endl;
	std::cout << "Enter a your first name :" << std::endl;
	std::getline (std::cin, first_name);
	std::cout << "Enter a your last name :" << std::endl;
	std::getline (std::cin, last_name);
	std::cout << "Enter a your nickname :" << std::endl;
	std::getline (std::cin, nickname);
	std::cout << "Enter a your phone_number :" << std::endl;
	std::getline (std::cin, phone_number);
	std::cout << "Enter a your darksecret :" << std::endl;
	std::getline (std::cin, darksecret);
	std::cout << std::endl;
	if ((_contact[_incr].Verification_All(first_name, last_name, nickname, phone_number, darksecret)) == 0)
	{
		std::cout << RED "Please fill in all the fields" NC << std::endl << std::endl;
		return ;
	}
	if ((_contact[_incr].Verification_All(first_name, last_name, nickname, phone_number, darksecret)) == -1)
	{
		std::cout << RED "Non-numeric characters in the telephone field" NC << std::endl << std::endl;
		return ;
	}
	_contact[_incr].set_All(first_name, last_name, nickname, phone_number, darksecret);
	_incr++;
	if (_incr > 7)
		this->_incr = 0;
	std::cout << GRN "Contact saved" NC << std::endl  << std::endl;
	return ;
}

void PhoneBook::Exit() const
{
	std::cout << "Delete PhoneBook" << std::endl;
	std::cout << "Bye :)" << std::endl;
	exit(1);
}

void PhoneBook::Error_message(std::string error) const
{
	std::cout << std::endl;
	std::cout << RED << error << NC << std::endl  << std::endl  << std::endl;
}

