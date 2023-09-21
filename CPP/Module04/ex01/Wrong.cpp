/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:58:41 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 12:08:46 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wrong.hpp"

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

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor was created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &clap) : WrongAnimal() {
	std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = clap;
}

WrongCat& WrongCat::operator=(const WrongCat &clap)
{
	if (this != &clap)
	{
		this->_type= clap._type;
	}
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat deconstructor called" << std::endl;
}

std::string WrongCat::getType(void) const
{
	return (this->_type);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat cry" << std::endl;
}

