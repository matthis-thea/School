/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:38:52 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 11:51:33 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	this->_type = "Animal";
	std::cout << "Animal constructor was created" << std::endl;
}

Animal::Animal(std::string name)
{
	this->_type = name;
	std::cout << "Animal constructor with parametres was created" << std::endl;
}

Animal::Animal(const Animal &clap) {
	std::cout << "Animal Copy constructor called" << std::endl;
    *this = clap;
}

Animal& Animal::operator=(const Animal &clap)
{
	if (this != &clap)
	{
		this->_type= clap._type;
	}
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "Animal deconstructor called" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal cry" << std::endl;
}