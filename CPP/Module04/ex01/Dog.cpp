/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:14:37 by haze              #+#    #+#             */
/*   Updated: 2023/09/22 10:34:02 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog constructor was created" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch(const std::exception& e) {
		std::cerr << "Dynamic allocation failed"<< std::endl;
	}
}

Dog::Dog(const Dog &clap) : Animal() {
	std::cout << "Dog Copy constructor called" << std::endl;
    *this = clap;
}

Dog& Dog::operator=(const Dog &clap)
{
	if (this != &clap)
	{
		this->_type= clap._type;
		this->_brain = new Brain( *clap._brain );
	}
	return (*this);
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog deconstructor called" << std::endl;
}

std::string Dog::getType(void) const
{
	return (this->_type);
}

void Dog::makeSound() const
{
	std::cout << "Dog cry" << std::endl;
}
