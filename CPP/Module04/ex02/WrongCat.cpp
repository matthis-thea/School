/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:25:12 by mthea             #+#    #+#             */
/*   Updated: 2023/09/22 10:28:35 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

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

