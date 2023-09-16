/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:35:40 by haze              #+#    #+#             */
/*   Updated: 2023/08/29 11:47:46 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " died" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

int		Zombie::setZombieName(std::string name)
{
	this->_name = name;
	return (1);
}
