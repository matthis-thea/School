/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:39:04 by mthea             #+#    #+#             */
/*   Updated: 2023/09/03 13:24:37 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string new_value)
{
	std::cout << "Constructor Called Weapon" << std::endl;
	this->_type = new_value;
}

Weapon::~Weapon(void)
{
	std::cout << "Destructor Called" << std::endl;
}

std::string Weapon::getType(void)
{
	return (this->_type);
}

int		Weapon::setType(std::string new_value)
{
	this->_type = new_value;
	return (1);
}
