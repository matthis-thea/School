/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:25:29 by mthea             #+#    #+#             */
/*   Updated: 2023/09/22 10:28:05 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    this->_type = "WrongAnimal";
	std::cout << "WrongAnimal constructor was created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
{
	this->_type = name;
	std::cout << "WrongAnimal constructor with parametres was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &clap) {
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = clap;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &clap)
{
	if (this != &clap)
	{
		this->_type= clap._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal cry" << std::endl;
}
