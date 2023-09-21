/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:38:52 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 02:41:27 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string type) {
    this->_type = type;
	std::cout << CYN << "Animal constructor  was created" << NC << std::endl;
}

Animal::Animal(void) {
	std::cout << CYN << "Animal constructor was created" << NC << std::endl;
}

Animal::Animal(const Animal &clap) {
	std::cout << CYN << "Copy constructor called" << NC << std::endl;
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
	std::cout << CYN << "Animal deconstructor called" << NC << std::endl;
}