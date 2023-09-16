/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.4/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:22:29 by haze              #+#    #+#             */
/*   Updated: 2023/09/02 12:27:06 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Constructor called" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Deconstructor called" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int i = 0;
	std::string tab[4];
	f_ptr f_ptr_tab[4];

	f_ptr_tab[0] = &Harl::debug;
	f_ptr_tab[1] = &Harl::info;
	f_ptr_tab[2] = &Harl::warning;
	f_ptr_tab[3] = &Harl::error;

	tab[0] = "DEBUG";
	tab[1] = "INFO";
	tab[2] = "WARNING";
	tab[3] = "ERROR";

	for (int i = 0; i < 4 ; i++)
	{
		if (tab[i].compare(level) == 0)
		{
			(this->*f_ptr_tab[i])();
			return ;
		}
	}
	std::cout << RED << "Wrong Value" << NC << std::endl;
}