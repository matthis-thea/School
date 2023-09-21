/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:38:52 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 13:27:25 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	this->_type = "AAnimal";
	std::cout << "AAnimal constructor was created" << std::endl;
}

AAnimal::AAnimal(std::string name)
{
	this->_type = name;
	std::cout << "AAnimal constructor with parametres was created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &clap) {
	std::cout << "AAnimal Copy constructor called" << std::endl;
    *this = clap;
}

AAnimal& AAnimal::operator=(const AAnimal &clap)
{
	if (this != &clap)
	{
		this->_type= clap._type;
	}
	return (*this);
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal deconstructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
