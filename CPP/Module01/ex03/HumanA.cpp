/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:59:51 by mthea             #+#    #+#             */
/*   Updated: 2023/08/30 21:27:47 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon)
{
	std::cout << "Constructor A Called" << std::endl;
	this->_name = name;
	this->_weapon = &Weapon;
}

HumanA::~HumanA(void)
{
	std::cout << "Deconstructor A Called" << std::endl;
}

void	HumanA::attack(void) const
{
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
