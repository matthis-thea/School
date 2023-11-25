/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:32:03 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 14:58:56 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout <<CYN<< "Default Intern constructor called" <<NC<< std::endl;
	return;
}

Intern::~Intern(void)
{
	std::cout <<CYN<<"Intern destructor called" <<NC<< std::endl;
	return;
}

Intern::Intern(Intern const & src)
{
	std::cout <<CYN<< "Copy Intern constructor called" <<NC<< std::endl;
	*this = src;
	return;
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "Intern can not create a form called " << name << std::endl;
	return (NULL);
}

Intern& Intern::operator=( Intern const & hrs)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &hrs)
	{
		return *this;
	}
	return *this;
}
