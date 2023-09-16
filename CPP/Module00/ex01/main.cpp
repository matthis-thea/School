/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:16:31 by haze              #+#    #+#             */
/*   Updated: 2023/08/29 10:56:07 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook repertoire;
	std::string prompt;
	while (1)
	{
		std::cin.clear();
		repertoire.Menu();
		std::cout << "Enter Text:";
		std::getline(std::cin, prompt);
		if ((prompt.compare("ADD")) == 0)
			repertoire.Add_Contact();
		else if ((prompt.compare("SEARCH")) == 0)
			repertoire.Search_Contact();
		else if ((prompt.compare("EXIT")) == 0)
			repertoire.Exit();
		else
			repertoire.Error_message("Enter just ADD or SEARCH or EXIT !");
	}
	return (0);
}
