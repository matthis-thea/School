/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:08:06 by mthea             #+#    #+#             */
/*   Updated: 2023/08/30 21:30:59 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << "Constructor B Called" << std::endl;
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB(void)
{
	std::cout << "Deonstructor B Called" << std::endl;
}

void	HumanB::attack(void) const
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " attacks without weapon !" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
